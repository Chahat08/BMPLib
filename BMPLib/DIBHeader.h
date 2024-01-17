#pragma once
// DIB header of type BITMAPINFOHEADER

#pragma pack(2)

namespace BMP{
	class BMPInfoHeader {
		/*
		* Offset:  0, size: 4 -> biSize			 (Size of the DIB header, 40 bytes)
		* Offset:  4, size: 4 -> biWidth		 (Width of image in pixels)
		* Offset:  8, size: 4 -> biHeight		 (Height of image in pixels)
		* Offset: 12, size: 2 -> biPlanes		 (No of color planes, must be 1)
		* Offset: 14, size: 2 -> biBitCount		 (Number of bits per pixel (1, 4, 8, 16, 24, or 32))
		* Offset: 16, size: 4 -> biCompression   (Compression, 0 for uncompressed)
		* Offset: 20, size: 4 -> biSizeImage     (Size of the raw bitmap data (including padding))
		* Offset: 24, size: 4 -> biXPelsPerMeter (Pixels per meter in X direction (horizontal resolution))
		* Offset: 28, size: 4 -> biYPelsPerMeter (Pixels per meter in Y direction (vertical resolution))
		* Offset: 32, size: 4 -> biClrUsed		 (Number of colors in the color palette, 0 for full color)
		* Offset: 36, size: 4 -> biClrImportant  (Number of important colors, 0 meaning all are imp)
		*/
	public:
		__int32 biSize{ 40 };
		__int32 biWidth;
		__int32 biHeight;
		__int16 biPlanes{ 1 };
		__int16 biBitCount{ 24 }; // 8 bytes per each of r,g,b
		__int32 biCompression{ 0 };
		__int32 biSizeImage{ 0 };
		__int32 biXPelsPerMeter{ 2400 };
		__int32 biYPelsPerMeter{ 2400 };
		__int32 biClrUsed{ 0 };
		__int32 biClrImportant{ 0 };
	};
}