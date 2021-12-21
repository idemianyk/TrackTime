#pragma once
#pragma once
#include <windows.h> //include windows.h header file (needed for windows API)
#include <tlhelp32.h> //include tlhelp32.h
#include <string> //include string header (needed for some string operations)
#include <vector> // include vector header file (need for creating vectors)
#include<map>
//#include <map>
//#include <chrono>

class ProcessHandling
{
private:
	HANDLE hProcessSnap; //create handle identifier for object hprocesssnap
	PROCESSENTRY32 pe32; //Describes an entry from a list of the processes residing in the system address space when a snapshot was taken.
	std::vector <std::string> process_name; //initialize vector named "process_name" where each element will be a string (process name)
	std::vector <std::string> process_name_unique; //initialize vector of string elements (each element will be unique process name)
	std::vector <int> process_num_occur; //initialize vector of integer elements (each element will be count that unique process has occured)
	std::map <std::string, DWORD> processNameAndId;

public:
	ProcessHandling() {
		hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //take "snapshot" of processes running
		pe32.dwSize = sizeof(PROCESSENTRY32); //size of PROCESSENTRY32 [unused]
		processesSnapshot();
		getUniqueProcessNames();
		sortProcessesAndNumbers();
	}
	void processesSnapshot();
	void getUniqueProcessNames();
	void sortProcessesAndNumbers();
	std::vector <std::string> getProcessesAndNumbers();
	bool terminateProcess(std::string processName);
	void refreshProcesses();
};

bool compareFunction(std::string a, std::string b);



