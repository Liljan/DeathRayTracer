#include "Sphere.h"

#include "Ray.h"

#include <glm/geometric.hpp>

Sphere::Sphere(const Vec3& position, float radius) : m_Radius(radius)
{
	m_Position = position;
}


bool Sphere::Intersection(const Ray &ray, IntersectionData &hitData) const
{
	const Vec3 CA =  ray.origin - m_Position;
	
	const float a = glm::dot(ray.direction, ray.direction);
	const float h = glm::dot(CA, ray.direction);
	const float c = glm::dot(CA, CA) - m_Radius * m_Radius;
	
	const float discriminant = h * h - a * c;
	
	if(discriminant < 0.0f)
		return false;
	
	const float sqrtDiscriminant = sqrtf(discriminant);
	
	const float closeIntersection = (-h - sqrtDiscriminant) / a;
	const float farIntersection = (-h + sqrtDiscriminant) / a;
	
	if(closeIntersection < hitData.closestDist)
		hitData.closestDist = closeIntersection;
	
	return true;
}
