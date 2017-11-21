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

	ClauText::ClauText() {
		global = new wiz::ClauTextLib();
	}
	ClauText::~ClauText() {
		this->!ClauText();
	}
	ClauText::!ClauText() {
		delete global;
	}
	/// Clear
	void ClauText::Clear()
	{
		global->Clear();
	}
	/// LoadDataFromFile ( load data )
	void ClauText::LoadDataFromFile(System::String^ fileName) {
		std::string _fileName = Convert(fileName);

		global->LoadDataFromFile(_fileName);
	}
	/// LoadDataFromString ( load data )
	void ClauText::LoadDataFromString(System::String^ data) {
		std::string _data = Convert(data);

		global->LoadDataFromString(_data);
	}
	/// SaveData
	void ClauText::SaveData(System::String^ fileName) {
		std::string _fileName = Convert(fileName);

		global->SaveData(_fileName); 
	}
	/// RunEvent ( load event and run event )
	System::String^ ClauText::RunEventString(System::String^ eventData) {
		std::string _eventData = Convert(eventData);
		return Convert(global->RunEventString(_eventData));
	}

	System::String^ ClauText::RunEventFile(System::String^ fileName) {
		std::string _fileName = Convert(fileName);
		return Convert(global->RunEventFile(_fileName));
	}
}
