#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RichTextBox^ AboutProgram;
	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::RichTextBox^ txtbxAboutAuthor;
	private: System::Windows::Forms::Button^ btnOk;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(About::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtbxAboutAuthor = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->AboutProgram = (gcnew System::Windows::Forms::RichTextBox());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnOk);
			this->panel1->Controls->Add(this->txtbxAboutAuthor);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->AboutProgram);
			this->panel1->Location = System::Drawing::Point(2, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(731, 443);
			this->panel1->TabIndex = 0;
			// 
			// txtbxAboutAuthor
			// 
			this->txtbxAboutAuthor->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtbxAboutAuthor->Location = System::Drawing::Point(206, 19);
			this->txtbxAboutAuthor->Name = L"txtbxAboutAuthor";
			this->txtbxAboutAuthor->ReadOnly = true;
			this->txtbxAboutAuthor->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->txtbxAboutAuthor->Size = System::Drawing::Size(466, 120);
			this->txtbxAboutAuthor->TabIndex = 2;
			this->txtbxAboutAuthor->Text = L"";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(29, 11);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(171, 158);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// AboutProgram
			// 
			this->AboutProgram->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AboutProgram->Location = System::Drawing::Point(29, 175);
			this->AboutProgram->Name = L"AboutProgram";
			this->AboutProgram->ReadOnly = true;
			this->AboutProgram->Size = System::Drawing::Size(638, 176);
			this->AboutProgram->TabIndex = 0;
			this->AboutProgram->Text = L"";
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(245, 375);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(231, 34);
			this->btnOk->TabIndex = 3;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &About::btnOk_Click);
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 447);
			this->Controls->Add(this->panel1);
			this->Name = L"About";
			this->Text = L"About";
			this->Load += gcnew System::EventHandler(this, &About::About_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void About_Load(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e);
};
}
