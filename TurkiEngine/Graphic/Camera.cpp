#pragma once
#include "Camera.h"
namespace Turki
{
	Camera::Camera(Shaders& theShader, vec3& pos, float fov, float aspectRatio, float near, float far)
	{
		theSha = &theShader;
		m_Pr = m_Pr.perspective(fov, aspectRatio, near, far);
		m_eye = pos;
		m_lookat = vec3(0, 0, -1.5f);
		m_up = vec3(0, 1, 0);
	}

	Camera::~Camera()
	{

	}
	mat4 Camera::getViewProj()
	{
		return m_Pr.mylookat(m_eye, m_lookat, m_up, vec3(0, 0, 0));
	}
	void Camera::setPosEye(vec3 eyePos)
	{
		m_eye = eyePos;
		setViewProj();
	}
	void Camera::setPosLook(vec3 lookAtPos)
	{
		m_lookat = lookAtPos;
		setViewProj();
	}
	void Camera::setPosUp(vec3 upPos)
	{
		m_up = upPos;
		setViewProj();
	}
	void Camera::setViewProj()
	{
		theSha->UniformMatrix4("viewMat", getViewProj());
	}
}