#pragma once
/*!*****************************************************************************
\file     Transform.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

struct Transform
{
	Transform() = default;
	Transform(const Transform&) = default;
	Transform(const glm::vec3& pos) : position() { position[0] = pos; }

	glm::vec3 position[3] = { {0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f} };
	glm::vec3 rotation[3] = { {0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f} };
	glm::vec3 scale[3] = { {0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f} };

	glm::mat4 GetTransformMatrix(int i) const
	{
		glm::mat4 r = glm::toMat4(glm::quat(rotation[i]));
		return glm::translate(glm::mat4(1.0f), position[i]) * r * glm::scale(glm::mat4(1.0f), scale[i]);
	}
};
