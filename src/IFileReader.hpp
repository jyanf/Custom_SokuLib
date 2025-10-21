//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_IFILEREADER_HPP
#define SOKULIB_IFILEREADER_HPP


#include <windows.h>
#include "FrameData.hpp"
#include "Map.hpp"
#include "Deque.hpp"

namespace SokuLib
{
	struct IFileReader {
		HANDLE fp = nullptr;

		inline void close() {
			if (this->fp != nullptr) CloseHandle(this->fp);
			this->fp = nullptr;
		}

		inline bool isOpen() { return this->fp != nullptr; }

		virtual ~IFileReader();
		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) = 0;
		virtual DWORD GetReadLength() = 0;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) = 0;
		virtual DWORD GetLength() = 0;
	};

	struct FileReader : public IFileReader {
		DWORD lastRead;

		inline void open(const char* filename) {
			this->close();
			this->fp = CreateFileA(filename, FILE_READ_DATA, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
			if (this->fp == INVALID_HANDLE_VALUE) this->fp = nullptr;
		}

		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) override;
		virtual DWORD GetReadLength() override;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) override;
		virtual DWORD GetLength() override;
	};

	struct PackageReader : public IFileReader {
		DWORD lastRead;
		LONG size;
		LONG begin;
		LONG offset;
		char decryptKey;

		static HANDLE (__stdcall * const findFile)(LPCSTR name, LPLONG outSize, LPLONG outBegin);

		inline void open(const char* name) {
			this->close();
			fp = this->findFile(name, &size, &begin);
			offset = begin;
			decryptKey = (begin >> 1) | 0x23;
		}

		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) override;
		virtual DWORD GetReadLength() override;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) override;
		virtual DWORD GetLength() override;
	};

	extern void (*readPattern)(const char *characterName, unsigned paletteId, Map<int, v2::CharacterSequenceData*> *patternMap, Deque<v2::CharacterSequenceData> *patternData, Vector<int> *textureMap);
}


#endif //SOKULIB_IFILEREADER_HPP
