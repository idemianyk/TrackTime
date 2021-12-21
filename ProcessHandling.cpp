#include "ProcessHandling.h"
#include <process.h>
#include <algorithm>    // include algorithm header file (needed for operations such as sort)

void ProcessHandling::processesSnapshot() {
	// record all detetected running processes

	while (Process32Next(hProcessSnap, &pe32)) { //for each object (pe32) in hprocesssnap [Process32Next runs through processes]
		WCHAR wc[260];
		wcscpy_s(wc, pe32.szExeFile);

		//convert from wide char to narrow char array
		char ch[260];
		char DefChar = ' ';
		WideCharToMultiByte(CP_ACP, 0, wc, -1, ch, 260, &DefChar, NULL);
		process_name.push_back(std::string(ch)); // add process name to list of processes	
		processNameAndId.emplace(std::string(ch), pe32.th32ProcessID);
	};
}

void ProcessHandling::getUniqueProcessNames() {
	process_name_unique.push_back(process_name[3]); //initialise first process; start from 3 [0=blank 1='sys' var 2=another title 3=first process listed]
	process_num_occur.push_back(1); //initialise count for first process
	for (int k = 3; k <= process_name.size() - 1; k++) { // for each kth process name in complete list
		int add_unique = 1; //initialise parameter that tells if proccess is unique (=1)
		for (int j = 0; j <= process_name_unique.size() - 1; j++) { // for each jth process in list of unique process names
			std::string st1 = process_name[k]; //string 1 = process name from complete list (k)
			std::string st2 = process_name_unique[j]; // process name from unique list (j)
			if (strcmp(st1.c_str(), st2.c_str()) == 0 && add_unique == 1) { //if process names j&k match and if unique parameter=1 [c_str() converts cmmdtsk to c string, needed for strcmp]
																	  // note: str(a,b)=0 if string a and b are identical match
				process_num_occur[j] += 1; //add to count for re-occurance of process name
				add_unique = 0; //set unique process parameter to 0 [process name from list k is already in list j]
			}; // if loop
		}  // for loop (j)
		if (add_unique == 1) { //if process name from list k was unique (to be added to list)
			process_name_unique.push_back(process_name[k]); //add process name from list k to list of unique process
			process_num_occur.push_back(1);	 //initialise count of occurance for newly added process name
		} // if loop
	}// for loop (k)
}

void ProcessHandling::sortProcessesAndNumbers() {
	std::vector <std::string> process_name_unique_unsorted; //initialize vector that will be unsorted vector of process names;
	std::vector <int> process_num_occur_sorted; //initialize vector that will be unsorted vector of process names;
	for (int k = 0; k != process_name_unique.size(); k++)
		process_name_unique_unsorted.push_back(process_name_unique[k]); //add elements from original list to new list [for loop in one line]
	std::sort(process_name_unique.begin(), process_name_unique.end(), compareFunction); // sortvector using compare function (output is that process_name_unique is sorted alphabetically using function "compareFunction")
	// sort process_num_occur alphabetically and as new vector "process_num_occur_sorted" (previously initialized but is still empty
	for (int k = 0; k != process_name_unique.size(); k++)
		for (int j = 0; j != process_name_unique.size(); j++) { // for each element of sorted(k) and unsorted (j) for process name [Double for loop defined in one line]
			if (strcmp(process_name_unique[k].c_str(), process_name_unique_unsorted[j].c_str()) == 0)
			{
				process_num_occur_sorted.push_back(process_num_occur[j]); //if string of kth string (sorted) and jth string (unsorted) match;
			}
		}


}

std::vector<std::string> ProcessHandling::getProcessesAndNumbers()
{
	std::vector<std::string> result;
	for (int k = 0; k <= (process_name_unique.size() - 1); k++) { // for each kth element in sorted list of process names
		result.push_back(process_name_unique[k]);
	};
	return result;
}
//воно не робе. або робе. хз. доробиш потом
bool ProcessHandling::terminateProcess(std::string processName)
{
	auto it = processNameAndId.find(processName);
	if (it == processNameAndId.end())
		return FALSE;
	DWORD dwDesiredAccess = PROCESS_TERMINATE;
	BOOL  bInheritHandle = FALSE;
	HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, it->second);
	if (hProcess == NULL)
		return FALSE;

	BOOL result = TerminateProcess(hProcess, 1);
	CloseHandle(hProcess);
	return TRUE;
}

bool compareFunction(std::string a, std::string b) { //function for sorting strings (of vector) in alphabetic order [considering them as lower-case]
	for (int k = 0; k <= a.size() - 1; k++) { // convert each element in vector a (string) to lower case
		a[k] = tolower(a[k]); //convert kth element of vector a to lower case
	}
	for (int k = 0; k <= b.size() - 1; k++) { // convert each element in vector b (string) to lower case
		b[k] = tolower(b[k]); //convert kth element of vector b to lower case
	}
	return a < b; // return a<b (sorted)
}

void ProcessHandling::refreshProcesses() {
	process_name.clear();
	process_name_unique.clear();
	process_num_occur.clear();
	processNameAndId.clear();
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //take "snapshot" of processes running
	pe32.dwSize = sizeof(PROCESSENTRY32); //size of PROCESSENTRY32 [unused]
	processesSnapshot();
	getUniqueProcessNames();
	sortProcessesAndNumbers();
}





