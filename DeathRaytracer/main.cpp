#include <iostream>

#include "Constants.h"
#include "Exporter.h"
#include "Ray.h"

#include "Sphere.h"
#include "Scene.h"

#include <glm/geometric.hpp>

// This is our scene, temporarily
glm::vec3 RayColor(const Ray& ray)
{
	Sphere sphere(Vec3(0.0f, 0.0f, 3.0f), 1.0f);
	
	IntersectionData hitData;
	if(sphere.Intersection(ray, hitData))
		return Vec3(0.9f, 0.0f, 0.0f);
	
	const glm::vec3& dir = glm::normalize(ray.direction);
	
	float t = 0.5f * (dir.y + 1.0f);
	
	const glm::vec3 color1(1.0f, 1.0f, 1.0f);
	const glm::vec3 color2(0.5f, 0.7f, 1.0f);
	return (1.0f - t) * color1 + t * color2;
}

int main(int argc, const char* argv[])
{
	Scene myScene(Vec3(0.3f, 0.3f, 0.6f));
	
	myScene.Add(std::make_shared<Sphere>(Vec3(0, 0, -3), 1.0f));
	myScene.Add(std::make_shared<Sphere>(Vec3(0, 1, -3), 1.0f));
	myScene.Add(std::make_shared<Sphere>(Vec3(0, -1, -3), 0.5f));
	myScene.Add(std::make_shared<Sphere>(Vec3(1, 0, -3), 2.0f));
	
	// Set-up camera
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
			const float u = float(x) / float(Settings::WIDTH - 1);
			const float v = float(y) / float(Settings::HEIGHT - 1);
			
			Ray r;
			r.origin = position;
			r.direction = lowerLeftCorner + u * horizontal + v * vertical - position;
			
			pixels[x + y * Settings::WIDTH] = RayColor(r);
		}
	}
	
	Exporter::ExportPPM("Al Pacino", pixels, Settings::WIDTH, Settings::HEIGHT);
	return 0;
}
