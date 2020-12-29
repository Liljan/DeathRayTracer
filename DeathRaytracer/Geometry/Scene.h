#pragma once

#include "Shape.h"

#include <memory>
#include <vector>

class Scene
{
public:
	
	Scene(const Vec3& backgroundColor);

	void Clear();
	void Add(std::shared_ptr<Shape> object);
	
	std::vector<std::shared_ptr<Shape>> m_Objects;
	
	Vec3 m_BackgroundColor;
};
