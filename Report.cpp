#include "Report.h"
#include "MyForm.h"
#include <chrono>

using namespace System;
using namespace System::Windows::Forms;

//ProcessHandling processHandling;
System::Void Project1::Report::Report_Load(System::Object^ sender, System::EventArgs^ e)
{
    std::map < std::string, long long> processesAndDuration = MyForm::getProcessesAndTime();
     std::map<std::string, long long>::iterator it;
     String^ strProcess;
	 std::string time;
     String^ strTime;

	 for (it = processesAndDuration.begin(); it != processesAndDuration.end(); it++) {
		 MyForm::convert_string_to_String(it->first, strProcess);
		 long seconds = it->second, hours = 0, minutes = 0;
		 minutes = seconds / 60;
		 hours = minutes / 60;
		 time = std::to_string(long(hours)) + ":" + std::to_string(long(minutes % 60)) + ":" + std::to_string(long(seconds % 60));
		 MyForm::convert_string_to_String(time, strTime);
		 strProcess += " Час:" + strTime;

		 lvProceses->Items->Add(strProcess);
	 }
    return System::Void();
}



System::Void Project1::Report::btnSearchProcess_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ itemText;
	String^ queryText;
	queryText = txtbxSearchProcess->Text->ToLower();
	for (int i = 0; i < lvProceses->Items->Count; i++) {
		lvProceses->Items[i]->Selected = false;
		lvProceses->Items[i]->Focused = false;
	}
	if (queryText == "") {
		MessageBox::Show("Введіть ім'я процесу", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}
	int itemsFound = 0;
	for (int i = 0; i < lvProceses->Items->Count; i++) {
		itemText = lvProceses->Items[i]->Text->ToLower();
		if (itemText->StartsWith(queryText)) {
			itemsFound++;
			lvProceses->Select();
			lvProceses->Items[i]->Selected = true;
			lvProceses->Items[i]->Focused = true;
			lvProceses->Items[i]->EnsureVisible();
		}
	}
	if (itemsFound == 0) {
		MessageBox::Show("Процес не знайдено", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	return System::Void();
}

System::Void Project1::Report::printFromFile()
{
	/*for (int i = 0; i < lvProceses->Items->Count; i++) {
		lvProceses->Items[i]->Remove();
	}*/
	lvProceses->Items->Clear();
	lvProceses->Items->Clear();
	
	std::map < std::string, long long> fromFile = MyForm::getDataFromReport();
	std::map<std::string, long long>::iterator it;
	String^ strProcess;
	std::string time;
	String^ strTime;

	for (it = fromFile.begin(); it != fromFile.end(); it++) {
		MyForm::convert_string_to_String(it->first, strProcess);
		long seconds = it->second, hours = 0, minutes = 0;
		minutes = seconds / 60;
		hours = minutes / 60;
		time = std::to_string(long(hours)) + ":" + std::to_string(long(minutes % 60)) + ":" + std::to_string(long(seconds % 60));
		MyForm::convert_string_to_String(time, strTime);
		strProcess += " Час:" + strTime;
		lvProceses->Items->Add(strProcess);
	}
	return System::Void();
}

System::Void Project1::Report::tsBtnClose_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}
