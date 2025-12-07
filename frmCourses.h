#pragma once

namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for frmCourses
	/// </summary>
	public ref class frmCourses : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306;username=root; password=''; database=ashesimis";
		int globalCourseID = 0;
	public:
		frmCourses(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LoadProgrammes();
			LoadLevels();
			LoadSemesters();
			LoadCredits();
			LoadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboPrgm;
	private: System::Windows::Forms::ComboBox^ comboLvl;
	private: System::Windows::Forms::ComboBox^ comboSem;
	private: System::Windows::Forms::ComboBox^ comboCred;
	private: System::Windows::Forms::TextBox^ txtCode;
	private: System::Windows::Forms::TextBox^ txtTitle;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnFind;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Label^ label8;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboPrgm = (gcnew System::Windows::Forms::ComboBox());
			this->comboLvl = (gcnew System::Windows::Forms::ComboBox());
			this->comboSem = (gcnew System::Windows::Forms::ComboBox());
			this->comboCred = (gcnew System::Windows::Forms::ComboBox());
			this->txtCode = (gcnew System::Windows::Forms::TextBox());
			this->txtTitle = (gcnew System::Windows::Forms::TextBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(245, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 31);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Programme Courses";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label2->Location = System::Drawing::Point(34, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 26);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Programme:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label3->Location = System::Drawing::Point(34, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 26);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Level:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label4->Location = System::Drawing::Point(34, 150);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 26);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Semester:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label5->Location = System::Drawing::Point(34, 189);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(139, 26);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Course Code:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label6->Location = System::Drawing::Point(34, 228);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(131, 26);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Course Title:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F));
			this->label7->Location = System::Drawing::Point(34, 273);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(147, 26);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Course Credit:";
			// 
			// comboPrgm
			// 
			this->comboPrgm->FormattingEnabled = true;
			this->comboPrgm->Location = System::Drawing::Point(213, 78);
			this->comboPrgm->Name = L"comboPrgm";
			this->comboPrgm->Size = System::Drawing::Size(420, 24);
			this->comboPrgm->TabIndex = 13;
			// 
			// comboLvl
			// 
			this->comboLvl->FormattingEnabled = true;
			this->comboLvl->Location = System::Drawing::Point(213, 115);
			this->comboLvl->Name = L"comboLvl";
			this->comboLvl->Size = System::Drawing::Size(233, 24);
			this->comboLvl->TabIndex = 14;
			// 
			// comboSem
			// 
			this->comboSem->FormattingEnabled = true;
			this->comboSem->Location = System::Drawing::Point(213, 150);
			this->comboSem->Name = L"comboSem";
			this->comboSem->Size = System::Drawing::Size(233, 24);
			this->comboSem->TabIndex = 15;
			// 
			// comboCred
			// 
			this->comboCred->FormattingEnabled = true;
			this->comboCred->Location = System::Drawing::Point(213, 273);
			this->comboCred->Name = L"comboCred";
			this->comboCred->Size = System::Drawing::Size(121, 24);
			this->comboCred->TabIndex = 16;
			// 
			// txtCode
			// 
			this->txtCode->Location = System::Drawing::Point(213, 189);
			this->txtCode->Name = L"txtCode";
			this->txtCode->Size = System::Drawing::Size(233, 22);
			this->txtCode->TabIndex = 17;
			// 
			// txtTitle
			// 
			this->txtTitle->Location = System::Drawing::Point(213, 228);
			this->txtTitle->Name = L"txtTitle";
			this->txtTitle->Size = System::Drawing::Size(522, 22);
			this->txtTitle->TabIndex = 18;
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(624, 313);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(111, 32);
			this->btnCancel->TabIndex = 22;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmCourses::btnCancel_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(465, 313);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(111, 32);
			this->btnDelete->TabIndex = 21;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmCourses::btnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(299, 313);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(111, 32);
			this->btnUpdate->TabIndex = 20;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmCourses::btnUpdate_Click);
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::White;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(134, 313);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(111, 32);
			this->btnSave->TabIndex = 19;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmCourses::btnSave_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(39, 350);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(695, 202);
			this->panel1->TabIndex = 26;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(696, 202);
			this->dataGridView1->TabIndex = 0;
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(623, 558);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(111, 32);
			this->btnFind->TabIndex = 25;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmCourses::btnFind_Click);
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(406, 562);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(211, 22);
			this->txtFind->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(225, 562);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(175, 26);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Find Programme:";
			// 
			// frmCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(762, 597);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtTitle);
			this->Controls->Add(this->txtCode);
			this->Controls->Add(this->comboCred);
			this->Controls->Add(this->comboSem);
			this->Controls->Add(this->comboLvl);
			this->Controls->Add(this->comboPrgm);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmCourses";
			this->Text = L"Course Management";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void LoadProgrammes() {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM programme ORDER By prgm_name ASC";
			sqlDR = sqlCmd->ExecuteReader();
			while (sqlDR->Read()) {
				comboPrgm->Items->Add(sqlDR->GetString("prgm_name"));
			}
			sqlDR->Close();
			sqlCmd->Cancel();
			sqlConn->Close();
		}
		System::Void LoadLevels() {
			array<String^>^ levels = { "100", "200", "300", "400", "500", "600" };
			comboLvl->Items->AddRange(levels);
		}
		System::Void LoadSemesters() {
			array<String^>^ semesters = { "Fall", "Spring", "Summer" };
			comboSem->Items->AddRange(semesters);
		}
		System::Void LoadCredits() {
			array<Int32^>^ credits = { 1,2,3,4,5,6 };
			comboCred->Items->AddRange(credits);
		}
		System::Void LoadData() {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			DataTable^ dt = gcnew DataTable();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT c.course_id, p.prgm_name, c.level, c.sem, c.course_code, c.course_name, c.credit, c.programme_id, p.programme_id FROM course c JOIN programme p ON c.programme_id=p.programme_id ORDER By c.course_id ASC", sqlConn);
			da->Fill(dt);
			dataGridView1->DataSource = dt;
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 100;
			dataGridView1->Columns[2]->Width = 50;
			dataGridView1->Columns[3]->Width = 65;
			dataGridView1->Columns[4]->Width = 70;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 70;
			dataGridView1->Columns[7]->Visible = false;
			dataGridView1->Columns[8]->Visible = false;
			sqlCmd->Cancel();
			sqlConn->Close();
		}
		System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
			int courseID = Convert::ToInt32(txtFind->Text->Trim());
			if (courseID <= 0) {
				MessageBox::Show("Please enter a valid Course ID: ", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "SELECT * FROM course where course_id = @courseID";
				sqlCmd->Parameters->AddWithValue("@courseID", courseID);
				sqlDR = sqlCmd->ExecuteReader();
				if (sqlDR->Read()) {
					MessageBox::Show("Course Found");
					txtCode->Text = sqlDR["course_code"]->ToString();
					txtTitle->Text = sqlDR["course_name"]->ToString();
					globalCourseID = Convert::ToInt32(sqlDR["course_id"]);
					LoadData();
				}
				else {
					MessageBox::Show("Course Not Found", "Data Entry Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					sqlDR->Close();
					sqlCmd->Cancel();
				}
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				return;
			}
		}
		System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ programme = comboPrgm->Text->Trim();
			String^ level = comboLvl->Text->Trim();
			String^ semester = comboSem->Text->Trim();
			String^ courseCode = txtCode->Text->Trim();
			String^ courseTitle = txtTitle->Text->Trim();
			String^ courseCredit = comboCred->Text->Trim();
			if (programme == "" || level == "" || semester == "" || courseCode == "" || courseTitle == "" || courseCredit == "") {
				MessageBox::Show("Please fill all fields", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT * FROM course WHERE course_code = @courseCode";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@courseCode", courseCode);
				sqlDR = sqlCmd->ExecuteReader();
				if (sqlDR->Read()) {
					MessageBox::Show("Course already exists.", "Data Entry Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					sqlDR->Close();
					sqlCmd->Cancel();
				}
				else {
					sqlDR->Close();
					sqlCmd->Parameters->Clear();
					sqlCmd->CommandText = "SELECT programme_id FROM programme WHERE prgm_name = @programme";
					sqlCmd->Parameters->AddWithValue("@programme", programme);
					sqlDR = sqlCmd->ExecuteReader();
					int prgmID = 0;
					if (sqlDR->Read()) {
						prgmID = Convert::ToInt32(sqlDR["programme_id"]);
					}
					sqlDR->Close();
					sqlCmd->Parameters->Clear();
					sqlCmd->CommandText = "INSERT INTO course(programme_id, level, sem, course_code, course_name, credit) VALUES (@programmeID, @level, @semester, @courseCode, @courseTitle, @courseCredit)";
					sqlCmd->Parameters->AddWithValue("@programmeID", prgmID);
					sqlCmd->Parameters->AddWithValue("@level", level);
					sqlCmd->Parameters->AddWithValue("@semester", semester);
					sqlCmd->Parameters->AddWithValue("@courseCode", courseCode);
					sqlCmd->Parameters->AddWithValue("@courseTitle", courseTitle);
					sqlCmd->Parameters->AddWithValue("@courseCredit", courseCredit);
					sqlCmd->ExecuteNonQuery();
					sqlCmd->Parameters->Clear();
					MessageBox::Show("Course is saved successfully");
					LoadData();
					txtCode->Text = "";
					txtTitle->Text = "";
					comboPrgm->Text = "";
					comboLvl->Text = "";
					comboSem->Text = "";
					comboCred->Text = "";
				}
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				return;
			}
		}
		System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
			if (globalCourseID == 0 || txtCode->Text->Trim() == "") {
				MessageBox::Show("No Course Selected for update", "Select course");
				return;
			}
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			String^ programme = comboPrgm->Text->Trim();
			String^ level = comboLvl->Text->Trim();
			String^ semester = comboSem->Text->Trim();
			String^ courseCode = txtCode->Text->Trim();
			String^ courseTitle = txtTitle->Text->Trim();
			String^ courseCredit = comboCred->Text->Trim();
			try {
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "SELECT programme_id FROM programme WHERE prgm_name = @programme";
				sqlCmd->Parameters->AddWithValue("@programme", programme);
				sqlDR = sqlCmd->ExecuteReader();
				int prgmID = 0;
				if (sqlDR->Read()) {
					prgmID = Convert::ToInt32(sqlDR["programme_id"]);
				}
				sqlDR->Close();
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "UPDATE course SET programme_id = @prgmID, level = @level, sem = @semester, course_code = @courseCode, course_name = @courseTitle, credit = @courseCredit WHERE course_id = @courseID";
				sqlCmd->Parameters->AddWithValue("@courseID", globalCourseID);
				sqlCmd->Parameters->AddWithValue("@prgmID", prgmID);
				sqlCmd->Parameters->AddWithValue("@level", level);
				sqlCmd->Parameters->AddWithValue("@semester", semester);
				sqlCmd->Parameters->AddWithValue("@courseCode", courseCode);
				sqlCmd->Parameters->AddWithValue("@courseTitle", courseTitle);
				sqlCmd->Parameters->AddWithValue("@courseCredit", courseCredit);
				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Update is successful");
				sqlCmd->Parameters->Clear();
				LoadData();
				txtCode->Text = "";
				txtTitle->Text = "";
				comboPrgm->Text = "";
				comboLvl->Text = "";
				comboSem->Text = "";
				comboCred->Text = "";
				globalCourseID = 0;
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				return;
			}
		}
		System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			if (globalCourseID == 0) {
				MessageBox::Show("No Course Selected for deletion", "Select course");
				return;
			}
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "DELETE FROM course WHERE course_id = @courseID";
				sqlCmd->Parameters->AddWithValue("@courseID", globalCourseID);
				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Course Deleted Successfully");
				sqlCmd->Parameters->Clear();
				LoadData();
				txtCode->Text = "";
				txtTitle->Text = "";
				comboPrgm->Text = "";
				comboLvl->Text = "";
				comboSem->Text = "";
				comboCred->Text = "";
				globalCourseID = 0;
				sqlConn->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
				return;
			}
		}
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
