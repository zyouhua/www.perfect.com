#pragma once

#include "Incpp.hpp"
#include "rapidxml.hpp"

using namespace rapidxml;

namespace std {

	class XmlReader : public SerializeInternal
	{
	public:
		//__b
		void _serialize(bool& nValue, const wchar_t * nName, bool nOptimal = false);
		//__i8
		void _serialize(__i8& nValue, const wchar_t * nName, __i8 nOptimal = 0);
		//__u8
		void _serialize(__u8& nValue, const wchar_t * nName, __u8 nOptimal = 0);
		//__i16
		void _serialize(__i16& nValue, const wchar_t * nName, __i16 nOptimal = 0);
		//__u16
		void _serialize(__u16& nValue, const wchar_t * nName, __u16 nOptimal = 0);
		//__i32
		void _serialize(__i32& nValue, const wchar_t * nName, __i32 nOptimal = 0);
		//__u32
		void _serialize(__u32& nValue, const wchar_t * nName, __u32 nOptimal = 0);
		//__i64
		void _serialize(__i64& nValue, const wchar_t * nName, __i64 nOptimal = 0);
		//__u64
		void _serialize(__u64& nValue, const wchar_t * nName, __u64 nOptimal = 0);
		//__s
		void _serialize(wstring& nValue, const wchar_t * nName, const wchar_t * nOptimal = L"");
		//string
		void _serialize(string& nValue, const wchar_t * nName, const char * nOptimal = "");
		//__f
		void _serialize(float& nValue, const wchar_t * nName, float nOptimal = 0.f);
		//__d
		void _serialize(double& nValue, const wchar_t * nName, double nOptimal = 0.);
		//__t
		void _serialize(IStream * nValue, const wchar_t * nName);
		//ISerialize
		void _openUrl(const wstring& nUrl);
		SerializeIO_ _serializeIO() const;
		__i32 _pushStream(const wchar_t * nName);
		void _popStream();
		void _runClose();
	public:
		XmlReader();
		~XmlReader();
	private:
		xml_document<wchar_t> mXmlDocument;
		xml_node<wchar_t> * mXmlNode;
		stack<xml_node<wchar_t> *> mXmlNodes;
	};
	typedef shared_ptr<XmlReader> XmlReaderPtr;

}
