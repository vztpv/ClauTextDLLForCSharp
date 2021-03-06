// ClauTextForCSharp.h

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string>

using namespace System;

namespace wiz {
	namespace load_data {
		class UserType;
	}

	class ClauTextLib
	{
	private:
		wiz::load_data::UserType* global;
	public:
		ClauTextLib();
		~ClauTextLib();
		ClauTextLib(const ClauTextLib&) = delete;
		ClauTextLib& operator=(const ClauTextLib&) = delete;
		/// ClearData
		void Clear();
		/// LoadDataFromFile ( load data )
		void LoadDataFromFile(const std::string& fileName);
		/// LoadDataFromString ( load data )
		void LoadDataFromString(const std::string& data);
		/// SaveData
		void SaveData(const std::string& fileName);
		/// RunEvent ( load event and run event )
		std::string RunEventString(const std::string& eventData);

		std::string RunEventFile(const std::string& fileName);
	};
}

namespace wiz {
	inline std::string Convert(System::String^ s);

	inline System::String^ Convert(const std::string& s);

	public ref class ClauText
	{
	private:
		ClauTextLib* global;
	public:
		ClauText();
		~ClauText();
		!ClauText();
	public:
		/// ClearData
		void Clear();
		/// LoadDataFromFile ( load data )
		void LoadDataFromFile(System::String^ fileName);
		/// LoadDataFromString ( load data )
		void LoadDataFromString(System::String^ data);
		/// SaveData
		void SaveData(System::String^ fileName);
		/// RunEvent ( load event and run event )
		System::String^ RunEventString(System::String^ eventData);

		System::String^ RunEventFile(System::String^ fileName);
	};
}
