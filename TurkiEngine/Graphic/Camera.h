#pragma once
#include "../Math/Math.h"
#include "../Graphic/Shaders.h"
namespace Turki
{
	class Camera
	{
	public:
		Camera(Shaders& theShader, vec3& pos, float fov, float aspectRatio,float near,float far);
		~Camera();
		void setViewProj();
		void mouseControl(float xpos, float ypos);
		Shaders* theSha;
		vec3 m_eye;
		mat4 m_Pr;
		vec3 m_lookat;
		vec3 m_up;
		mat4 getViewProj();
		void setPosEye(vec3 eyePos);
		void setPosLook(vec3 lookAtPos);
		void setPosUp(vec3 upPos);
	private:
		bool firstMouse = true;
		float yaw = 0;
		float pitch = 0;
		float lastX = 400, lastY = 300;
		float xoffset, yoffset;
	};


}