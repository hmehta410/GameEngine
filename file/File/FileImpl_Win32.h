//no header gaurd as this is only supposed to be included once in the File.cpp
#ifdef _WIN32

#include "File.h"
#include <assert.h>

DWORD getSeekPattern(FileSeek seek);
DWORD getAccessPattern(FileMode mode);

File::File(const char* const fileName, FileMode mode)
	:fileMode(mode), fileSize(-1), fileError(0)
{
	if (fileName == nullptr)
	{
		this->setError(FileError::OPEN_FAILED);
		assert(fileName != nullptr);
	}

	DWORD accessPattern = getAccessPattern(mode);

	if (accessPattern & GENERIC_WRITE)
	{
		fileHandle = CreateFile(fileName, accessPattern, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	}
	else
	{
		fileHandle = CreateFile(fileName, accessPattern, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, nullptr);
	}

	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		this->setError(FileError::OPEN_FAILED);
	}
}

File::File(FileMode mode)
	:fileMode(mode), fileHandle(0), fileError(0), fileSize(-1)
{
}

File::File(File&& file)
	: fileHandle(file.fileHandle), fileMode(file.fileMode), 
	fileError(file.fileError), fileSize(file.fileSize)
{
	file.fileHandle = 0;
	file.setError(FileError::UNDEFINED_STATE_AFTER_MOVE);
}

File& File::operator=(File&& file)
{
	this->fileHandle = file.fileHandle;
	this->fileMode = file.fileMode;
	this->fileError = file.fileError;
	this->fileSize = file.fileSize;
	file.fileHandle = 0;
	file.setError(FileError::UNDEFINED_STATE_AFTER_MOVE);
	return *this;
}

File::~File()
{
	this->Close();
}

void File::Close()
{
	if (0 != fileHandle)
	{
		if (CloseHandle(fileHandle))
		{
			fileHandle = 0;
			return;
		}
		this->setError(FileError::CLOSE_FAILED);
	}
}

void File::Open(const char* const fileName)
{
	if (fileName == nullptr || fileHandle != 0)
	{
		this->setError(FileError::OPEN_FAILED);
		return;
	}

	DWORD accessPattern = getAccessPattern(fileMode);

	if (accessPattern & GENERIC_WRITE)
	{
		fileHandle = CreateFile(fileName, accessPattern, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	}
	else
	{
		fileHandle = CreateFile(fileName, accessPattern, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, nullptr);
	}

	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		this->setError(FileError::OPEN_FAILED);
	}
}

void File::Write(const void* const buffer, size_t size)
{
	DWORD outSize;
	if (!(WriteFile(fileHandle, buffer, size, &outSize, nullptr) && outSize == size))
	{
		this->setError(FileError::WRITE_FAILED);
	}
}

int File::Read(void* const buffer, size_t size)
{
	DWORD outSize = 0;
	if (buffer == 0 || size < 0 || !ReadFile(fileHandle, buffer, size, &outSize, nullptr))
	{
		this->setError(FileError::READ_FAILED);
	}
	if (outSize != size)
	{
		this->setError(FileError::READ_RETURNED_EARLY);
	}
	return outSize;
}

void File::Seek(FileSeek seek, int offset)
{
	if (SetFilePointer(fileHandle, offset, nullptr, getSeekPattern(seek)) == INVALID_SET_FILE_POINTER)
	{
		this->setError(FileError::SEEK_FAILED);
	}
}

int File::Tell()
{
	return SetFilePointer(fileHandle, 0, nullptr, FILE_CURRENT);
}

void File::Flush()
{
	if (!FlushFileBuffers(fileHandle))
	{
		this->setError(FileError::FLUSH_FAILED);
	}
}

int File::GetSize()
{
	if (-1 == this->fileSize)
	{
		//get the current position
		int current = this->Tell();

		//seek to the end of the file
		this->Seek(FileSeek::END, 0);

		//store the size of the file into this->fileSize
		fileSize = this->Tell();

		//return the position back to where it started
		this->Seek(FileSeek::BEGIN, current);
	}

	return fileSize;
}

FileError File::GetError()
{
	if (fileError == (int)FileError::NONE)
	{
		fileError = 0;
		return FileError::NONE;
	}
	if (fileError & (int)FileError::UNDEFINED_STATE_AFTER_MOVE)
	{
		return FileError::UNDEFINED_STATE_AFTER_MOVE;
	}
	if (fileError & (int)FileError::OPEN_FAILED)
	{
		fileError = 0;
		return FileError::OPEN_FAILED;
	}
	if (fileError & (int)FileError::CLOSE_FAILED)
	{
		fileError = 0;
		return FileError::CLOSE_FAILED;
	}
	if (fileError & (int)FileError::WRITE_FAILED)
	{
		fileError = 0;
		return FileError::WRITE_FAILED;
	}
	if (fileError & (int)FileError::READ_FAILED)
	{
		fileError = 0;
		return FileError::READ_FAILED;
	}
	if (fileError & (int)FileError::READ_RETURNED_EARLY)
	{
		fileError = 0;
		return FileError::READ_RETURNED_EARLY;
	}
	if (fileError & (int)FileError::SEEK_FAILED)
	{
		fileError = 0;
		return FileError::SEEK_FAILED;
	}
	if (fileError & (int)FileError::FLUSH_FAILED)
	{
		fileError = 0;
		return FileError::FLUSH_FAILED;
	}
	return FileError::NONE;
}

void File::setError(FileError err)
{
	this->fileError = fileError | (int)err;
}

DWORD getSeekPattern(FileSeek seek)
{
	switch (seek)
	{
	case FileSeek::BEGIN:
		return FILE_BEGIN;

	case FileSeek::CURRENT:
		return FILE_CURRENT;

	case FileSeek::END:
		return FILE_END;

	default:
		assert(0);
		return 0;
	}
}

DWORD getAccessPattern(FileMode mode)
{
	switch (mode)
	{
	case FileMode::READ:
		return GENERIC_READ;

	case FileMode::WRITE:
		return GENERIC_WRITE;

	case FileMode::READ_WRITE:
		return GENERIC_READ | GENERIC_WRITE;

	default:
		assert(0);
		return 0;
	}
}

#endif