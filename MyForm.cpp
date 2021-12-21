#include "MyForm.h"
#include "Report.h"
#include "About.h"
#include "ProcessHandling.h"
#include <chrono>
#include <map>
#include <set>
#include <fstream>
#include <sstream> 


using namespace System;
using namespace System::Windows::Forms;

std::vector <std::string> processes_string;
std::map < std::string, std::chrono::time_point<std::chrono::system_clock>> allProcessesAndTimeMap;//процеси і точка початку їх роботи
std::map < std::string, long long> allRanProcessesAndDuration;//процеси і тривалість їх роботи
std::map <std::string, long long> processesAndDurationFromReport;
std::vector <std::string> ranButClosed;
std::string defaultDirectoryPath;
std::string settingsPath;
ProcessHandling processHandling;

[STAThreadAttribute] 

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	Application::Run(% form);
}

System::Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	statusStrip->ShowItemToolTips = true;

	tsStatusLabel->Text ="ssss";
	tsStatusLabel->ToolTipText = "222222";
	tsStatusLabel->Visible = false;
	processHandling = ProcessHandling();
	processes_string = processHandling.getProcessesAndNumbers();
	Collections::Generic::List<System::String^>^ processes= gcnew Collections::Generic::List<System::String^>();
	for (int i = 0; i < processes_string.size(); i++) {
		processes->Add(gcnew String(processes_string[i].c_str()));
		allProcessesAndTimeMap.emplace(processes_string[i], std::chrono::system_clock::now());
		allRanProcessesAndDuration.emplace(processes_string[i], 0);
	}
	for (int i = 0; i <processes->Count; i++)
		lvProcesses->Items->Add(processes[i]);

	settingsPath = "settings.txt";
	
	std::ifstream in;
	in.open(settingsPath);
	if (is_empty(in)) {
		defaultDirectoryPath = "D:\\3rdCourse\\ОС\\KursovaProbe\\Project1\\Project1\\Reports";
		
	}
	else {
		std::string strFromSettings;
		const char delim = '|';
		std::vector<std::string> out;
		std::string::size_type sz = 0;
		while (!in.eof()) {
			strFromSettings = "";
			std::getline(in, strFromSettings);
			if (strFromSettings.find("DirectoryPath") != std::string::npos) {
				tokenize(strFromSettings, delim, out);
				defaultDirectoryPath = out[1];
				out.clear();
			}
		}
	}
	in.close();
	backgroundWorker1->RunWorkerAsync(); // пуск потока
	return System::Void();
}

System::Void Project1::MyForm::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
} 

System::Void Project1::MyForm::btnTerminate_Click(System::Object^ sender, System::EventArgs^ e)
{
	//emulateProgress();
	auto now= std::chrono::system_clock::now();
	std::string s;
	if (lvProcesses->SelectedItems->Count == 0) {
		MessageBox::Show("Оберіть процес для завершення", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}
	
	convert_String_to_string(lvProcesses->SelectedItems[0]->Text, s);
	for (int i = 0; i < processes_string.size(); i++) {
		if (processes_string[i].find(s) != std::string::npos) {
			// remove processes_string[i]?
			lvProcesses->SelectedItems[0]->Remove();
			
			processHandling.terminateProcess(processes_string[i]);
			//додати рядок нижче в потік напевно
			if (std::count(ranButClosed.begin(), ranButClosed.end(), processes_string[i]) == 0) {
				allRanProcessesAndDuration[processes_string[i]] = std::chrono::duration_cast<std::chrono::seconds>(now - allProcessesAndTimeMap[processes_string[i]]).count();
				ranButClosed.push_back(processes_string[i]);
				allProcessesAndTimeMap[processes_string[i]] = std::chrono::time_point<std::chrono::system_clock>{};
			}
			else if (std::count(ranButClosed.begin(), ranButClosed.end(), processes_string[i]) == 1) {
				allRanProcessesAndDuration[processes_string[i]] += std::chrono::duration_cast<std::chrono::seconds>(now - allProcessesAndTimeMap[processes_string[i]]).count();
				allProcessesAndTimeMap[processes_string[i]] = std::chrono::time_point<std::chrono::system_clock>{};
			}


			//allProcessesAndTimeMap[processes_string[i]]=;
			break;
		}
	}
	
	//std::string cmmdtsk = "taskkill /im " + s + " /f"; //create full string to run in line below (had to this for system() to work, yet to be optimized from this)
	//system(cmmdtsk.c_str()); //c_str() converts cmmdtsk to c string

	return System::Void();
}

System::Void Project1::MyForm::btnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	lvProcesses->Items->Clear();
	processHandling.refreshProcesses();
	processes_string.clear();
	processes_string = processHandling.getProcessesAndNumbers();
	Collections::Generic::List<System::String^>^ processes = gcnew Collections::Generic::List<System::String^>();
	for (int i = 0; i < processes_string.size(); i++) {
		processes->Add(gcnew String(processes_string[i].c_str()));
	}
	for (int i = 0; i < processes->Count; i++)
		lvProcesses->Items->Add(processes[i]);
	return System::Void();
}

//зробити щоб воно було незалежне від регістру.
System::Void Project1::MyForm::btProcessSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ itemText;
	String^ queryText;
	queryText = tbProcessName->Text->ToLower();
	for (int i = 0; i < lvProcesses->Items->Count; i++) {
		lvProcesses->Items[i]->Selected = false;
		lvProcesses->Items[i]->Focused = false;
	}
	if (queryText == "") {
		MessageBox::Show("Введіть ім'я процесу", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}
	int itemsFound = 0;
	for (int i = 0; i < lvProcesses->Items->Count; i++) {
		itemText=lvProcesses->Items[i]->Text->ToLower();
		if (itemText->StartsWith(queryText)) {
			itemsFound++;
			lvProcesses->Select();
			lvProcesses->Items[i]->Selected=true;
			lvProcesses->Items[i]->Focused = true;
			lvProcesses->Items[i]->EnsureVisible();
		}
	}
	if (itemsFound == 0) {
		MessageBox::Show("Процес не знайдено", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	emulateProgress();
	return System::Void();
}

System::Void Project1::MyForm::CountProcessesTime()
{
	std::map<std::string, long long>::iterator it;
	std::map < std::string, std::chrono::time_point<std::chrono::system_clock>>::iterator it1;
	for (it = allRanProcessesAndDuration.begin(); it != allRanProcessesAndDuration.end(); it++)
	{
		it1 = allProcessesAndTimeMap.find(it->first);
		auto timeStamp = it1->second;
		auto now = std::chrono::system_clock::now();
		if (it1->second != std::chrono::time_point<std::chrono::system_clock>{}) {
			if (std::count(ranButClosed.begin(), ranButClosed.end(), it->first) == 0)
				it->second = std::chrono::duration_cast<std::chrono::seconds>(now - timeStamp).count();
			else
				it->second += std::chrono::duration_cast<std::chrono::seconds>(now - timeStamp).count();
		}
	}
	return System::Void();
}

System::Void Project1::MyForm::saveReport()
{
	CountProcessesTime();
	SaveFileDialog save;
	save.RestoreDirectory = true;
	save.AutoUpgradeEnabled = true;
	String^ s;
	save.InitialDirectory = convert_string_to_String(defaultDirectoryPath,s);
	save.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	save.FilterIndex = 1;
	save.ShowDialog();
	save.FileName;
	std::string fileNameStdString;
	convert_String_to_string(save.FileName, fileNameStdString);
	std::ofstream outdata;
	if (!outdata.is_open()) {
		return System::Void();
	}
	outdata.open(fileNameStdString);
	std::map<std::string, long long>::iterator it;
	for (it = allRanProcessesAndDuration.begin(); it != allRanProcessesAndDuration.end(); it++)
	{
		outdata << it->first<<"|"<<it->second<<"\n";
	}
	outdata.close();
	return System::Void();
}	

System::Void Project1::MyForm::openReport()
{
	processesAndDurationFromReport.clear();
	OpenFileDialog open; 
	String^ s;
	open.InitialDirectory = convert_string_to_String(defaultDirectoryPath, s);
	open.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	open.FilterIndex = 1;
	open.ShowDialog();
	std::string fileNameStdString;
	convert_String_to_string(open.FileName, fileNameStdString);
	
	std::ifstream indata(fileNameStdString);
	if (!indata.is_open()) {
		return System::Void();
	}
	std::string stringsFromFile;
	const char delim = '|';
	std::vector<std::string> out;
	std::string::size_type sz = 0;
	int step = 0;
	while (!indata.eof()) {
		step++;
		stringsFromFile = "";
		std::getline(indata, stringsFromFile);
		if (stringsFromFile == "\n")
			continue;
		tokenize(stringsFromFile, delim, out);
		try {
			if (out.size() > 1)
			processesAndDurationFromReport.emplace(out[0], std::stoll(out[1], nullptr, 10));
		}
		catch (const std::exception& ex) {
			MessageBox::Show(convert_string_to_String(out[0], s), "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		out.clear();
	}
	
	indata.close();
	Report^ report = gcnew Report();
	report->Show();
	report->printFromFile();
	
	
	return System::Void();
}



System::Void Project1::MyForm::mniSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveReport();
	return System::Void();
}



System::Void Project1::MyForm::mniOpen_Click(System::Object^ sender, System::EventArgs^ e)
{
	openReport();
	return System::Void();
}

System::Void Project1::MyForm::mniReportFolder_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::ofstream out;
	out.open(settingsPath);
	FolderBrowserDialog fldBrowse;
	fldBrowse.ShowDialog();
	convert_String_to_string(fldBrowse.SelectedPath, defaultDirectoryPath);
	out << "DirectoryPath|" << defaultDirectoryPath;
	out.close();
	return System::Void();
}

bool Project1::MyForm::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}





System::Void Project1::MyForm::btnShowReport_Click(System::Object^ sender, System::EventArgs^ e)
{
	Report^ f2 = gcnew Report();
	CountProcessesTime();
	f2->Show();
	return System::Void();
}

System::Void Project1::MyForm::compareProcesses()
{
	//тут шось не так 
	processHandling.refreshProcesses();
	std::vector <std::string> oldProcesses=processes_string;
	processes_string = processHandling.getProcessesAndNumbers();
	if (oldProcesses.size() != processes_string.size()) {
		for (int i = 0; i < processes_string.size(); i++) {
			if(std::count(oldProcesses.begin(), oldProcesses.end(), processes_string[i]) == 0){
			if ( std::count(ranButClosed.begin(), ranButClosed.end(), processes_string[i]) == 0) {
				allRanProcessesAndDuration.emplace(processes_string[i], 0);
				allProcessesAndTimeMap.emplace(processes_string[i], std::chrono::system_clock::now());
			}
			else if (std::count(ranButClosed.begin(), ranButClosed.end(), processes_string[i]) >= 1) {
				allProcessesAndTimeMap[processes_string[i]] = std::chrono::system_clock::now();
			}
			}
		}
		for (int i = 0; i < oldProcesses.size(); i++) {
			if (std::count(processes_string.begin(), processes_string.end(), oldProcesses[i])==0) {
				auto timeStamp = allProcessesAndTimeMap[oldProcesses[i]];
				if (timeStamp == std::chrono::time_point<std::chrono::system_clock>{})
					continue;
				auto now = std::chrono::system_clock::now();
				if (std::count(ranButClosed.begin(), ranButClosed.end(), oldProcesses[i]) == 0) {
					allRanProcessesAndDuration[oldProcesses[i]] = std::chrono::duration_cast<std::chrono::seconds>(now - timeStamp).count();
					allProcessesAndTimeMap[oldProcesses[i]] = std::chrono::time_point<std::chrono::system_clock>{};
					ranButClosed.push_back(oldProcesses[i]);
				}
				else if(std::count(ranButClosed.begin(), ranButClosed.end(), oldProcesses[i]) == 1) {
					allRanProcessesAndDuration[oldProcesses[i]] += std::chrono::duration_cast<std::chrono::seconds>(now - timeStamp).count();
					allProcessesAndTimeMap[oldProcesses[i]] = std::chrono::time_point<std::chrono::system_clock>{};
				}
				
				}
		}	
		oldProcesses.clear();
		processes_string.clear();
		btnRefresh->PerformClick();
	}

	return System::Void();
}



std::map < std::string, long long> Project1::MyForm::getProcessesAndTime()
{
	return allRanProcessesAndDuration;
}

std::map < std::string, long long> Project1::MyForm::getDataFromReport() {
	return processesAndDurationFromReport;
}

System::Void Project1::MyForm::tsBtnExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}

System::Void Project1::MyForm::emulateProgress()
{
	tsStatusLabel->Text = "Завантаження";
	tsStatusLabel->Visible = true;
	tsProgressBar->ProgressBar->Visible = true;
	while (tsProgressBar->ProgressBar->Value < 100) {
		tsProgressBar->ProgressBar->Value += tsProgressBar->ProgressBar->Step;
		Sleep(100);
	}
	tsStatusLabel->Visible = false;
	tsProgressBar->ProgressBar->Visible = false;
	tsProgressBar->ProgressBar->Value = 0;
	tsStatusLabel->Text = "";
	return System::Void();
}

System::Void Project1::MyForm::tsBtnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveReport();
	return System::Void();
}

System::Void Project1::MyForm::tsBtnOpen_Click(System::Object^ sender, System::EventArgs^ e)
{
	openReport();
	return System::Void();
}

System::Void Project1::MyForm::tsBtnReport_Click(System::Object^ sender, System::EventArgs^ e)
{
	btnShowReport->PerformClick();
	return System::Void();
}

System::Void Project1::MyForm::tsBtnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	btnRefresh->PerformClick();
	return System::Void();
}

System::Void Project1::MyForm::mniAbout_Click(System::Object^ sender, System::EventArgs^ e)
{
	About^ about = gcnew About();
	about->Show();
	return System::Void();
}



std::string& Project1::MyForm::convert_String_to_string(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)(chars)));
	return os;
}

 String^ Project1::MyForm::convert_string_to_String(std::string os, String^ &s) {
	s = gcnew String(os.c_str());
	return s;
}

 System::Void Project1::MyForm::tokenize(std::string const& str, const char delim, std::vector<std::string>& out)
 {
	 std::stringstream ss(str);
	 std::string s;
	 while (std::getline(ss, s, delim)) {
		 out.push_back(s);
	 }
	 return System::Void();
 }
