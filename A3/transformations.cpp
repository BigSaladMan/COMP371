#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "transformations.h"

glm::mat4 createTranslationMatrix(const glm::vec3& translation) {
    return glm::translate(glm::mat4(1.0f), translation);
}

glm::mat4 createRotationMatrix(float angle) {
    return glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

glm::mat4 createScalingMatrix(float scale) {
    return glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, scale));
}

