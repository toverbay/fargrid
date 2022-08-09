#include "fgpch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Fargrid {

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float znear /* -1.0f */, float zfar /* 1.0f */)
		: m_ProjectionMatrix(glm::orthoRH_NO(left, right, bottom, top, znear, zfar)), m_Position(0)
	{
		RecalculateViewMatrix();
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
							  glm::rotate(glm::mat4(1.0f), glm::radians(m_RotationZDeg), glm::vec3(0, 0, 1));

		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

}
