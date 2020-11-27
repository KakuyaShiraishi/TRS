#pragma once

#include "ofMain.h"


class TRS{
public:


	float ConvertDegToRad(float degrees) {
		return ((float)PI / (float)180) * degrees;
	}

	glm::mat4x4 GetTranslationMatrix(glm::vec3 position) {
		return glm::mat4x4(glm::vec4(1, 0, 0, 0),
						   glm::vec4(0, 1, 0, 0),
						   glm::vec4(0, 0, 1, 0),
						   glm::vec4(position.x, position.y, position.z, 1));
	}

	glm::mat4x4 GetRotationMatrix(glm::vec3 anglesDeg) {
		anglesDeg = glm::vec3(ConvertDegToRad(anglesDeg[0]), ConvertDegToRad(anglesDeg[1]), ConvertDegToRad(anglesDeg[2]));

		glm::mat4x4 rotationX = glm::mat4x4(glm::vec4(1, 0, 0, 0),
											glm::vec4(0, cos(anglesDeg[0]), sin(anglesDeg[0]), 0),
											glm::vec4(0, -sin(anglesDeg[0]), cos(anglesDeg[0]), 0),
											glm::vec4(0, 0, 0, 1));

		glm::mat4x4 rotationY = glm::mat4x4(glm::vec4(cos(anglesDeg[1]), 0, -sin(anglesDeg[1]), 0),
											glm::vec4(0, 1, 0, 0),
											glm::vec4(sin(anglesDeg[1]), 0, cos(anglesDeg[1]), 0),
											glm::vec4(0, 0, 0, 1));

		glm::mat4x4 rotationZ = glm::mat4x4(glm::vec4(cos(anglesDeg[2]), sin(anglesDeg[2]), 0, 0),
											glm::vec4(-sin(anglesDeg[2]), cos(anglesDeg[2]), 0, 0),
											glm::vec4(0, 0, 1, 0),
											glm::vec4(0, 0, 0, 1));

		return rotationX * rotationY * rotationZ;
	}

	glm::mat4x4 GetScaleMatrix(glm::vec3 scale) {
		return glm::mat4x4(glm::vec4(scale.x, 0, 0, 0),
						   glm::vec4(0, scale.y, 0, 0),
						   glm::vec4(0, 0, scale.z, 0),
						   glm::vec4(0, 0, 0, 1));
	}

	glm::mat4x4 Get_TRS_Matrix(glm::vec3 position, glm::vec3 rotationAngles, glm::vec3 scale) {
		return GetTranslationMatrix(position) * GetRotationMatrix(rotationAngles) * GetScaleMatrix(scale);
	}



};


