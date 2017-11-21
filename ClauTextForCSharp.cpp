// 기본 DLL 파일입니다.

#include "ClauTextForCSharp.h"


namespace wiz {
	inline std::string Convert(System::String^ s) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		std::string os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		return os;
	}
	inline System::String^ Convert(const std::string& s) {
		return gcnew System::String(s.c_str());
	}

	/// Clear
	void ClauText::ClearData()
	{
		global->Remove();
	}
	/// LoadDataFromFile ( load data )
	void ClauText::LoadDataFromFile(System::String^ fileName) {
		std::string _fileName = Convert(fileName);

		wiz::load_data::LoadData::LoadDataFromFile(_fileName, *global);
	}
	/// LoadDataFromString ( load data )
	void ClauText::LoadDataFromString(System::String^ data) {
		std::string _data = Convert(data);

		wiz::load_data::LoadData::LoadDataFromString(_data, *global);
	}
	/// SaveData
	void ClauText::SaveData(System::String^ fileName) {
		std::string _fileName = Convert(fileName);

		wiz::load_data::LoadData::SaveWizDB(*global, _fileName, "1"); // EU4 "1", JSON "3"
	}
	/// RunEvent ( load event and run event )
	System::String^ ClauText::RunEvent(System::String^ eventData) {
		std::string _eventData = Convert(eventData);
		wiz::StringBuilder builder(102400);

		wiz::load_data::LoadData::AddData(*global, "/./", _eventData, "TRUE", ExcuteData(), &builder);

		System::String^ result = Convert(excute_module("", global, ExcuteData(), 0));

		return result;
	}
}
