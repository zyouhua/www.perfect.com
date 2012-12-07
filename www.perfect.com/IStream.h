#ifndef IStream_h__
#define IStream_h__

#include "Inc.h"

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

struct IStream
{
	_runSerialize_t mRunSerialize;
	_setStream_t mUninitialized;
	void * mStream;
}__pack;

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif // IStream_h__
