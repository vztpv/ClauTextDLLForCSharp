// ClauTextForCSharp.h

#pragma once

#include <string>

#define _CRT_SECURE_NO_WARNINGS
#include <wiz/ClauText.h>

using namespace System;

namespace wiz {
	inline std::string Convert(System::String^ s);

	inline System::String^ Convert(const std::string& s);

	public ref class ClauText
	{
	private:
		wiz::load_data::UserType* global;
	public:
		ClauText() {
			global = new wiz::load_data::UserType();
		}
		~ClauText() {
			this->!ClauText();
		}
		!ClauText() {
			delete global;
		}
	public:
		/// ClearData
		void ClearData();
		/// LoadDataFromFile ( load data )
		void LoadDataFromFile(System::String^ fileName);
		/// LoadDataFromString ( load data )
		void LoadDataFromString(System::String^ data);
		/// SaveData
		void SaveData(System::String^ fileName);
		/// RunEvent ( load event and run event )
		System::String^ RunEvent(System::String^ eventData);
	};
}
