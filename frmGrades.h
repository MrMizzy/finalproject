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
	/// Summary for frmGrades
	/// </summary>
	public ref class frmGrades : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306;username=root; password=''; database=ashesimis";
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnFind;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ courseCombo;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ gradeCombo;
		   int selectedStudentID = 0;
	public:

		frmGrades(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			txtName->Enabled = false;
			LoadStudentData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ btnUpdate;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->courseCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->gradeCombo = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(162, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student\'s Name:";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(219, 52);
			this->txtName->Multiline = true;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(605, 34);
			this->txtName->TabIndex = 1;
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(584, 143);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(111, 32);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmGrades::btnUpdate_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(712, 143);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(111, 32);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmGrades::btnCancel_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(221, 181);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(603, 286);
			this->panel1->TabIndex = 6;
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(604, 286);
			this->dataGridView1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(439, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(199, 31);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Manage Grades";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(714, 491);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(111, 32);
			this->btnFind->TabIndex = 35;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmGrades::btnFind_Click);
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(371, 498);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(337, 22);
			this->txtFind->TabIndex = 34;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(121, 495);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(244, 26);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Find Student with Email:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(30, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 26);
			this->label3->TabIndex = 36;
			this->label3->Text = L"Course Name:";
			// 
			// courseCombo
			// 
			this->courseCombo->FormattingEnabled = true;
			this->courseCombo->Location = System::Drawing::Point(219, 100);
			this->courseCombo->Name = L"courseCombo";
			this->courseCombo->Size = System::Drawing::Size(604, 24);
			this->courseCombo->TabIndex = 37;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(100, 138);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 26);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Grade:";
			// 
			// gradeCombo
			// 
			this->gradeCombo->FormattingEnabled = true;
			this->gradeCombo->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"A+", L"A", L"B+", L"B", L"C+", L"C", L"D+",
					L"D", L"E", L"None"
			});
			this->gradeCombo->Location = System::Drawing::Point(221, 143);
			this->gradeCombo->Name = L"gradeCombo";
			this->gradeCombo->Size = System::Drawing::Size(110, 24);
			this->gradeCombo->TabIndex = 39;
			// 
			// frmGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(909, 532);
			this->Controls->Add(this->gradeCombo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->courseCombo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->label1);
			this->Name = L"frmGrades";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Manage Grades";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ emailToFind = txtFind->Text->Trim();
		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT * FROM user where email = @email";
			sqlCmd->Parameters->AddWithValue("@email", emailToFind);
			sqlDR = sqlCmd->ExecuteReader();
			if (sqlDR->Read()) {
				MessageBox::Show("Student Found");
				selectedStudentID = Convert::ToInt32(sqlDR["uid"]);
				txtName->Text = sqlDR["f_name"]->ToString() + " " + sqlDR["l_name"]->ToString();
				LoadGradeData(selectedStudentID);
				LoadCourseNames(selectedStudentID);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
			}
			else {
				MessageBox::Show("The student does not exist", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Date Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			sqlDR->Close();
			sqlCmd->Cancel();
			sqlConn->Close();
			return;
		}
	}
	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = txtName->Text->Trim();
		String^ course = courseCombo->Text;
		String^ grade = gradeCombo->Text;
		if (name == "") {
			MessageBox::Show("Please Find a Student first", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (course == "") {
			MessageBox::Show("Please Select a Course", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (grade == "") {
			MessageBox::Show("Please Select a Grade", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (sqlConn->State == ConnectionState::Open) {
			sqlConn->Close();
		}
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "UPDATE enrollments SET grade = @grade WHERE student_id = @sid AND course_id = (SELECT course_id from course where course_name = @course)";
			sqlCmd->Parameters->AddWithValue("@grade", grade);
			sqlCmd->Parameters->AddWithValue("@sid", selectedStudentID);
			sqlCmd->Parameters->AddWithValue("@course", course);
			sqlCmd->ExecuteNonQuery();
			MessageBox::Show("Update is successful");
			LoadGradeData(selectedStudentID);
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
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
		   void LoadGradeData(int sid) {
			   if (sqlConn->State == ConnectionState::Open) {
				   sqlConn->Close();
			   }
			   sqlConn->ConnectionString = ConnectionStr;
			   sqlConn->Open();
			   sqlCmd->Connection = sqlConn;
			   sqlCmd->Parameters->Clear();
			   sqlCmd->CommandText = "SELECT c.course_name, e.grade FROM enrollments e JOIN course c ON e.course_id = c.course_id WHERE e.student_id = @sid";
			   sqlCmd->Parameters->AddWithValue("@sid", sid);
			   sqlDR = sqlCmd->ExecuteReader();
			   DataTable^ dt = gcnew DataTable();
			   dt->Load(sqlDR);
			   dataGridView1->DataSource = dt;
			   dataGridView1->Columns[0]->Width = 200;
			   dataGridView1->Columns[1]->Width = 100;
			   sqlDR->Close();
			   sqlConn->Close();
		   }
		   void LoadCourseNames(int sid) {
			   if (sqlConn->State == ConnectionState::Open) {
				   sqlConn->Close();
			   }
			   sqlConn->ConnectionString = ConnectionStr;
			   sqlConn->Open();
			   sqlCmd->Connection = sqlConn;
			   sqlCmd->Parameters->Clear();
			   sqlCmd->CommandText = "SELECT c.course_name FROM enrollments e JOIN course c ON e.course_id = c.course_id WHERE e.student_id = @sid";
			   sqlCmd->Parameters->AddWithValue("@sid", sid);
			   sqlDR = sqlCmd->ExecuteReader();
			   courseCombo->Items->Clear();
			   while (sqlDR->Read()) {
				   String^ courseName = sqlDR["course_name"]->ToString();
				   courseCombo->Items->Add(courseName);
			   }
		   }
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
