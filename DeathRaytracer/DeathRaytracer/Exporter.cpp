#include "Exporter.h"
#include "Ray.h"

#include <fstream>

bool Exporter::ExportPPM(const Ray rays[], const uint32 width, const uint32 height)
{
	if(width == 0)
		return false;
	
	if(height == 0)
		return false;
	
	std::ofstream file;
	file.open ("example.ppm");
	
	file << "P3\n" << width << ' ' << height << "\n255\n";

	for(int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			auto r = float(i) / (width - 1);
			auto g = float(j) / (height - 1);
			auto b = 0.25;

			int ir = static_cast<int>(255.999f * r);
			int ig = static_cast<int>(255.999f * g);
			int ib = static_cast<int>(255.999f * b);

			file << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	
	file.close();
	return true;
}
