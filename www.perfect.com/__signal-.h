#ifndef __signal__h__
#define __signal__h__

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

typedef struct __signal_node __signal_node;
typedef struct __signal __signal;

struct __signal_node
{
	void * mData;
	__signal_node * mNext;
} __pack;

struct __signal
{
	__signal_node * mHead;
	__signal_node * mTail;
} __pack;

typedef void (*_run_signal_t)(void * nFun);

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif // __signal-_h__
