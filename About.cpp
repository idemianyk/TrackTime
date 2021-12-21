#include "About.h"

using namespace System;
using namespace System::Windows::Forms;


System::Void Project1::About::About_Load(System::Object^ sender, System::EventArgs^ e)
{
	txtbxAboutAuthor->Text = "Про виконавця\n" + "Назва додатку: TrackTime 1.0.0.80\n" +
		"Виконавець: Дем'ник Ірина 1ПІ-19б\n";
	AboutProgram->Text = "Додаток призначений для створення звітів використання застосунків користувачем.  " + 
		"TrackTime має також функцію завершення процесів, фіксації процесів та часу їх роботи у ситсемі, показу звітів, яку вміщують процес та час його роботи, "+
		"а також збереження їх у файл текстового формату. Потім цей звіт можна відкрити та переглянути у програмі";
	
	return System::Void();
}

System::Void Project1::About::btnOk_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}
