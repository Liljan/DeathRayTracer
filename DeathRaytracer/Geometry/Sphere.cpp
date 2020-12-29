#include "Sphere.h"

Sphere::Sphere(const Vec3& position, float radius) : m_Radius(radius)
{
	m_Position = position;
}


bool Sphere::Intersection(const Ray &ray, IntersectionData &hitData) const
{
	return false;
}
