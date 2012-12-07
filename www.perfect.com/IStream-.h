#ifndef IStream__h__
#define IStream__h__

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct ISerialize ISerialize;
	typedef struct IStream IStream;
	typedef void (*_setStream_t)(IStream * nStream);
	typedef void (*_runSerialize_t)(IStream * nStream, ISerialize * nSerialize);

#ifdef __cplusplus
}
#endif
#endif // IStream__h__
