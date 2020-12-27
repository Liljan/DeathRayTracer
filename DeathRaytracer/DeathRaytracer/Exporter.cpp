#include "Exporter.h"
#include "Ray.h"

#include <fstream>


inline int Exporter::FloatTo255(float value)
{
	return static_cast<int>(roundf(255.0f * value));
}

bool Exporter::ExportPPM(const std::string& fileName, const Ray rays[], const uint32 width, const uint32 height)
{
	// Todo: Add error messages
	
	if(fileName.empty())
		return false;
	
	if(width == 0)
		return false;
	
	if(height == 0)
		return false;
	
	std::string fullFileName = fileName + ".ppm";
	std::ofstream file;
	file.open(fullFileName.c_str());
	
	if(!file.is_open())
		return false;
	
	file << "P3\n" << width << ' ' << height << "\n255\n";

	for(int j = height - 1; j >= 0; --j)
	{
		for(int i = 0; i < width; ++i)
		{
			// Temporary format testing.
			auto r = float(i) / (width - 1);
			auto g = float(j) / (height - 1);
			auto b = 0.25;
			
			int ir = FloatTo255(r);
			int ig = FloatTo255(g);
			int ib = FloatTo255(b);

			file << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	
	file.close();
	return true;
}
