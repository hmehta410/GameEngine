#ifndef FILE_H
#define FILE_H

// Make the assumption of c-char strings, not UNICODE
// 32 bit files, not supporting 64 bits
#ifdef _WIN32
#include <windows.h>
#else
#include <stdio.h>
#endif

enum class FileMode
{
	READ,
	WRITE,
	READ_WRITE
};

enum class FileSeek
{
	BEGIN,
	CURRENT,
	END
};

//will work as bit flags
enum class FileError : int
{
	NONE = 0,
	OPEN_FAILED = 1 << 0,
	CLOSE_FAILED = 1 << 1,
	WRITE_FAILED = 1 << 2,
	READ_FAILED = 1 << 3,
	SEEK_FAILED = 1 << 4,
	FLUSH_FAILED = 1 << 5,
	UNDEFINED_STATE_AFTER_MOVE = 1 << 6,
	READ_RETURNED_EARLY = 1 << 7,
};

class File
{
public:
	//will set an error code that can be retreived with GetError()
	//if construction fails
	File(const char* const fileName, FileMode mode);
	File(FileMode mode);
	~File();

	File(const File& file) = delete;
	File(File&& file);

	File& operator=(File&& file);

	//will reset the fileError to FileError::NONE after being called 
	//except when fileError == FileError::UNDEFINED_STATE_AFTER_MOVE
	FileError GetError();

	//Attempts to open file based on the FileMode set in the constructor
	//Will fail if attempting to open an already open file
	void Open(const char* const fileName);

	//Attempts to close file handle
	//May be called multiple times on the same File object
	void Close();

	//returns the number of bytes read.
	int Read(void* const buffer, size_t size);
	void Write(const void* const buffer, size_t size);

	void Seek(FileSeek seek, int offset);
	int Tell();
	void Flush();
	int GetSize();

private:

#ifdef _WIN32
	typedef HANDLE FileHandle;
#else
	typedef FILE* FileHandle;
#endif

	FileHandle fileHandle;
	FileMode fileMode;
	int fileError;
	int fileSize;

	void setError(FileError err);
};

#endif