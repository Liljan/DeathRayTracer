#pragma once

#include "DataTypes.h"

#include <string>

#include <glm/vec3.hpp>

class Exporter
{
public:
	
	static inline int FloatTo255(float value);
	
	static bool ExportPPM(const std::string& fileName, const glm::vec3 pixels[], const uint32 width, const uint32 height);
};
