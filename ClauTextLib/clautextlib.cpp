#pragma once

#include "clautextlib.h"

#define _CRT_SECURE_NO_WARNINGS
#include <wiz/ClauText.h>

namespace wiz {
	ClauTextLib::ClauTextLib() {
		global = new wiz::load_data::UserType("");
	}
	ClauTextLib::~ClauTextLib() {
		delete global;
	}

	/// ClearData
	void ClauTextLib::Clear()
	{
		global->Remove();
	}
	/// LoadDataFromFile ( load data )
	void ClauTextLib::LoadDataFromFile(const std::string& fileName)
	{
		wiz::load_data::LoadData::LoadDataFromFile(fileName, *global);
	}
	/// LoadDataFromString ( load data )
	void ClauTextLib::LoadDataFromString(const std::string& data)
	{
		wiz::load_data::LoadData::LoadDataFromString(data, *global);
	}
	/// SaveData
	void ClauTextLib::SaveData(const std::string& fileName)
	{
		wiz::load_data::LoadData::SaveWizDB(*global, fileName, "1"); /// "1" eu4, "3" json
	}
	/// RunEvent ( load event and run event )
	std::string ClauTextLib::RunEventString(const std::string& eventData)
	{
		wiz::StringBuilder builder(102400);

		wiz::load_data::LoadData::AddData(*global, "/./", eventData, "TRUE", ExcuteData(), &builder);

		return excute_module("", global, ExcuteData(), 0);
	}

	std::string ClauTextLib::RunEventFile(const std::string& fileName)
	{
		LoadDataFromFile(fileName);

		return excute_module("", global, ExcuteData(), 0);
	}
}
