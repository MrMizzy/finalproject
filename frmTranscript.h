#pragma once
#include "user.h"
using namespace System::IO;

namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmTranscript
	/// </summary>
	public ref class frmTranscript : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306;username=root; password=''; database=ashesi_arms";
		User^ currentUser = nullptr;
		int studentID = 0;
		String^ studentName = "";

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Label^ lblGPA;
	private: System::Windows::Forms::Label^ lblStudentInfo;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnFind;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ btnDownload;

	public:
		frmTranscript() {
			InitializeComponent();
		}
	public:
		frmTranscript(User^ user)
		{
			InitializeComponent();
			currentUser = user;

			if (user->roleNum == 0) {
				label8->Visible = true;
				txtFind->Visible = true;
				btnFind->Visible = true;

				lblStudentInfo->Text = "Student: Please search for a student.";
				lblGPA->Text = "GPA: N/A";
				btnDownload->Enabled = false;
			}
			else if (user->roleNum == 2) {
				label8->Visible = false;
				txtFind->Visible = false;
				btnFind->Visible = false;

				studentID = user->id;
				GetStudentInfo(studentID);
				LoadTranscriptData(studentID);
				btnDownload->Enabled = true;
			}

			else if (user->roleNum == 1) {
				MessageBox::Show("Faculty members do not have permission to view transcripts.", "Permission Denied",
					MessageBoxButtons::OK, MessageBoxIcon::Stop);
				this->Close();
				return;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmTranscript()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lblGPA = (gcnew System::Windows::Forms::Label());
			this->lblStudentInfo = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnDownload = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(300, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Transcript";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(35, 172);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(696, 250);
			this->dataGridView1->TabIndex = 1;
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(620, 439);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(111, 32);
			this->btnCancel->TabIndex = 23;
			this->btnCancel->Text = L"Close";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmTranscript::btnCancel_Click);
			// 
			// lblGPA
			// 
			this->lblGPA->AutoSize = true;
			this->lblGPA->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->lblGPA->Location = System::Drawing::Point(35, 137);
			this->lblGPA->Name = L"lblGPA";
			this->lblGPA->Size = System::Drawing::Size(100, 26);
			this->lblGPA->TabIndex = 24;
			this->lblGPA->Text = L"GPA: N/A";
			// 
			// lblStudentInfo
			// 
			this->lblStudentInfo->AutoSize = true;
			this->lblStudentInfo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->lblStudentInfo->Location = System::Drawing::Point(35, 54);
			this->lblStudentInfo->Name = L"lblStudentInfo";
			this->lblStudentInfo->Size = System::Drawing::Size(199, 26);
			this->lblStudentInfo->TabIndex = 25;
			this->lblStudentInfo->Text = L"Student: Loading...";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(34, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(223, 26);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Enrollments Record:";
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(620, 54);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(111, 32);
			this->btnFind->TabIndex = 34;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmTranscript::btnFind_Click);
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(403, 58);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(211, 22);
			this->txtFind->TabIndex = 33;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(34, 54);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(244, 26);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Find Student with Email:";
			// 
			// btnDownload
			// 
			this->btnDownload->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDownload->Location = System::Drawing::Point(475, 439);
			this->btnDownload->Name = L"btnDownload";
			this->btnDownload->Size = System::Drawing::Size(139, 32);
			this->btnDownload->TabIndex = 35;
			this->btnDownload->Text = L"Download";
			this->btnDownload->UseVisualStyleBackColor = true;
			this->btnDownload->Click += gcnew System::EventHandler(this, &frmTranscript::btnDownload_Click);
			// 
			// frmTranscript
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(762, 483);
			this->Controls->Add(this->btnDownload);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblStudentInfo);
			this->Controls->Add(this->lblGPA);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Name = L"frmTranscript";
			this->Text = L"Transcript";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void GetStudentInfo(int uID) {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT u.email, CONCAT(u.f_name, ' ', u.l_name) AS student_name " +
				"FROM user u JOIN student s ON u.uid = s.student_id WHERE u.uid = @uid";
			sqlCmd->Parameters->AddWithValue("@uid", uID);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				studentName = sqlDR["student_name"]->ToString();
				String^ studentEmail = sqlDR["email"]->ToString();
				lblStudentInfo->Text = "Student: " + studentName + " (" + studentEmail + ")";
			}
			else {
				lblStudentInfo->Text = "Student: Record Not Found";
			}
			sqlDR->Close();
			sqlConn->Close();
		}

		System::Void LoadTranscriptData(int uID) {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			String^ query = "SELECT c.course_code, c.course_name, c.credit AS credit_hours, e.grade " +
				"FROM enrollments e JOIN course c ON c.course_id = e.course_id " +
				"WHERE e.student_id = @uid ORDER BY c.course_code";

			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = query;
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@uid", uID);

			DataTable^ dt = gcnew DataTable();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sqlCmd);
			da->Fill(dt);

			double gpa = CalculateGPA(dt);

			dataGridView1->DataSource = dt;

			dataGridView1->Columns["course_code"]->HeaderText = "Code";
			dataGridView1->Columns["course_name"]->HeaderText = "Course Title";
			dataGridView1->Columns["credit_hours"]->HeaderText = "Credits";
			dataGridView1->Columns["grade"]->HeaderText = "Grade";

			dataGridView1->Columns["course_code"]->Width = 80;
			dataGridView1->Columns["course_name"]->Width = 300;
			dataGridView1->Columns["credit_hours"]->Width = 80;
			dataGridView1->Columns["grade"]->Width = 80;

			lblGPA->Text = "GPA: " + gpa.ToString("F2");

			sqlConn->Close();
		}

		double GetGradePoint(String^ grade) {
			if (grade == nullptr) return 0.0;
			String^ normalizedGrade = grade->Trim()->ToUpper();

			if (normalizedGrade == "A+") return 4.0;
			if (normalizedGrade == "A") return 4.0;
			if (normalizedGrade == "A-") return 3.7;
			if (normalizedGrade == "B+") return 3.3;
			if (normalizedGrade == "B") return 3.0;
			if (normalizedGrade == "B-") return 2.7;
			if (normalizedGrade == "C+") return 2.3;
			if (normalizedGrade == "C") return 2.0;
			if (normalizedGrade == "C-") return 1.7;
			if (normalizedGrade == "D+") return 1.3;
			if (normalizedGrade == "D") return 1.0;

			return 0.0;
		}


		double CalculateGPA(DataTable^ enrollmentData) {
			double totalQualityPoints = 0.0;
			int totalCreditHours = 0;

			for each (DataRow ^ row in enrollmentData->Rows) {

				String^ grade = row["grade"]->ToString();
				int creditHours = Convert::ToInt32(row["credit_hours"]);

				if (grade != nullptr && grade->Trim()->Length > 0 && grade != "None") {
					double gradePoint = GetGradePoint(grade);
					totalQualityPoints += gradePoint * creditHours;
					totalCreditHours += creditHours;
				}
			}

			if (totalCreditHours > 0) {
				return totalQualityPoints / totalCreditHours;
			}
			return 0.0;
		}

		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ email = txtFind->Text->Trim();
			if (email->Length == 0) {
				MessageBox::Show("Please enter a student email to search.", "Input Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();

			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "SELECT u.uid FROM user u WHERE u.email = @email AND u.role = 2";
			sqlCmd->Parameters->AddWithValue("@email", email);
			sqlDR = sqlCmd->ExecuteReader();

			if (sqlDR->Read()) {
				studentID = Convert::ToInt32(sqlDR["uid"]);
				sqlDR->Close();
				sqlConn->Close();

				GetStudentInfo(studentID); 
				LoadTranscriptData(studentID);

				btnDownload->Enabled = true;

				MessageBox::Show("Student transcript loaded successfully.", "Search Successful",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				sqlDR->Close();
				sqlConn->Close();
				studentID = 0;
				lblStudentInfo->Text = "Student: Email Not Found";
				lblGPA->Text = "GPA: N/A";
				dataGridView1->DataSource = nullptr;
				MessageBox::Show("Student record not found or user is not a student.", "Data Load Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		System::Void btnDownload_Click(System::Object^ sender, System::EventArgs^ e) {
			if (studentID == 0) {
				MessageBox::Show("Please select or find a student first to generate a transcript.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();

			saveFileDialog1->FileName = "Transcript_" + studentName->Replace(" ", "_") + ".txt";
			saveFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			saveFileDialog1->Title = "Save Transcript File";

			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

				String^ filePath = saveFileDialog1->FileName;

				try {

					StreamWriter^ writer = gcnew StreamWriter(filePath);


					writer->WriteLine("             OFFICIAL ACADEMIC TRANSCRIPT           ");
					writer->WriteLine(" ");
					writer->WriteLine(lblStudentInfo->Text);
					writer->WriteLine(lblGPA->Text);
					writer->WriteLine(" ");
					writer->WriteLine("Enrollments Record:");

					DataTable^ dt = (DataTable^)dataGridView1->DataSource;

					writer->WriteLine(String::Format("{0,-10} {1,-35} {2,-10} {3,-5}",
						"CODE", "COURSE TITLE", "CREDITS", "GRADE"));
					writer->WriteLine(" ");

					for each (DataRow ^ row in dt->Rows)
					{
						String^ courseCode = row["course_code"]->ToString();
						String^ courseName = row["course_name"]->ToString();
						String^ creditHours = row["credit_hours"]->ToString();
						String^ grade = row["grade"]->ToString();

						writer->WriteLine(String::Format("{0,-10} {1,-35} {2,-10} {3,-5}",
							courseCode, courseName, creditHours, grade));
					}

					writer->WriteLine(" ");

					writer->Close();

					MessageBox::Show("Transcript saved successfully to:\n" + filePath,
						"Download Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);

				}
				catch (Exception^ ex) {
					MessageBox::Show("An error occurred while saving the file: " + ex->Message,
						"File Save Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	};
}