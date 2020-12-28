#include <iostream>

#include "Constants.h"
#include "Exporter.h"
#include "Ray.h"

#include <glm/vec2.hpp>
#include <glm/geometric.hpp>

glm::vec3 RayColor(const Ray& ray)
{
	const glm::vec3& dir = glm::normalize(ray.direction);
	
	float t = 0.5f * (dir.y + 1.0f);
	
	const glm::vec3 color1(1.0f, 1.0f, 1.0f);
	const glm::vec3 color2(0.5f, 0.7f, 1.0f);
	return (1.0f - t) * color1 + t * color2;
}

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
	
	glm::vec3 pixels[Settings::WIDTH * Settings::HEIGHT];
	
	// Render here
	for(int y = Settings::HEIGHT - 1; y >= 0; --y)
	{
		for(int x = 0.0f; x < Settings::WIDTH; ++x)
		{
			glm::vec2 uv;
			uv.x = float(x) / float(Settings::WIDTH - 1);
			uv.y = float(y) / float(Settings::HEIGHT - 1);
			
			Ray r;
			r.origin = position;
			r.direction = lowerLeftCorner + uv.x * horizontal + uv.y * vertical - position;
			
			pixels[x + y * Settings::WIDTH] = RayColor(r);
		}
	}
	
	Exporter::ExportPPM("Al Pacino", pixels, Settings::WIDTH, Settings::HEIGHT);
	return 0;
}
