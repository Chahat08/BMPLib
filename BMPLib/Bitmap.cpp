#include <fstream>
#include "Bitmap.h"
#include "DIBHeader.h"
#include "BMPFileHeader.h"

namespace BMP {
	bool Bitmap::write(std::string filepath) {
		BMP::BMPInfoHeader bmpInfoHeader;
		BMP::BMPFileHeader bmpFileHeader;

		// setting the deterministic fields in bmpFileHeader
		bmpFileHeader.fileSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + _width * _height * 3;
		bmpFileHeader.dataOffset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

		// setting the deterministic fields in bmpInfoHeader
		bmpInfoHeader.biWidth = _width;
		bmpInfoHeader.biHeight = _height;

		std::fstream file(filepath, std::ios::out|std::ios::binary);

		if (file.is_open()) {
			file.write((char*)&bmpFileHeader, sizeof(bmpFileHeader));
			file.write((char*)&bmpInfoHeader, sizeof(bmpInfoHeader));
			file.write((char*)_pPixelData.get(), _width * _height * 3);
		}
		else return false;

		file.close();

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green) {
		uint8_t* pPixel = _pPixelData.get();
		pPixel += 3 * (y * _width + x);

		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}
}