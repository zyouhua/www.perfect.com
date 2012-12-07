#ifndef Inc_h__
#define Inc_h__

typedef char __i8;
typedef unsigned char __u8;

typedef short __i16;
typedef unsigned short __u16;

typedef long __i32;
typedef unsigned long __u32;

typedef __int64 __i64;
typedef unsigned __int64 __u64;

#define __nptr 0

#ifdef _MSC_VER
#define __pack
#else
#define __pack __attribute__((packed))
#endif

#ifdef EXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi __declspec(dllimport)
#endif

#include "__signal-.h"
#include "__signal.h"

#endif // Inc_h__
