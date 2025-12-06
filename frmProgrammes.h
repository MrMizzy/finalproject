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
	/// Summary for frmProgrammes
	/// </summary>
	public ref class frmProgrammes : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306;username=root; password=''; database=ashesi_arms";
		int globalPrgmtID = 0;
	public:
		frmProgrammes(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LoadDepartments();
			LoadProgrammeType();
			LoadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmProgrammes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnFind;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ComboBox^ comboDept;
	private: System::Windows::Forms::ComboBox^ comboPrgm;
	private: System::Windows::Forms::TextBox^ txtPrgm;
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->comboDept = (gcnew System::Windows::Forms::ComboBox());
			this->comboPrgm = (gcnew System::Windows::Forms::ComboBox());
			this->txtPrgm = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(312, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(284, 31);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Academic Programmes";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(47, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 26);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Department:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(47, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 26);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Programme:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(47, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(178, 26);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Programme Type:";
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(711, 198);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(111, 32);
			this->btnCancel->TabIndex = 12;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmProgrammes::btnCancel_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(552, 198);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(111, 32);
			this->btnDelete->TabIndex = 11;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmProgrammes::btnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(386, 198);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(111, 32);
			this->btnUpdate->TabIndex = 10;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmProgrammes::btnUpdate_Click);
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::White;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(221, 198);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(111, 32);
			this->btnSave->TabIndex = 9;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmProgrammes::btnSave_Click);
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(711, 444);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(111, 32);
			this->btnFind->TabIndex = 16;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmProgrammes::btnFind_Click);
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(494, 448);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(211, 22);
			this->txtFind->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(313, 448);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(175, 26);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Find Programme:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(221, 236);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(601, 202);
			this->panel1->TabIndex = 17;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(601, 202);
			this->dataGridView1->TabIndex = 0;
			// 
			// comboDept
			// 
			this->comboDept->FormattingEnabled = true;
			this->comboDept->Location = System::Drawing::Point(297, 63);
			this->comboDept->Name = L"comboDept";
			this->comboDept->Size = System::Drawing::Size(525, 24);
			this->comboDept->TabIndex = 18;
			this->comboDept->SelectedIndexChanged += gcnew System::EventHandler(this, &frmProgrammes::comboDept_SelectedIndexChanged);
			// 
			// comboPrgm
			// 
			this->comboPrgm->FormattingEnabled = true;
			this->comboPrgm->Location = System::Drawing::Point(297, 146);
			this->comboPrgm->Name = L"comboPrgm";
			this->comboPrgm->Size = System::Drawing::Size(135, 24);
			this->comboPrgm->TabIndex = 19;
			this->comboPrgm->SelectedIndexChanged += gcnew System::EventHandler(this, &frmProgrammes::comboPrgm_SelectedIndexChanged);
			// 
			// txtPrgm
			// 
			this->txtPrgm->Location = System::Drawing::Point(297, 106);
			this->txtPrgm->Name = L"txtPrgm";
			this->txtPrgm->Size = System::Drawing::Size(525, 22);
			this->txtPrgm->TabIndex = 20;
			// 
			// frmProgrammes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(909, 492);
			this->Controls->Add(this->txtPrgm);
			this->Controls->Add(this->comboPrgm);
			this->Controls->Add(this->comboDept);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Name = L"frmProgrammes";
			this->Text = L"frmProgrammes";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void LoadDepartments() {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM department ORDER By department ASC";
			sqlDR = sqlCmd->ExecuteReader();
			while (sqlDR->Read()) {
				comboDept->Items->Add(sqlDR->GetString("department"));
			}
			sqlDR->Close();
			sqlCmd->Cancel();
			sqlConn->Close();
		}
		System::Void LoadProgrammeType() {
			array<String^>^ prgmTypes = { "BSc", "BA", "MSc", "MA", "PhD" };
			comboPrgm->Items->AddRange(prgmTypes);
		}
		System::Void comboDept_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			String^ selectedDept = comboDept->SelectedItem->ToString();
		}
		System::Void comboPrgm_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			String^ selectedPrgm = comboPrgm->SelectedItem->ToString();
		}
		System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
			int prgmID = Convert::ToInt32(txtFind->Text->Trim());
			if (prgmID <= 0) {
				MessageBox::Show("Please enter a valid Programme ID: ", "Data Entry Error",
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
				sqlCmd->CommandText = "SELECT * FROM programmes where id = @prgmID";
				sqlCmd->Parameters->AddWithValue("@prgmID", prgmID);
				sqlDR = sqlCmd->ExecuteReader();
				if (sqlDR->Read()) {
					MessageBox::Show("Programme Found");
					txtPrgm->Text = sqlDR["Programme"]->ToString();
					globalPrgmtID = Convert::ToInt32(sqlDR["id"]);
					LoadData();
				}
				else {
					MessageBox::Show("Programme Not Found", "Data Entry Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					sqlDR->Close();
					sqlCmd->Cancel();
					sqlConn->Close();
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
			String^ department = comboDept->Text->Trim();
			String^ programme = txtPrgm->Text->Trim();
			String^ programmeType = comboPrgm->Text->Trim();
			if (department == "" || programme == "" || programmeType == "") {
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
				sqlCmd->CommandText = "SELECT * FROM programmes WHERE Programme = @programme";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@programme", programme);
				sqlDR = sqlCmd->ExecuteReader();
				if (sqlDR->Read()) {
					MessageBox::Show("Programme already exists.", "Data Entry Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					sqlDR->Close();
					sqlCmd->Cancel();
				}
				else {
					sqlDR->Close();
					sqlCmd->Parameters->Clear();
					sqlCmd->CommandText = "SELECT id FROM department WHERE Department = @department";
					sqlCmd->Parameters->AddWithValue("@department", department);
					sqlDR = sqlCmd->ExecuteReader();
					int depID = 0;
					if (sqlDR->Read()) {
						depID = Convert::ToInt32(sqlDR["id"]);
					}
					sqlDR->Close();
					sqlCmd->Parameters->Clear();
					sqlCmd->CommandText = "INSERT INTO programmes(Programme, Department, Programmetype) VALUES (@programme, @departmentID, @programmeType)";
					sqlCmd->Parameters->AddWithValue("@programme", programme);
					sqlCmd->Parameters->AddWithValue("@departmentID", depID);
					sqlCmd->Parameters->AddWithValue("@programmeType", programmeType);
					sqlCmd->ExecuteNonQuery();
					sqlDR->Close();
					sqlCmd->Cancel();
					MessageBox::Show("Programme is saved successfully");
				}
				sqlConn->Close();
				LoadData();
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
			if (globalPrgmtID == 0 || txtPrgm->Text->Trim() == "") {
				MessageBox::Show("No Programme Selected for update", "Select programme");
				return;
			}
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			String^ programme = txtPrgm->Text->Trim();
			String^ department = comboDept->Text->Trim();
			String^ programmeType = comboPrgm->Text->Trim();
			try {
				sqlConn->ConnectionString = ConnectionStr;
				sqlConn->Open();
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "SELECT id FROM department WHERE Department = @department";
				sqlCmd->Parameters->AddWithValue("@department", department);
				sqlDR = sqlCmd->ExecuteReader();
				int depID = 0;
				if (sqlDR->Read()) {
					depID = Convert::ToInt32(sqlDR["id"]);
				}
				sqlDR->Close();
				sqlCmd->Parameters->Clear();
				sqlCmd->CommandText = "UPDATE programmes SET Programme = @programme, Department = @depID, Programmetype = @pType WHERE id = @prgID";
				sqlCmd->Parameters->AddWithValue("@prgID", globalPrgmtID);
				sqlCmd->Parameters->AddWithValue("@depID", depID);
				sqlCmd->Parameters->AddWithValue("@programme", programme);
				sqlCmd->Parameters->AddWithValue("@pType", programmeType);
				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Update is successful");
				sqlCmd->Parameters->Clear();
				LoadData();
				txtPrgm->Text = "";
				comboDept->Text = "";
				comboPrgm->Text = "";
				globalPrgmtID = 0;
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			if (globalPrgmtID == 0) {
				MessageBox::Show("No Programme Selected for deletion", "Select Programme");
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
				sqlCmd->CommandText = "DELETE FROM programmes WHERE id = @prgmID";
				sqlCmd->Parameters->AddWithValue("@prgmID", globalPrgmtID);
				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Programme Deleted Successfully");
				sqlCmd->Parameters->Clear();
				LoadData();
				txtPrgm->Text = "";
				comboDept->Text = "";
				comboPrgm->Text = "";
				globalPrgmtID = 0;
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		void LoadData() {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			DataTable^ dt = gcnew DataTable();
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT p.ID, d.Department, p.Programme, p.Programmetype, d.ID, p.Department FROM programmes p JOIN department d ON p.department=d.ID ORDER By p.ID DESC", sqlConn);
			da->Fill(dt);
			dataGridView1->DataSource = dt;
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 100;
			dataGridView1->Columns[2]->Width = 130;
			dataGridView1->Columns[3]->Width = 100;
			dataGridView1->Columns[4]->Visible = false;
			dataGridView1->Columns[5]->Visible = false;
			sqlCmd->Cancel();
			sqlConn->Close();
		}
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
