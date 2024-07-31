#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <glm.hpp>

glm::mat4 createTranslationMatrix(const glm::vec3& translation);
glm::mat4 createRotationMatrix(float angle);
glm::mat4 createScalingMatrix(float scale);

#endif // TRANSFORMATIONS_H
