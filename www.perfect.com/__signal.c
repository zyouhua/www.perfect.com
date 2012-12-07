#include "Inc.h"

#include <malloc.h>

void __signal_initialize(__signal * nSignal)
{
	nSignal->mHead = __nptr;
	nSignal->mTail = __nptr;
}

void __signal_push_back(__signal * nSignal, void * nData)
{
	__signal_node * signalnode = __nptr;
	signalnode = (__signal_node *)calloc(1, sizeof(__signal_node));
	signalnode->mData = nData;
	signalnode->mNext = __nptr;
	if (__nptr == nSignal->mHead)
	{
		nSignal->mHead = signalnode;
		nSignal->mTail = signalnode;
	}
	else
	{
		nSignal->mTail->mNext = signalnode;
		nSignal->mTail = signalnode;
	}
}

void __signal_run(__signal * nSignal, _run_signal_t nRunSignal)
{
	__signal_node * signalnode = nSignal->mHead;
	for ( ; signalnode != __nptr; signalnode = signalnode->mNext)
	{
		void * data = signalnode->mData;
		nRunSignal(data);
	}
}

void __signal_remove(__signal * nSignal, void * nData)
{
	__signal_node * prevnode = __nptr;
	__signal_node * signalnode = nSignal->mHead;
	for ( ; signalnode != __nptr; signalnode = signalnode->mNext)
	{
		void * data = signalnode->mData;
		if (nData != data)
		{
			prevnode = signalnode;
			continue;;
		}
		data = __nptr;
		if (nSignal->mHead == nSignal->mTail)
		{
			free(signalnode);
			signalnode = __nptr;
			nSignal->mHead = __nptr;
			nSignal->mTail = __nptr;
			break;
		}
		if (__nptr == prevnode)
		{
			nSignal->mHead = signalnode->mNext;
			free(signalnode);
			signalnode = __nptr;
			break;
		}
		if (__nptr == signalnode->mNext)
		{
			nSignal->mTail = prevnode;
			free(signalnode);
			signalnode = __nptr;
			break;
		}
		prevnode->mNext = signalnode->mNext;
		free(signalnode);
		signalnode = __nptr;
		break;
	}
}

void __signal_uninitialized(__signal * nSignal)
{
	__signal_node * signalnode = nSignal->mHead;
	__signal_node * tempnode = __nptr;
	for ( ; signalnode != __nptr; )
	{
		void * data = signalnode->mData;
		data = __nptr;
		tempnode = signalnode;
		signalnode = signalnode->mNext;
		free(tempnode);
		tempnode = __nptr;
	}
	nSignal->mHead = __nptr;
	nSignal->mTail = __nptr;
}
