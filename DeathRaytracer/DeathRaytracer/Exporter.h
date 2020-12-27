#pragma once

#include "DataTypes.h"

#include <string>

struct Ray;

class Exporter
{
public:
	
	static inline int FloatTo255(float value);
	
	static bool ExportPPM(const std::string& fileName, const Ray rays[], const uint32 width, const uint32 height);
};
