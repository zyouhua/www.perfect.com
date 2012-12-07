#include "XmlReader.hpp"

#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include "UrlParser.hpp"

namespace std {

	void XmlReader::_serialize( bool& nValue, const wchar_t * nName, bool nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<bool, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __i8& nValue, const wchar_t * nName, __i8 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__i8, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __u8& nValue, const wchar_t * nName, __u8 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__u8, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __i16& nValue, const wchar_t * nName, __i16 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__i16, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __u16& nValue, const wchar_t * nName, __u16 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__u16, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __i32& nValue, const wchar_t * nName, __i32 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__i32, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __u32& nValue, const wchar_t * nName, __u32 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__u32, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __i64& nValue, const wchar_t * nName, __i64 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__i64, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( __u64& nValue, const wchar_t * nName, __u64 nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<__u64, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( wstring& nValue, const wchar_t * nName, const wchar_t * nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			nValue = xmlAttribute_->value();
		}
	}

	void XmlReader::_serialize( string& nValue, const wchar_t * nName, const char * nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<string, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( float& nValue, const wchar_t * nName, float nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<float, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize( double& nValue, const wchar_t * nName, double nOptimal )
	{
		nValue = nOptimal;
		xml_attribute<wchar_t> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (__nptr == xmlAttribute_)
		{
			wchar_t * text_ = xmlAttribute_->value();
			nValue = _convert<double, wchar_t *>(text_);
		}
	}

	void XmlReader::_serialize(list<double>& nValue, const wchar_t * nName)
	{
		xml_node<wchar_t> * xmlNode_ = mXmlNode->first_node(nName);
		if (__nptr == xmlNode_)
		{
			return;
		}
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() )
		{
			wchar_t * text_ = xmlNode_->value();
			double value_ = _convert<double, wchar_t *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::_serialize( IStream * nValue, const wchar_t * nName )
	{
		mXmlNodes.push(mXmlNode);
		mXmlNode = mXmlNode->first_node(nName);
		if (__nptr != mXmlNode)
		{
			nValue->mRunSerialize(nValue, this);
		}
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}

	void XmlReader::_openUrl(const wstring& nUrl)
	{
		UrlParser urlParser_(nUrl);
		wstring path_ = urlParser_._returnResult();
		file<wchar_t> fileDoc_(path_.c_str());
		mXmlDocument.parse<0>(fileDoc_.data()); 
	}

	SerializeIO_ XmlReader::_serializeIO() const
	{
		return mSerializeIOInput_;
	}

	__i32 XmlReader::_pushStream( const wchar_t * nName )
	{
		mXmlNodes.push(mXmlNode);
		return 0;
	}

	void XmlReader::_popStream()
	{
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}

	void XmlReader::_runClose()
	{
	}

	XmlReader::XmlReader()
		: mXmlDocument()
		, mXmlNode(__nptr)
		, mXmlNodes()
	{
	}

	XmlReader::~XmlReader()
	{
		mXmlDocument.clear();
		mXmlNode = __nptr;
	}

}
