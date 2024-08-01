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
	Transform(const glm::vec3& pos)	: position(pos) {}

	glm::vec3 position = { 0.0f, 0.0f, 0.0f };
	glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
	glm::vec3 scale = { 1.0f, 1.0f, 1.0f };

	glm::mat4 GetTransformMatrix() const
	{
		glm::mat4 rotation = glm::toMat4(glm::quat(rotation));
		return glm::translate(glm::mat4(1.0f), position) * rotation * glm::scale(glm::mat4(1.0f), scale);
	}
};
