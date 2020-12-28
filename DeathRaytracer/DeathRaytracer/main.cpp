#include <iostream>

#include "Constants.h"
#include "Exporter.h"
#include "Ray.h"

#include <glm/vec2.hpp>

int main(int argc, const char* argv[])
{
	const float aspectRatio = (float)Settings::WIDTH / (float)Settings::HEIGHT;
	const float focalLength = 1.0f;
	
	// Camera (view port)
	const float viewportHeight = 2.0f;
	const float viewportWidth = aspectRatio * viewportHeight;
	
	const glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	const glm::vec3 horizontal = glm::vec3(viewportWidth, 0.0f, 0.0f);
	const glm::vec3 vertical = glm::vec3(0.0f, viewportHeight, 0.0f);
	const glm::vec3 lowerLeftCorner = position - 0.5f * horizontal - 0.5f * vertical - 0.5f * glm::vec3(0.0f, 0.0f, focalLength);
	
	// Render here
	
	Ray rays[Settings::WIDTH * Settings::HEIGHT];
	Exporter::ExportPPM("Al Pacino", rays, Settings::WIDTH, Settings::HEIGHT);
	return 0;
}
