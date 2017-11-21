#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string>

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
