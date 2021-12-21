#pragma once
#include "ProcessHandling.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//backgroundWorker1.WorkerReportsProgress = true;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
		
			backgroundWorker1->CancelAsync();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ mnDropdown;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ довідкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mniOpen;
	private: System::Windows::Forms::ToolStripMenuItem^ mniSave;
	private: System::Windows::Forms::ToolStripMenuItem^ mniExit;




	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ mniAbout;

	private: System::Windows::Forms::ToolStrip^ tsQuickAccess;














	private: System::Windows::Forms::ToolStripButton^ tsBtnExit;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::ListView^ lvProcesses;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btnTerminate;
	private: System::Windows::Forms::Button^ btnRefresh;


	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ lblProcess;

	private: System::Windows::Forms::TextBox^ tbProcessName;
	private: System::Windows::Forms::Button^ btProcessSearch;
	private: System::Windows::Forms::ToolStripMenuItem^ налаштуванняToolStripMenuItem;
	private: System::Windows::Forms::Button^ btnShowReport;

	public:BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::OpenFileDialog^ openReportDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ mniReportFolder;





	private: System::Windows::Forms::ToolStripButton^ tsBtnSave;
	private: System::Windows::Forms::ToolStripButton^ tsBtnOpen;
	private: System::Windows::Forms::ToolStripButton^ tsBtnReport;
	private: System::Windows::Forms::ToolStripButton^ tsBtnRefresh;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;


	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ tsStatusLabel;

	private: System::Windows::Forms::ToolStripProgressBar^ tsProgressBar;

	private: System::ComponentModel::IContainer^ components;







	public:

	public:

	public:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->mnDropdown = (gcnew System::Windows::Forms::MenuStrip());
			this->довідкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mniExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->налаштуванняToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mniReportFolder = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsQuickAccess = (gcnew System::Windows::Forms::ToolStrip());
			this->tsBtnSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsBtnOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsBtnReport = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsBtnRefresh = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsBtnExit = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->lvProcesses = (gcnew System::Windows::Forms::ListView());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnShowReport = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->btnTerminate = (gcnew System::Windows::Forms::Button());
			this->btProcessSearch = (gcnew System::Windows::Forms::Button());
			this->lblProcess = (gcnew System::Windows::Forms::Label());
			this->tbProcessName = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->openReportDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->tsStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tsProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->mnDropdown->SuspendLayout();
			this->tsQuickAccess->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// mnDropdown
			// 
			this->mnDropdown->ImageScalingSize = System::Drawing::Size(20, 20);
			this->mnDropdown->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->довідкаToolStripMenuItem,
					this->файлToolStripMenuItem, this->налаштуванняToolStripMenuItem
			});
			this->mnDropdown->Location = System::Drawing::Point(0, 0);
			this->mnDropdown->Name = L"mnDropdown";
			this->mnDropdown->Size = System::Drawing::Size(1247, 30);
			this->mnDropdown->TabIndex = 0;
			this->mnDropdown->Text = L"menuStrip1";
			this->mnDropdown->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// довідкаToolStripMenuItem
			// 
			this->довідкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->mniOpen,
					this->mniSave, this->toolStripSeparator1, this->mniExit
			});
			this->довідкаToolStripMenuItem->Name = L"довідкаToolStripMenuItem";
			this->довідкаToolStripMenuItem->Size = System::Drawing::Size(59, 26);
			this->довідкаToolStripMenuItem->Text = L"Файл";
			this->довідкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::довідкаToolStripMenuItem_Click);
			// 
			// mniOpen
			// 
			this->mniOpen->Name = L"mniOpen";
			this->mniOpen->Size = System::Drawing::Size(184, 26);
			this->mniOpen->Text = L"Відкрити звіт";
			this->mniOpen->Click += gcnew System::EventHandler(this, &MyForm::mniOpen_Click);
			// 
			// mniSave
			// 
			this->mniSave->Name = L"mniSave";
			this->mniSave->Size = System::Drawing::Size(184, 26);
			this->mniSave->Text = L"Зберегти звіт";
			this->mniSave->Click += gcnew System::EventHandler(this, &MyForm::mniSave_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(181, 6);
			// 
			// mniExit
			// 
			this->mniExit->Name = L"mniExit";
			this->mniExit->Size = System::Drawing::Size(184, 26);
			this->mniExit->Text = L"Вихід";
			this->mniExit->Click += gcnew System::EventHandler(this, &MyForm::вихідToolStripMenuItem_Click);
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mniAbout });
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(104, 26);
			this->файлToolStripMenuItem->Text = L"Інформація";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::файлToolStripMenuItem_Click);
			// 
			// mniAbout
			// 
			this->mniAbout->Name = L"mniAbout";
			this->mniAbout->Size = System::Drawing::Size(202, 26);
			this->mniAbout->Text = L"Про програму...";
			this->mniAbout->Click += gcnew System::EventHandler(this, &MyForm::mniAbout_Click);
			// 
			// налаштуванняToolStripMenuItem
			// 
			this->налаштуванняToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mniReportFolder });
			this->налаштуванняToolStripMenuItem->Name = L"налаштуванняToolStripMenuItem";
			this->налаштуванняToolStripMenuItem->Size = System::Drawing::Size(125, 26);
			this->налаштуванняToolStripMenuItem->Text = L"Налаштування";
			// 
			// mniReportFolder
			// 
			this->mniReportFolder->Name = L"mniReportFolder";
			this->mniReportFolder->Size = System::Drawing::Size(204, 26);
			this->mniReportFolder->Text = L"Папка для звітів";
			this->mniReportFolder->Click += gcnew System::EventHandler(this, &MyForm::mniReportFolder_Click);
			// 
			// tsQuickAccess
			// 
			this->tsQuickAccess->ImageScalingSize = System::Drawing::Size(20, 20);
			this->tsQuickAccess->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->tsBtnSave, this->tsBtnOpen,
					this->tsBtnReport, this->tsBtnRefresh, this->tsBtnExit
			});
			this->tsQuickAccess->Location = System::Drawing::Point(0, 30);
			this->tsQuickAccess->Name = L"tsQuickAccess";
			this->tsQuickAccess->Size = System::Drawing::Size(1247, 31);
			this->tsQuickAccess->TabIndex = 1;
			this->tsQuickAccess->Text = L"toolStrip1";
			// 
			// tsBtnSave
			// 
			this->tsBtnSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsBtnSave.Image")));
			this->tsBtnSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsBtnSave->Name = L"tsBtnSave";
			this->tsBtnSave->Size = System::Drawing::Size(29, 28);
			this->tsBtnSave->Text = L"toolStripButton1";
			this->tsBtnSave->ToolTipText = L"Зберегти звіт";
			this->tsBtnSave->Click += gcnew System::EventHandler(this, &MyForm::tsBtnSave_Click);
			// 
			// tsBtnOpen
			// 
			this->tsBtnOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsBtnOpen.Image")));
			this->tsBtnOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsBtnOpen->Name = L"tsBtnOpen";
			this->tsBtnOpen->Size = System::Drawing::Size(29, 28);
			this->tsBtnOpen->Text = L"toolStripButton1";
			this->tsBtnOpen->ToolTipText = L"Відкрити звіт";
			this->tsBtnOpen->Click += gcnew System::EventHandler(this, &MyForm::tsBtnOpen_Click);
			// 
			// tsBtnReport
			// 
			this->tsBtnReport->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnReport->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsBtnReport.Image")));
			this->tsBtnReport->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsBtnReport->Name = L"tsBtnReport";
			this->tsBtnReport->Size = System::Drawing::Size(29, 28);
			this->tsBtnReport->Text = L"toolStripButton1";
			this->tsBtnReport->ToolTipText = L"Вивести звіт";
			this->tsBtnReport->Click += gcnew System::EventHandler(this, &MyForm::tsBtnReport_Click);
			// 
			// tsBtnRefresh
			// 
			this->tsBtnRefresh->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnRefresh->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsBtnRefresh.Image")));
			this->tsBtnRefresh->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsBtnRefresh->Name = L"tsBtnRefresh";
			this->tsBtnRefresh->Size = System::Drawing::Size(29, 28);
			this->tsBtnRefresh->Text = L"toolStripButton1";
			this->tsBtnRefresh->ToolTipText = L"Оновити процеси";
			this->tsBtnRefresh->Click += gcnew System::EventHandler(this, &MyForm::tsBtnRefresh_Click);
			// 
			// tsBtnExit
			// 
			this->tsBtnExit->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnExit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsBtnExit.Image")));
			this->tsBtnExit->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsBtnExit->Name = L"tsBtnExit";
			this->tsBtnExit->Size = System::Drawing::Size(29, 28);
			this->tsBtnExit->Text = L"Вихід";
			this->tsBtnExit->Click += gcnew System::EventHandler(this, &MyForm::tsBtnExit_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 61);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1247, 601);
			this->panel1->TabIndex = 3;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->lvProcesses);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1247, 472);
			this->panel5->TabIndex = 4;
			// 
			// lvProcesses
			// 
			this->lvProcesses->Alignment = System::Windows::Forms::ListViewAlignment::SnapToGrid;
			this->lvProcesses->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lvProcesses->Font = (gcnew System::Drawing::Font(L"Tahoma", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lvProcesses->HideSelection = false;
			this->lvProcesses->Location = System::Drawing::Point(0, 0);
			this->lvProcesses->Name = L"lvProcesses";
			this->lvProcesses->Size = System::Drawing::Size(1247, 472);
			this->lvProcesses->TabIndex = 1;
			this->lvProcesses->UseCompatibleStateImageBehavior = false;
			this->lvProcesses->View = System::Windows::Forms::View::Tile;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->btnShowReport);
			this->panel2->Controls->Add(this->btnRefresh);
			this->panel2->Controls->Add(this->btnTerminate);
			this->panel2->Controls->Add(this->btProcessSearch);
			this->panel2->Controls->Add(this->lblProcess);
			this->panel2->Controls->Add(this->tbProcessName);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 472);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1247, 129);
			this->panel2->TabIndex = 3;
			// 
			// btnShowReport
			// 
			this->btnShowReport->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnShowReport->Location = System::Drawing::Point(769, 71);
			this->btnShowReport->Name = L"btnShowReport";
			this->btnShowReport->Size = System::Drawing::Size(240, 33);
			this->btnShowReport->TabIndex = 5;
			this->btnShowReport->Text = L"Показати звіт";
			this->btnShowReport->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btnShowReport->UseVisualStyleBackColor = true;
			this->btnShowReport->Click += gcnew System::EventHandler(this, &MyForm::btnShowReport_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRefresh->Location = System::Drawing::Point(408, 71);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(240, 33);
			this->btnRefresh->TabIndex = 2;
			this->btnRefresh->Text = L"Оновити";
			this->btnRefresh->UseVisualStyleBackColor = true;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &MyForm::btnRefresh_Click);
			// 
			// btnTerminate
			// 
			this->btnTerminate->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnTerminate->Location = System::Drawing::Point(69, 71);
			this->btnTerminate->Name = L"btnTerminate";
			this->btnTerminate->Size = System::Drawing::Size(242, 33);
			this->btnTerminate->TabIndex = 0;
			this->btnTerminate->Text = L"Завершити процес";
			this->btnTerminate->UseVisualStyleBackColor = true;
			this->btnTerminate->Click += gcnew System::EventHandler(this, &MyForm::btnTerminate_Click);
			// 
			// btProcessSearch
			// 
			this->btProcessSearch->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btProcessSearch->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btProcessSearch->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btProcessSearch->Location = System::Drawing::Point(769, 13);
			this->btProcessSearch->Name = L"btProcessSearch";
			this->btProcessSearch->Size = System::Drawing::Size(160, 31);
			this->btProcessSearch->TabIndex = 4;
			this->btProcessSearch->Text = L"Пошук";
			this->btProcessSearch->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btProcessSearch->UseVisualStyleBackColor = true;
			this->btProcessSearch->Click += gcnew System::EventHandler(this, &MyForm::btProcessSearch_Click);
			// 
			// lblProcess
			// 
			this->lblProcess->AutoSize = true;
			this->lblProcess->Font = (gcnew System::Drawing::Font(L"Tahoma", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblProcess->Location = System::Drawing::Point(65, 18);
			this->lblProcess->Name = L"lblProcess";
			this->lblProcess->Size = System::Drawing::Size(114, 21);
			this->lblProcess->TabIndex = 3;
			this->lblProcess->Text = L"Ім\'я процесу:";
			// 
			// tbProcessName
			// 
			this->tbProcessName->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbProcessName->Location = System::Drawing::Point(200, 16);
			this->tbProcessName->Name = L"tbProcessName";
			this->tbProcessName->Size = System::Drawing::Size(521, 28);
			this->tbProcessName->TabIndex = 2;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// openReportDialog
			// 
			this->openReportDialog->FileName = L"openReportDialog";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// statusStrip
			// 
			this->statusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tsStatusLabel, this->tsProgressBar });
			this->statusStrip->Location = System::Drawing::Point(0, 662);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(1247, 26);
			this->statusStrip->TabIndex = 2;
			this->statusStrip->Text = L"statusStrip";
			// 
			// tsStatusLabel
			// 
			this->tsStatusLabel->Name = L"tsStatusLabel";
			this->tsStatusLabel->Size = System::Drawing::Size(96, 20);
			this->tsStatusLabel->Text = L"tsStatusLabel";
			// 
			// tsProgressBar
			// 
			this->tsProgressBar->Name = L"tsProgressBar";
			this->tsProgressBar->Size = System::Drawing::Size(100, 18);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1247, 688);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->tsQuickAccess);
			this->Controls->Add(this->mnDropdown);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->mnDropdown;
			this->Name = L"MyForm";
			this->Text = L"TrackTime";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->mnDropdown->ResumeLayout(false);
			this->mnDropdown->PerformLayout();
			this->tsQuickAccess->ResumeLayout(false);
			this->tsQuickAccess->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void довідкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void файлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnTerminate_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void tsBtnExit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btProcessSearch_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnShowReport_Click(System::Object^ sender, System::EventArgs^ e);

public: delegate void dCompareProcesses();//порівнює процеси у системі та виведені у програмі
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	backgroundWorker1->WorkerSupportsCancellation = true;
	while (true)
	{
		if (backgroundWorker1->CancellationPending) //if it was cancelled
		{
			e->Cancel = true;
			break;
		}
		Sleep(100);
		dCompareProcesses^ d1 = gcnew dCompareProcesses(this, &MyForm::compareProcesses);
		/*try
		{
			this->Invoke(d1);
		}
		catch (Exception e)
		{
		}*/
		this->Invoke(d1);
		//dGetCurrentProcesses^ d1 = gcnew dGetCurrentProcesses(this, &MyForm::getCurrentProcesses);
		//dGetProcessesInProgram^ d2 = gcnew dGetProcessesInProgram(this, &MyForm::getProcesseInProgram);
		//dPressRefresh^ d3 = gcnew dPressRefresh(this, &MyForm::refresh);
		////dFindTime^ d4 = gcnew dFindTime(this, &MyForm::findTime);
		//this->Invoke(d1);
		//this->Invoke(d2);
		//String^ s = "ss";
		//currentProcesses->Contains(s);
		//if (currentProcesses->size() < processesInprogram->size()) {
		//	this->Invoke(d3);
		//	for (int i = 0; i < processesInprogram->size(); i++) {
		//		if (currentProcesses->Contains()) {

		//		}
		//	}
		//}
		//this->Invoke(d, "9999999999999999999");
		//backgroundWorker1->ReportProgress(10);  //reporting progress
	}
}
 
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	backgroundWorker1->CancelAsync();
}

private: System::Void compareProcesses();

public:static std::string& convert_String_to_string(String^ s, std::string& os);
public:static  String^ convert_string_to_String(std::string os, String^ &s);
public: static std::map < std::string, long long> Project1::MyForm::getProcessesAndTime();
public: static System::Void CountProcessesTime();
public: static System::Void saveReport();
public: static System::Void openReport();
private: System::Void mniSave_Click(System::Object^ sender, System::EventArgs^ e);
public: static System::Void tokenize(std::string const& str, const char delim, std::vector<std::string>& out);
public: static std::map < std::string, long long> Project1::MyForm::getDataFromReport();


private: System::Void mniOpen_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void mniReportFolder_Click(System::Object^ sender, System::EventArgs^ e);
private: bool is_empty(std::ifstream& pFile);
private: System::Void emulateProgress();

private: System::Void tsBtnSave_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tsBtnOpen_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tsBtnReport_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tsBtnRefresh_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void mniAbout_Click(System::Object^ sender, System::EventArgs^ e);

};
}
