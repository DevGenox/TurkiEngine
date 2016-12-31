#pragma once
#include "Camera.h"
namespace Turki
{
	Camera::Camera(Shaders& theShader, vec3& pos, float fov, float aspectRatio, float near, float far)
	{
		theSha = &theShader;
		m_Pr = m_Pr.perspective(fov, aspectRatio, near, far);
		m_eye = pos;
		m_lookat = vec3(0, 0, -1.0f);
		m_up = vec3(0, 1.0f, 0);
	}

	Camera::~Camera()
	{

	}
	mat4 Camera::getViewProj()
	{
		return m_Pr.mylookat(m_eye, m_lookat, m_up);
	}
	void Camera::setPosEye(vec3 eyePos)
	{
		m_eye += eyePos;
		setViewProj();
	}
	void Camera::setPosLook(vec3 lookAtPos)
	{
		vec3 eyePos;
		eyePos = m_eye;
		m_lookat = eyePos + lookAtPos;
		setViewProj();
	}
	void Camera::setPosUp(vec3 upPos)
	{
		m_up += upPos;
		setViewProj();
	}
	void Camera::setViewProj()
	{
		theSha->UniformMatrix4("viewMat", getViewProj());
	}
	void Camera::mouseControl(float xpos, float ypos)
	{
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		xoffset = xpos - lastX;
		yoffset = lastY - ypos;

		float sensivity = 0.001f;

		xoffset *= sensivity;
		yoffset *= sensivity;

		yaw += xoffset;
		pitch += yoffset;	

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		vec3 lookat;
		lookat.x = cos(toRadians(pitch)) * cos(toRadians(yaw));
		lookat.y = sin(toRadians(pitch));
		lookat.z = cos(toRadians(pitch)) * sin(toRadians(yaw));
		m_lookat = lookat;
		setPosLook(m_lookat);
	}
}