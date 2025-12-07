#pragma once
#include "user.h"
#include "newfrmRegister.h"
namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for newfrmLogin
	/// </summary>
	public ref class newfrmLogin : public System::Windows::Forms::Form
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


	public:
		User^ user = gcnew User();

		newfrmLogin(void)
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
		~newfrmLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtEmail;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtPassword;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnCancel;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(newfrmLogin::typeid));
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->txtEmail->Location = System::Drawing::Point(460, 180);
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
			this->label1->Location = System::Drawing::Point(339, 180);
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
			this->label2->Location = System::Drawing::Point(339, 242);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->txtPassword->Location = System::Drawing::Point(460, 242);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(369, 34);
			this->txtPassword->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(472, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 56);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Login";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnLogin
			// 
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnLogin->Location = System::Drawing::Point(460, 307);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(138, 43);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &newfrmLogin::btnLogin_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnCancel->Location = System::Drawing::Point(691, 307);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(138, 43);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &newfrmLogin::btnCancel_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(-2, -9);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(335, 511);
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
			this->label4->Size = System::Drawing::Size(260, 159);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Ashesi Learning Management System";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(40, 55);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(243, 230);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// newfrmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(852, 502);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtEmail);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"newfrmLogin";
			this->Text = L"Ashesi MIS";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = txtEmail->Text->Trim();
		String^ password = txtPassword->Text->Trim();

		if (email->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter email and password", "", MessageBoxButtons::OK);
			return;
		}

		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM user where email=@email AND password=@pwd";
			sqlCmd->Parameters->AddWithValue("@email", email);
			sqlCmd->Parameters->AddWithValue("@pwd", password);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				user->id = Convert::ToInt32(sqlDR["uid"]);
				user->fName = sqlDR["f_name"]->ToString();
				user->lName = sqlDR["l_name"]->ToString();
				user->email = sqlDR["email"]->ToString();
				user->password = sqlDR["password"]->ToString();
				user->roleNum = Convert::ToInt32(sqlDR["role"]);

				MessageBox::Show("Hello " + sqlDR["f_name"]);
				this->Close();
			}
			else {
				MessageBox::Show("Email or Password is incorrect", "", MessageBoxButtons::OK);
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
