#ifndef ISerialize_h__
#define ISerialize_h__

#include "Inc.h"

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

struct ISerialize
{
	_setStream_t mUninitialized;
	void * mStream;
}__pack;

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif // ISerialize_h__
