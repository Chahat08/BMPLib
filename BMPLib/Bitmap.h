#pragma once

#include <string>
#include <memory>

namespace BMP {
	class Bitmap
	{
	private:
		int _width{ 0 };
		int _height{ 0 };
		std::unique_ptr<uint8_t[]> _pPixelData{ nullptr };
	public:
		// constructors
		Bitmap() {};
		Bitmap(int width, int height) : _width(width), _height(height), _pPixelData(new uint8_t[width * height * 3]{}) {};

		// destructor
		~Bitmap() {};

		// utils
		bool write(std::string filepath);
		void setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green);

	};
}

