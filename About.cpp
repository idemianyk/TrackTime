#include "About.h"

using namespace System;
using namespace System::Windows::Forms;


System::Void Project1::About::About_Load(System::Object^ sender, System::EventArgs^ e)
{
	txtbxAboutAuthor->Text = "��� ���������\n" + "����� �������: TrackTime 1.0.0.80\n" +
		"����������: ���'��� ����� 1ϲ-19�\n";
	AboutProgram->Text = "������� ����������� ��� ��������� ���� ������������ ���������� ������������.  " + 
		"TrackTime �� ����� ������� ���������� �������, �������� ������� �� ���� �� ������ � ������, ������ ����, ��� ������� ������ �� ��� ���� ������, "+
		"� ����� ���������� �� � ���� ���������� �������. ���� ��� ��� ����� ������� �� ����������� � �������";
	
	return System::Void();
}

System::Void Project1::About::btnOk_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}
