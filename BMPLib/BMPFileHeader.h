#pragma once
#pragma pack(2)

namespace BMP {
	class BMPFileHeader {
		/*
		* Offset dec:  0, size: 2 bytes -> header     (Idenfication for a BMP file, BM ascii in windows)
		* Offset dec:  2, size: 4 bytes -> fileSize   (SiZe of the BMP file in bytes)
		* Offset dec:  6, size: 2 bytes -> reserved   (reserved, depends upon application)
		* Offset dec:  8, size: 2 bytes -> reserved   (reserved, depends upon application)
		* Offset dec: 10, size: 4 bytes -> dataOffset (starting address (offset) of the byte where pixel array can be found)
		*/
	public:
		char header[2]{ 'B', 'M' }; // char is 1 byte
		__int32 fileSize; // __int32 is 4 bytes
		__int32 reserved{ 0 };
		__int32 dataOffset;
	};
}