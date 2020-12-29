
#include "Scene.h"

Scene::Scene(const Vec3& backgroundColor)
{
	m_BackgroundColor = backgroundColor;
}


void Scene::Clear()
{
	m_Objects.clear();
}

void Scene::Add(std::shared_ptr<Shape> object)
{
	m_Objects.push_back(object);
}
