#include "Assert.h"
#include "GL\glew.h"

#include <math.h>
#include "Camera.h"


// default constructor
Camera::Camera(int id) : id(id), padding(0), padding1(0), padding2(0)
{
}
	
 Camera::~Camera()
 {
 }

 int Camera::GetId() const
 {
	 return this->id;
 }

// critical informational knobs for the perspective matrix
// Field of View Y is in degrees
void Camera::SetPerspective(const float fieldOfViewY, const float aspect, const float nearDistance, const float farDistance)
{
	this->fovy = fieldOfViewY;
	this->aspectRatio = aspect;
	this->nearDist = nearDistance;
	this->farDist = farDistance;
}

int Camera::GetScreenWidth() const
{
	return this->viewWidth;
}

int Camera::GetScreenHeight() const
{
	return this->viewHeight;
}

// Just a pass through to setup the view port screen sub window
void Camera::SetViewport(const int inX, const int inY, const int width, const int height)
{
	this->viewX = inX;
	this->viewY = inY;
	this->viewWidth = width;
	this->viewHeight = height;

	glViewport(this->viewX, this->viewY, this->viewWidth, this->viewHeight);
};

// Goal, calculate the near height / width, same for far plane 
void Camera::privCalcPlaneHeightWidth( void )
{
	this->nearHeight = 2.0f * tanf(( this->fovy * util::kPi/180.0f ) * .5f) * this->nearDist;
	this->nearWidth = this->nearHeight * this->aspectRatio;

	this->farHeight = 2.0f * tanf(( this->fovy * util::kPi/180.0f) * .5f) * this->farDist;
	this->farWidth = this->farHeight * this->aspectRatio;
};

void Camera::SetOrientAndPosition(const Vect &inUp, const Vect &inLookAt, const Vect &inPos)
{
	// Remember the up, lookAt and right are unit, and are perpendicular.
	// Treat lookAt as king, find Right vect, then correct Up to insure perpendicular.
	// Make sure that all vectors are unit vectors.

	assert(inLookAt.IsPoint());
	assert(inPos.IsPoint());
	this->vLookAt = inLookAt;

	// Point out of the screen into your EYE
	this->vDir = inPos - inLookAt;
	this->vDir.Normalize();

	// Clean up the vectors (Right hand rule)
	this->vRight = inUp.Cross( this->vDir );
	this->vRight.Normalize();

	this->vUp = this->vDir.Cross( this->vRight );
	this->vUp.Normalize();

	this->vPos = inPos;
};


void Camera::privCalcFrustumVerts( void )
{
	// Top Left corner and so forth.  In this form to see the pattern
	// Might be confusing (remember the picture) vDir goes from screen into your EYE
	// so distance from the eye is "negative" vDir
	this->nearTopLeft		= this->vPos - this->vDir * this->nearDist + this->vUp * this->nearHeight * 0.5f - this->vRight * this->nearWidth * 0.5f;
	this->nearTopRight		= this->vPos - this->vDir * this->nearDist + this->vUp * this->nearHeight * 0.5f + this->vRight * this->nearWidth * 0.5f;
	this->nearBottomLeft	= this->vPos - this->vDir * this->nearDist - this->vUp * this->nearHeight * 0.5f - this->vRight * this->nearWidth * 0.5f;
	this->nearBottomRight	= this->vPos - this->vDir * this->nearDist - this->vUp * this->nearHeight * 0.5f + this->vRight * this->nearWidth * 0.5f;
	this->farTopLeft		= this->vPos - this->vDir * this->farDist  + this->vUp * this->farHeight * 0.5f  - this->vRight * this->farWidth * 0.5f;
	this->farTopRight		= this->vPos - this->vDir * this->farDist  + this->vUp * this->farHeight * 0.5f  + this->vRight * this->farWidth * 0.5f;
	this->farBottomLeft		= this->vPos - this->vDir * this->farDist  - this->vUp * this->farHeight * 0.5f  - this->vRight * this->farWidth * 0.5f;
	this->farBottomRight   	= this->vPos - this->vDir * this->farDist  - this->vUp * this->farHeight * 0.5f  + this->vRight * this->farWidth * 0.5f;
};
	
void Camera::privCalcFrustumCollisionNormals( void )
{
	// Normals of the frustum around nearTopLeft
	Vect A = this->nearBottomLeft - this->nearTopLeft;
	Vect B = this->nearTopRight - this->nearTopLeft;
	Vect C = this->farTopLeft - this->nearTopLeft;
	
	this->frontNorm = A.Cross(B);
	this->frontNorm.Normalize();

	this->leftNorm = C.Cross(A);
	this->leftNorm.Normalize();
	
	this->topNorm = B.Cross(C);
	this->topNorm.Normalize();

	// Normals of the frustum around farBottomRight
	A = this->farBottomLeft - this->farBottomRight;
	B = this->farTopRight - this->farBottomRight;
	C = this->nearBottomRight - this->farBottomRight;
	
	this->backNorm = A.Cross(B);
	this->backNorm.Normalize();
	
	this->rightNorm = B.Cross(C);
	this->rightNorm.Normalize();

	this->bottomNorm = C.Cross(A);
	this->bottomNorm.Normalize();
};


// The projection matrix (note it's invertable)
void Camera::privUpdateProjectionMatrix( void )
{
	this->projMatrix[m0] = 2.0f * this->nearDist / this->nearWidth;
	this->projMatrix[m1] = 0.0f;
	this->projMatrix[m2] = 0.0f;
	this->projMatrix[m3] = 0.0f;
	
	this->projMatrix[m4] = 0.0f;
	this->projMatrix[m5] = 2.0f * this->nearDist / this->nearHeight;
	this->projMatrix[m6] = 0.0f;
	this->projMatrix[m7] = 0.0f;

	this->projMatrix[m8] = 0.0f;
	this->projMatrix[m9] = 0.0f;
	this->projMatrix[m10] = (this->farDist + this->nearDist)/(this->nearDist - this->farDist);
	this->projMatrix[m11] = -1.0f;

	this->projMatrix[m12] = 0.0f;
	this->projMatrix[m13] = 0.0f;
	this->projMatrix[m14] = (2.0f * this->farDist * this->nearDist)/(this->nearDist - this->farDist);
	this->projMatrix[m15] = 0.0f;
};


void Camera::privUpdateViewMatrix( void )
{
	// This functions assumes the your vUp, vRight, vDir are still unit
	// And perpendicular to each other
	//  view = Rot(orient) * trans(-(eye.basis) )

	this->viewMatrix[m0] = this->vRight[x];
	this->viewMatrix[m1] = this->vUp[x];
	this->viewMatrix[m2] = this->vDir[x];
	this->viewMatrix[m3] = 0.0f;

	this->viewMatrix[m4] = this->vRight[y];
	this->viewMatrix[m5] = this->vUp[y];
	this->viewMatrix[m6] = this->vDir[y];
	this->viewMatrix[m7] = 0.0f;

	this->viewMatrix[m8]  = this->vRight[z];
	this->viewMatrix[m9]  = this->vUp[z];
	this->viewMatrix[m10] = this->vDir[z];
	this->viewMatrix[m11] = 0.0f;

	// Change of basis (dot with the basis vectors)
	this->viewMatrix[m12] = -vPos.Dot(vRight);
	this->viewMatrix[m13] = -vPos.Dot(vUp);
	this->viewMatrix[m14] = -vPos.Dot(vDir);
	this->viewMatrix[m15] = 1.0f;
};

// Update everything (make sure it's consistent)
void Camera::Update(void)
{
	// First find the near height/width, far height/width
	this->privCalcPlaneHeightWidth( );

	// Find the frustum physical verts
	this->privCalcFrustumVerts( );

	// find the frustum collision normals
	this->privCalcFrustumCollisionNormals( );

	// update the projection matrix
	this->privUpdateProjectionMatrix( );

	// update the view matrix
	this->privUpdateViewMatrix( );
}


// Accessor mess:
Matrix & Camera::GetViewMatrix( void )
{
	return this->viewMatrix;
}

Matrix & Camera::GetProjMatrix( void)
{
	return this->projMatrix;
}

Vect Camera::GetPosition() const
{
	return this->vPos;
}

void Camera::GetPosition( Vect &outPos) const
{
	outPos = this->vPos;
}

void  Camera::GetDirection(Vect &outDir) const
{
	outDir = this->vDir;
}

void  Camera::GetUp(Vect &outUp) const
{
	outUp = this->vUp;
}

void Camera::GetLookAt(Vect &outLookAt) const
{
	outLookAt = this->vLookAt;
}

void Camera::GetRight(Vect &outRight) const
{
	outRight = this->vRight;
}

void Camera::GetFieldOfView( float &Value) const
{
	Value = this->aspectRatio;
};

void Camera::SetFieldOfView( const float Value)
{
	this->aspectRatio = Value;
};

void Camera::GetNearDist( float &Value) const
{
	Value = this->nearDist;
}

void Camera::SetNearDist( const float Value)
{
	this->nearDist = Value;
}

void Camera::GetNearTopLeft(Vect &vOut) const 
{
	vOut = this->nearTopLeft;
}
void Camera::GetNearTopRight(Vect &vOut) const
{
	vOut = this->nearTopRight;
}
void Camera::GetNearBottomLeft(Vect &vOut)const
{
	vOut = this->nearBottomLeft;
}
void Camera::GetNearBottomRight(Vect &vOut) const
{
	vOut = this->nearBottomRight;
}
void Camera::GetFarTopLeft(Vect &vOut) const
{
		vOut = this->farTopLeft;
}
void Camera::GetFarTopRight(Vect &vOut) const
{
		vOut = this->farTopRight;
}
void Camera::GetFarBottomLeft(Vect &vOut) const
{
		vOut = this->farBottomLeft;
}
void Camera::GetFarBottomRight(Vect &vOut)const
{
		vOut = this->farBottomRight;
}

Vect Camera::GetFrontNormal() const
{
	return frontNorm;
}
Vect Camera::GetBackNormal() const
{
	return backNorm;
}
Vect Camera::GetLeftNormal() const
{
	return leftNorm;
}
Vect Camera::GetRightNormal() const
{
	return rightNorm;
}
Vect Camera::GetBottomNormal() const
{
	return bottomNorm;
}
Vect Camera::GetTopNormal() const
{
	return topNorm;
}

void Camera::GetNormalsAndPoints(Vect &upOut, Vect &tarOut, Vect &posOut, Vect &upNormOut, Vect &forwardNormOut, Vect &rightNormOut)
{
	this->GetPosition(posOut);
	this->GetLookAt(tarOut);

	this->GetUp(upNormOut);
	upOut = posOut + upNormOut;

	forwardNormOut = tarOut - posOut;
	forwardNormOut.Normalize();


	this->GetRight(rightNormOut);
}