#pragma once
#include "user.h"
namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmRegFac
	/// </summary>
	public ref class frmRegFac : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306; username=root; password=""; database=ashesi_arms;";
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtFName;
	private: System::Windows::Forms::TextBox^ txtLName;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ deptCombo;
	public:
		User^ user = gcnew User();

		frmRegFac(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegFac()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnCancel;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmRegFac::typeid));
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtFName = (gcnew System::Windows::Forms::TextBox());
			this->txtLName = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->deptCombo = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->txtEmail->Location = System::Drawing::Point(471, 228);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(369, 34);
			this->txtEmail->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Location = System::Drawing::Point(318, 231);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Email:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14));
			this->label2->Location = System::Drawing::Point(318, 290);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->txtPassword->Location = System::Drawing::Point(471, 290);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(369, 34);
			this->txtPassword->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(465, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 56);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Register";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnRegister->Location = System::Drawing::Point(401, 409);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(138, 43);
			this->btnRegister->TabIndex = 5;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &frmRegFac::btnRegister_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnCancel->Location = System::Drawing::Point(645, 409);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(138, 43);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmRegFac::btnCancel_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(-2, -9);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(303, 511);
			this->panel1->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(34, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(228, 159);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Ashesi Learning Management System";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(19, 55);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(243, 230);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label5->Location = System::Drawing::Point(318, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(130, 32);
			this->label5->TabIndex = 8;
			this->label5->Text = L"First Name:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label6->Location = System::Drawing::Point(318, 172);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(130, 32);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Last Name:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtFName
			// 
			this->txtFName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->txtFName->Location = System::Drawing::Point(471, 115);
			this->txtFName->Name = L"txtFName";
			this->txtFName->Size = System::Drawing::Size(369, 34);
			this->txtFName->TabIndex = 10;
			// 
			// txtLName
			// 
			this->txtLName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->txtLName->Location = System::Drawing::Point(471, 170);
			this->txtLName->Name = L"txtLName";
			this->txtLName->Size = System::Drawing::Size(369, 34);
			this->txtLName->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label7->Location = System::Drawing::Point(318, 346);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(141, 32);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Department:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// deptCombo
			// 
			this->deptCombo->FormattingEnabled = true;
			this->deptCombo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Admin", L"Faculty", L"Student" });
			this->deptCombo->Location = System::Drawing::Point(470, 347);
			this->deptCombo->Name = L"deptCombo";
			this->deptCombo->Size = System::Drawing::Size(369, 24);
			this->deptCombo->TabIndex = 13;
			// 
			// frmRegFac
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(852, 502);
			this->Controls->Add(this->deptCombo);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txtLName);
			this->Controls->Add(this->txtFName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtEmail);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmRegFac";
			this->Text = L"Register Faculty";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname = txtFName->Text->Trim();
		String^ lname = txtLName->Text->Trim();
		String^ email = txtEmail->Text->Trim();
		String^ password = txtPassword->Text->Trim();
		String^ dept = deptCombo->SelectedItem->ToString();
		if (fname->Length == 0 || lname->Length == 0 || email->Length == 0 || password->Length == 0 || dept->Length == 0) {
			MessageBox::Show("Please fill all fields", "", MessageBoxButtons::OK);
			return;
		}

		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "INSERT INTO user VALUES (@fname, @lname, @email, @pwd, @role)";
			sqlCmd->Parameters->AddWithValue("@fname", fname);
			sqlCmd->Parameters->AddWithValue("@lname", lname);
			sqlCmd->Parameters->AddWithValue("@email", email);
			sqlCmd->Parameters->AddWithValue("@pwd", password);
			sqlCmd->Parameters->AddWithValue("@role", 1); // 1 for faculty
			if (sqlCmd->ExecuteNonQuery() == 1) {
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "INSERT INTO faculty (user_id, department_id) VALUES ((SELECT u.id FROM user u WHERE u.email = @email), (SELECT d.department_id from department d WHERE d.dept_name = @dept))";
				sqlCmd->Parameters->AddWithValue("@email", email);
				sqlCmd->Parameters->AddWithValue("@dept", dept);
				if (sqlCmd->ExecuteNonQuery() == 1) {
					MessageBox::Show("Registration Successful", "", MessageBoxButtons::OK);
					this->Close();
				}
				else {
					MessageBox::Show("Registration Failed at faculty table. Please try again", "", MessageBoxButtons::OK);
					return;
				}
			}
			else {
				MessageBox::Show("Registration Failed. Please try again", "", MessageBoxButtons::OK);
				return;
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to connect to database " + e->Message,
				"Data Base Error Connection", MessageBoxButtons::OK);
		}
	}
	};
}