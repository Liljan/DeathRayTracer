#pragma once

#include "DataTypes.h"

struct Ray;

struct IntersectionData
{
	float closestDist = INFINITY;
};

class Shape
{
public:
	
	virtual bool Intersection(const Ray& ray, OUT IntersectionData& hitData) const = 0;
	
protected:
	Vec3 m_Position;
};
