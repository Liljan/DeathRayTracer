#pragma once

#include "Shape.h"

class Sphere : public Shape
{
public:
	
	Sphere(const Vec3& position, float radius);
	
	virtual bool Intersection(const Ray& ray, OUT IntersectionData& hitData) const override;
	
	float m_Radius = 1.0f;
};
