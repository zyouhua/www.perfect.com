#pragma once

namespace std {

	namespace default_namespace {

		template<typename __t>
		struct Default
		{
			const __t operator () () const
			{
				return 0;
			}
		};

		template<>
		struct Default<bool>
		{
			const bool operator () ()const
			{
				return false;
			}
		};

		template<>
		struct Default<float>
		{
			const float operator () ()const
			{
				return 0.;
			}
		};

		template<>
		struct Default<double>
		{
			const double operator () ()const
			{
				return 0.;
			}
		};

		template<>
		struct Default<char *>
		{
			const char * operator () ()const
			{
				return "";
			}
		};

		template<>
		struct Default<wchar_t *>
		{
			const wchar_t * operator () () const
			{
				return L"";
			}
		};

		template<>
		struct Default<string>
		{
			const char * operator () ()const
			{
				return "";
			}
		};

		template<>
		struct Default<wstring>
		{
			const wchar_t * operator () () const
			{
				return L"";
			}
		};

	}

	template<typename __t>
	const __t _default()
	{
		return default_namespace::Default<__t>()();
	}

}
