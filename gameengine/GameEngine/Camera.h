#ifndef CAMERA_H
#define CAMERA_H

#include "Math\MathEngine.h"
#include "List\Link.h"
/*
This class was largely borrowed from my professor with mainly cosmetic changes from me
*/

class Camera final : public DLink, public Align16
{
public:
	// Default constructor
	Camera( int id );
	~Camera();

   // Setup on single camera
	void SetPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
	void SetViewport(const int inX, const int inY, const int width, const int height);
	void SetOrientAndPosition(const Vect &Up_vect, const Vect &inLookAt_pt, const Vect &pos_pt);

   // update camera system
	void Update(void);

   // Get the matrices for rendering
	Matrix &GetViewMatrix();
	Matrix &GetProjMatrix();
	
	// accessors
	void GetPosition(Vect &outPos) const;
	Vect GetPosition() const;
	void GetDirection( Vect &outDir) const;
	void GetUp( Vect &outUp) const;
	void GetLookAt( Vect &outLookAt ) const;
	void GetRight( Vect &outRight ) const;

	int GetScreenWidth() const;
	int GetScreenHeight() const;
	int GetId() const;
			
	//Pos,Dir,Up,LookAt, Right have to be adjusted
	//together in SetOrientAndPosition()
			
	void GetFieldOfView( float &Value) const;
	void SetFieldOfView( const float Value);

	void GetNearDist( float &Value) const;
	void SetNearDist( const float Value);

	// helper functions

	void GetNormalsAndPoints(Vect &up, Vect &tar, Vect &pos, Vect &upNorm, Vect &forwardNorm, Vect &rightNorm);

	void GetNearTopLeft(Vect &vOut) const;
	void GetNearTopRight(Vect &vOut) const;
	void GetNearBottomLeft(Vect &vOut) const;
	void GetNearBottomRight(Vect &vOut) const;	
	void GetFarTopLeft(Vect &vOut) const;
	void GetFarTopRight(Vect &vOut) const;
	void GetFarBottomLeft(Vect &vOut) const;
	void GetFarBottomRight(Vect &vOut) const;

	Vect GetFrontNormal() const;
	Vect GetBackNormal() const;
	Vect GetLeftNormal() const;
	Vect GetRightNormal() const;
	Vect GetBottomNormal() const;
	Vect GetTopNormal() const;
	
	float GetNearHeight() const { return nearHeight; }

private:  // methods
	void privCalcPlaneHeightWidth( void );
	void privCalcFrustumVerts( void );
	void privCalcFrustumCollisionNormals( void );
	void privUpdateProjectionMatrix( void );
	void privUpdateViewMatrix( void );


private: //data

	// -------------------------------------------------------
	// 16-bit aligned data below this point:
	// -------------------------------------------------------

	// Projection Matrix
	Matrix	projMatrix;
	Matrix	viewMatrix;

	// camera unit vectors (up, dir, right)
	Vect	vUp;
	Vect	vDir;
	Vect	vRight;  // derived by up and dir
	Vect	vPos;   

	Vect	vLookAt;

	// world space coords for viewing frustum
	Vect	nearTopLeft;
	Vect	nearTopRight;
	Vect	nearBottomLeft;

	Vect	nearBottomRight;
	Vect	farTopLeft;
	Vect	farTopRight;
	Vect	farBottomLeft;

	Vect	farBottomRight;

	// Normals of the frustum
	Vect	frontNorm;
	Vect	backNorm;
	Vect	rightNorm;

	Vect	leftNorm;
	Vect	topNorm;
	Vect	bottomNorm;

	// -------------------------------------------------------
	// unaligned data below this point:
	// -------------------------------------------------------

	// Define the frustum inputs
	float	nearDist;
	float	farDist;
	float	fovy;
	float	aspectRatio;

	// Screen size in world space
	float	nearHeight;
	float	nearWidth;
	float	farHeight;
	float	farWidth;

	// viewports
	int		viewX;
	int		viewY;
	int		viewWidth;
	int		viewHeight;

	int		id;
	int		padding;
	int		padding1;
	int		padding2;
};

#endif