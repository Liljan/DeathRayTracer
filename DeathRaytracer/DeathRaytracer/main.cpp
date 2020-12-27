#include <iostream>

#include "Constants.h"
#include "Exporter.h"
#include "Ray.h"

int main(int argc, const char* argv[])
{
	Ray rays[Settings::IMAGE_SIZE_X * Settings::IMAGE_SIZE_Y];
	Exporter::ExportPPM("Al Pacino", rays, Settings::IMAGE_SIZE_X, Settings::IMAGE_SIZE_Y);
	return 0;
}
