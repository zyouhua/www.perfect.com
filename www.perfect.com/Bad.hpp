#pragma once

namespace std {

	class Bad : protected virtual noncopyable
	{
	public:
		signal<bool ()> m_tIsBad;
		virtual bool _isBad() const;
		void _runBad();

	protected:
		void _saveBad();

	public:
		Bad();
		virtual ~Bad();

	private:
		bool mIsBad;
	};

}
