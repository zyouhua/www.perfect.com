#pragma once

namespace std {

	class SerializeInternal
	{
	public:
		//__b
		virtual void _serialize(bool& nValue, const wchar_t * nName, bool nOptimal = false) = 0;
		//__i8
		virtual void _serialize(__i8& nValue, const wchar_t * nName, __i8 nOptimal = 0) = 0;
		//__u8
		virtual void _serialize(__u8& nValue, const wchar_t * nName, __u8 nOptimal = 0) = 0;
		//__i16
		virtual void _serialize(__i16& nValue, const wchar_t * nName, __i16 nOptimal = 0) = 0;
		//__u16
		virtual void _serialize(__u16& nValue, const wchar_t * nName, __u16 nOptimal = 0) = 0;
		//__i32
		virtual void _serialize(__i32& nValue, const wchar_t * nName, __i32 nOptimal = 0) = 0;
		//__u32
		virtual void _serialize(__u32& nValue, const wchar_t * nName, __u32 nOptimal = 0) = 0;
		//__i64
		virtual void _serialize(__i64& nValue, const wchar_t * nName, __i64 nOptimal = 0) = 0;
		//__u64
		virtual void _serialize(__u64& nValue, const wchar_t * nName, __u64 nOptimal = 0) = 0;
		//wstring
		virtual void _serialize(wstring& nValue, const wchar_t * nName, const wchar_t * nOptimal = L"") = 0;
		//string
		virtual void _serialize(string& nValue, const wchar_t * nName, const char * nOptimal = "") = 0;
		//__float
		virtual void _serialize(float& nValue, const wchar_t * nName, float nOptimal = 0.f) = 0;
		//__double
		virtual void _serialize(double& nValue, const wchar_t * nName, double nOptimal = 0.) = 0;
		//__t
		virtual void _serialize(IStream * nValue, const wchar_t * nName) = 0;

		ISerialize * _getSerialize();
		SerializeInternal();
		virtual ~SerializeInternal();

	private:
		ISerialize mSerialize;
	};

}
