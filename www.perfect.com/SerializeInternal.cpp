#include "SerializeInternal.hpp"

namespace std {

	ISerialize * SerializeInternal::_getSerialize()
	{

	}

	SerializeInternal::SerializeInternal()
	{

	}

	SerializeInternal::~SerializeInternal()
	{
		mSerialize = __nptr;
		mStream.mRunSerialize = __nptr;
		mStream.mUninitialized = __nptr;
	}

}
