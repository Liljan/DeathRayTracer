#pragma once

#include "DataTypes.h"

struct Ray;

class Exporter
{
public:
	static bool ExportPPM(const Ray rays[], const uint32 width, const uint32 height);
};
