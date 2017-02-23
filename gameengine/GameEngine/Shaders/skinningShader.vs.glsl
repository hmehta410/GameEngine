#version 400 core

// Uniforms
	uniform mat4 world_matrix;
	uniform mat4 view_matrix;
	uniform mat4 proj_matrix;
	uniform vec3 vLightPos;
	uniform vec4 vColor;
	uniform mat4 invBone[100];
	uniform worldBlock
	{
		uniform mat4 worldBone[100];
	};

// Attributes
	layout (location = 0) in vec4 vVert;
	layout (location = 1) in vec2 vTexCoord0;
	layout (location = 2) in vec3 vNormal;
	layout (location = 3) in vec4 vWeights;
	layout (location = 4) in ivec4 vIndex; 
	  
// Varying
	out VS_OUT
	{
		vec4 vFragColor;
	//	vec2 vTex;
	} vs_out;


void main(void) 
{ 
	//skinning
		//vertex
			vec4 adjustedVert = (vWeights.x * worldBone[vIndex.x] * invBone[vIndex.x] +
							     vWeights.y * worldBone[vIndex.y] * invBone[vIndex.y] +
							     vWeights.z * worldBone[vIndex.z] * invBone[vIndex.z] + 
							     vWeights.w * worldBone[vIndex.w] * invBone[vIndex.w] ) * vVert;

		//normals
			vec3 adjustedNorm =  (vWeights.x* mat3(worldBone[vIndex.x]) * mat3(invBone[vIndex.x]) +
							     vWeights.y * mat3(worldBone[vIndex.y]) * mat3(invBone[vIndex.y]) +
							     vWeights.z * mat3(worldBone[vIndex.z]) * mat3(invBone[vIndex.z]) + 
							     vWeights.w * mat3(worldBone[vIndex.w]) * mat3(invBone[vIndex.w]) ) * vNormal;

	// Get vNorm
		mat4 mvMatrix = view_matrix * world_matrix;
		mat3 mNormalMatrix;
		mNormalMatrix[0] = normalize(mvMatrix[0].xyz);
		mNormalMatrix[1] = normalize(mvMatrix[1].xyz);
		mNormalMatrix[2] = normalize(mvMatrix[2].xyz);
		vec3 vNorm = normalize(mNormalMatrix * adjustedNorm);

	// Get vLightDir
		vec4 ecPosition;
		vec3 ecPosition3;
		ecPosition = mvMatrix * adjustedVert;
		ecPosition3 = ecPosition.xyz /ecPosition.w;
		vec3 vLightDir = normalize(vLightPos - ecPosition3);

	// Get vFragColor
		float fDot = max(0.0, dot(vNorm, vLightDir)); 
		vs_out.vFragColor.rgb = vColor.rgb * fDot;
		vs_out.vFragColor.a = vColor.a;

	// Get vTex;
	//	vs_out.vTex = vTexCoord0;

	// Set Gl_position
		gl_Position = proj_matrix * mvMatrix * adjustedVert;
}