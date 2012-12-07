#pragma once

namespace std {

	class Serialize;
	class Stream : public Bad
	{
	public:
		virtual void _serialize(Serialize * nSerialize) = 0;
		IStream * _getSteam();
		Stream();
		virtual ~Stream();
	private:
		IStream mStream;
	};
	typedef shared_ptr<Stream> StreamPtr;

}
