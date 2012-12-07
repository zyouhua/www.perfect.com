#include "Incpp.hpp"

namespace std {

	void Bad::_runBad()
	{
		mIsBad = true;
	}

	void Bad::_saveBad()
	{
		mIsBad = false;
	}

	bool Bad::_isBad() const
	{
		if (mIsBad)
		{
			return true;
		}
		if (m_tIsBad.empty())
		{
			return false;
		}
		return this->m_tIsBad();
	}

	Bad::Bad()
		:mIsBad(false)
	{
		m_tIsBad.disconnect_all_slots();
	}

	Bad::~Bad()
	{
		m_tIsBad.disconnect_all_slots();
		mIsBad = false;
	}

}
