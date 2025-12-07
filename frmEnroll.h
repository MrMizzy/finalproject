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
	/// Summary for frmEnroll
	/// </summary>
	public ref class frmEnroll : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306;username=root; password=''; database=ashesi_arms";
		User^ currentUser = nullptr;
		int studentID = 0;
	private: System::Windows::Forms::ComboBox^ enrollCombo;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnFind;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Button^ btnEnroll;
	private: System::Windows::Forms::Label^ label8;
	public:
		frmEnroll(User^ user)
		{
			InitializeComponent();
			currentUser = user;
			if (user->roleNum != 2) {
				/*Load all courses that exist*/
				LoadAllCourses();
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				DataTable^ dt = gcnew DataTable();
				MySqlCommand^ sqlCmd = gcnew MySqlCommand();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT c.course_name, e.grade FROM enrollments e JOIN course c ON c.course_id = e.course_id JOIN student s ON s.student_id = e.student_id";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sqlCmd);
				da->Fill(dt);
				dataGridView1->DataSource = dt;
				dataGridView1->Columns[0]->Width = 100;
				dataGridView1->Columns[1]->Width = 50;
				sqlCmd->Cancel();
				sqlConn->Close();
			}
			else
			{
				/*Load only courses that the student is not enrolled in and is in their programme*/ 
				studentID = user->id;
				txtFind->Enabled = false;
				btnFind->Enabled = false;
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT u.email FROM user u WHERE u.uid = @studentID";
				sqlCmd->Parameters->AddWithValue("@studentID", studentID);
				sqlDR = sqlCmd->ExecuteReader();
				if (sqlDR->Read()) {
					String^ studentEmail = sqlDR["email"]->ToString();
					sqlDR->Close();
					sqlCmd->Parameters->Clear();
					txtFind->Text = studentEmail;
				}
				else {
					sqlDR->Close();
					sqlCmd->Cancel();
					sqlConn->Close();
					MessageBox::Show("Student record not found", "Data Load Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					this->Close();
				}
				LoadPossibleEnrolls();
				LoadStudentData();
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEnroll()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->enrollCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnEnroll = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(341, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 31);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Enroll";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label6->Location = System::Drawing::Point(35, 53);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(131, 26);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Course Title:";
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(625, 408);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(111, 32);
			this->btnCancel->TabIndex = 22;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmEnroll::btnCancel_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(40, 130);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(695, 270);
			this->panel1->TabIndex = 26;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(696, 270);
			this->dataGridView1->TabIndex = 0;
			// 
			// enrollCombo
			// 
			this->enrollCombo->FormattingEnabled = true;
			this->enrollCombo->Location = System::Drawing::Point(202, 53);
			this->enrollCombo->Name = L"enrollCombo";
			this->enrollCombo->Size = System::Drawing::Size(533, 24);
			this->enrollCombo->TabIndex = 27;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label2->Location = System::Drawing::Point(35, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(207, 26);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Current Enrollments:";
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(501, 408);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(111, 32);
			this->btnFind->TabIndex = 31;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmEnroll::btnFind_Click);
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(284, 412);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(211, 22);
			this->txtFind->TabIndex = 30;
			this->txtFind->TextChanged += gcnew System::EventHandler(this, &frmEnroll::txtFind_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(34, 412);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(244, 26);
			this->label8->TabIndex = 29;
			this->label8->Text = L"Find Student with Email:";
			// 
			// btnEnroll
			// 
			this->btnEnroll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnEnroll->Location = System::Drawing::Point(624, 97);
			this->btnEnroll->Name = L"btnEnroll";
			this->btnEnroll->Size = System::Drawing::Size(111, 32);
			this->btnEnroll->TabIndex = 32;
			this->btnEnroll->Text = L"Enroll";
			this->btnEnroll->UseVisualStyleBackColor = true;
			this->btnEnroll->Click += gcnew System::EventHandler(this, &frmEnroll::btnEnroll_Click);
			// 
			// frmEnroll
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(762, 452);
			this->Controls->Add(this->btnEnroll);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->enrollCombo);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Name = L"frmEnroll";
			this->Text = L"Enroll";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void LoadData() {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			DataTable^ dt = gcnew DataTable();
			MySqlCommand^ sqlCmd = gcnew MySqlCommand();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT c.course_name, e.grade FROM enrollments e JOIN course c ON c.course_id = e.course_id JOIN student s ON s.student_id = e.student_id WHERE s.student_id = @uid";
			sqlCmd->Parameters->AddWithValue("@uid", studentID);
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sqlCmd);
			da->Fill(dt);
			dataGridView1->DataSource = dt;
			dataGridView1->Columns[0]->Width = 100;
			dataGridView1->Columns[1]->Width = 50;
			sqlCmd->Cancel();
			sqlConn->Close();
		}
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		void LoadStudentData() {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			DataTable^ dt = gcnew DataTable();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT u.f_name, u.l_name, u.email FROM user u JOIN student s ON u.uid = s.student_id", sqlConn);
			da->Fill(dt);

			dataGridView1->DataSource = dt;
			dataGridView1->Columns[0]->Width = 100;
			dataGridView1->Columns[1]->Width = 100;
			dataGridView1->Columns[2]->Width = 200;
			sqlConn->Close();
		}
		System::Void LoadPossibleEnrolls() {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT c.course_name FROM course c JOIN programme p ON p.programme_id = c.programme_id JOIN student s ON s.programme_id = p.programme_id WHERE c.course_id NOT IN (SELECT course_id FROM enrollments WHERE student_id = @uid)";
			sqlCmd->Parameters->AddWithValue("@uid", studentID);
			sqlDR = sqlCmd->ExecuteReader();
			enrollCombo->Items->Clear();
			while (sqlDR->Read()) {
				String^ courseName = sqlDR["course_name"]->ToString();
				enrollCombo->Items->Add(courseName);
			}
			sqlDR->Close();
			sqlConn->Close();
		}
		System::Void LoadAllCourses(){
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT course_name FROM course";
			sqlDR = sqlCmd->ExecuteReader();
			sqlCmd->Parameters->Clear();
			enrollCombo->Items->Clear();
			while (sqlDR->Read()) {
				String^ courseName = sqlDR["course_name"]->ToString();
				enrollCombo->Items->Add(courseName);
			}
			sqlDR->Close();
			sqlConn->Close();
		}
		System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ email = txtFind->Text->Trim();
			if (email->Length == 0) {
				MessageBox::Show("Please enter an email", "Input Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT u.uid FROM user u WHERE u.email = @email";
			sqlCmd->Parameters->AddWithValue("@email", email);
			sqlDR = sqlCmd->ExecuteReader();
			sqlCmd->Parameters->Clear();
			if (sqlDR->Read()) {
				studentID = Convert::ToInt32(sqlDR["uid"]);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				LoadData();
				LoadAllCourses();
				MessageBox::Show("Student record found", "Data Load",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				MessageBox::Show("Student record not found", "Data Load Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			sqlDR->Close();
		}
		System::Void btnEnroll_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ courseName = enrollCombo->Text;
			if (courseName->Length == 0) {
				MessageBox::Show("Please select a course to enroll in", "Input Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			if (sqlDR != nullptr) {
				sqlDR->Close();
			}
			if (studentID == 0) {
				MessageBox::Show("Please find a student first", "Input Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT c.course_id FROM course c WHERE c.course_name = @cname";
			sqlCmd->Parameters->AddWithValue("@cname", courseName);
			sqlDR = sqlCmd->ExecuteReader();
			int courseID = 0;
			if (sqlDR->Read()) {
				courseID = Convert::ToInt32(sqlDR["course_id"]);
			}
			sqlDR->Close();
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT * FROM enrollments WHERE student_id = @uid AND course_id = @cid";
			sqlCmd->Parameters->AddWithValue("@uid", studentID);
			sqlCmd->Parameters->AddWithValue("@cid", courseID);
			sqlDR = sqlCmd->ExecuteReader();
			if (sqlDR->Read()) {
				MessageBox::Show("Student is already enrolled in this course", "Enrollment Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				return;
			}
			sqlDR->Close();
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "INSERT INTO enrollments(student_id, course_id, grade) " +
				"VALUES(@uid, @cid, NULL)";
			sqlCmd->Parameters->AddWithValue("@uid", studentID);
			sqlCmd->Parameters->AddWithValue("@cid", courseID);
			sqlCmd->ExecuteNonQuery();
			sqlCmd->Cancel();
			sqlConn->Close();
			MessageBox::Show("Enrollment Successful", "Enrollment");
			LoadData();
		}
private: System::Void txtFind_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
