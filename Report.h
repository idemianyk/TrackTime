#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Report
	/// </summary>
	public ref class Report : public System::Windows::Forms::Form
	{
	public:
		Report(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Report()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ListView^ lvProceses;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txtbxSearchProcess;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSearchProcess;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ tsBtnClose;



	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Report::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lvProceses = (gcnew System::Windows::Forms::ListView());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txtbxSearchProcess = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSearchProcess = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->tsBtnClose = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->toolStrip1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1299, 27);
			this->panel1->TabIndex = 0;
			// 
			// lvProceses
			// 
			this->lvProceses->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lvProceses->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lvProceses->HideSelection = false;
			this->lvProceses->Location = System::Drawing::Point(0, 0);
			this->lvProceses->Name = L"lvProceses";
			this->lvProceses->Size = System::Drawing::Size(1299, 623);
			this->lvProceses->TabIndex = 0;
			this->lvProceses->UseCompatibleStateImageBehavior = false;
			this->lvProceses->View = System::Windows::Forms::View::Tile;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->lvProceses);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 27);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1299, 623);
			this->panel2->TabIndex = 1;
			// 
			// txtbxSearchProcess
			// 
			this->txtbxSearchProcess->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtbxSearchProcess->Location = System::Drawing::Point(151, 63);
			this->txtbxSearchProcess->Name = L"txtbxSearchProcess";
			this->txtbxSearchProcess->Size = System::Drawing::Size(258, 28);
			this->txtbxSearchProcess->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(22, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 21);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ім\'я процесу:";
			// 
			// btnSearchProcess
			// 
			this->btnSearchProcess->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSearchProcess->Location = System::Drawing::Point(458, 63);
			this->btnSearchProcess->Name = L"btnSearchProcess";
			this->btnSearchProcess->Size = System::Drawing::Size(156, 28);
			this->btnSearchProcess->TabIndex = 4;
			this->btnSearchProcess->Text = L"Пошук";
			this->btnSearchProcess->UseVisualStyleBackColor = true;
			this->btnSearchProcess->Click += gcnew System::EventHandler(this, &Report::btnSearchProcess_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->txtbxSearchProcess);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->btnSearchProcess);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 508);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1299, 142);
			this->panel3->TabIndex = 1;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tsBtnClose });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1299, 27);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// tsBtnClose
			// 
			this->tsBtnClose->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsBtnClose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsBtnClose.Image")));
			this->tsBtnClose->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsBtnClose->Name = L"tsBtnClose";
			this->tsBtnClose->Size = System::Drawing::Size(29, 24);
			this->tsBtnClose->Text = L"toolStripButton1";
			this->tsBtnClose->Click += gcnew System::EventHandler(this, &Report::tsBtnClose_Click);
			// 
			// Report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1299, 650);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Report";
			this->Text = L"Звіт";
			this->Load += gcnew System::EventHandler(this, &Report::Report_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Report_Load(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void btnSearchProcess_Click(System::Object^ sender, System::EventArgs^ e);
public: System::Void printFromFile();

private: System::Void tsBtnClose_Click(System::Object^ sender, System::EventArgs^ e);
};
}
