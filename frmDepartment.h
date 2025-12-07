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
	/// Summary for frmDepartment
	/// </summary>
	public ref class frmDepartment : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlDA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlDR;
		DataTable^ sqlDT = gcnew DataTable();
		String^ ConnectionStr = "datasource = localhost; port=3306;username=root; password=''; database=ashesimis";
		int globalDeptID = 0;
	public:

		frmDepartment(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * FROM department ORDER By department_id DESC";
			sqlDR = sqlCmd->ExecuteReader();
			sqlDT->Load(sqlDR);
			sqlDR->Close();
			dataGridView1->DataSource = sqlDT;
			dataGridView1->Columns[0]->Width = 100;
			dataGridView1->Columns[1]->Width = 250;
			sqlCmd->Cancel();
			sqlConn->Close();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmDepartment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtDepartment;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtFind;
	private: System::Windows::Forms::Button^ btnFind;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDepartment = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtFind = (gcnew System::Windows::Forms::TextBox());
			this->btnFind = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(57, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Department:";
			// 
			// txtDepartment
			// 
			this->txtDepartment->Location = System::Drawing::Point(219, 52);
			this->txtDepartment->Multiline = true;
			this->txtDepartment->Name = L"txtDepartment";
			this->txtDepartment->Size = System::Drawing::Size(605, 34);
			this->txtDepartment->TabIndex = 1;
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::White;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSave->Location = System::Drawing::Point(217, 116);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(111, 32);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmDepartment::btnSave_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUpdate->Location = System::Drawing::Point(387, 116);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(111, 32);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmDepartment::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(553, 116);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(111, 32);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmDepartment::btnDelete_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnCancel->Location = System::Drawing::Point(713, 116);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(111, 32);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmDepartment::btnCancel_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(220, 187);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(603, 225);
			this->panel1->TabIndex = 6;
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(604, 225);
			this->dataGridView1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(409, 444);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(156, 26);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Department ID:";
			// 
			// txtFind
			// 
			this->txtFind->Location = System::Drawing::Point(571, 444);
			this->txtFind->Name = L"txtFind";
			this->txtFind->Size = System::Drawing::Size(108, 22);
			this->txtFind->TabIndex = 9;
			// 
			// btnFind
			// 
			this->btnFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnFind->Location = System::Drawing::Point(713, 440);
			this->btnFind->Name = L"btnFind";
			this->btnFind->Size = System::Drawing::Size(111, 32);
			this->btnFind->TabIndex = 10;
			this->btnFind->Text = L"Find";
			this->btnFind->UseVisualStyleBackColor = true;
			this->btnFind->Click += gcnew System::EventHandler(this, &frmDepartment::btnFind_Click);
			// 
			// frmDepartment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(909, 492);
			this->Controls->Add(this->btnFind);
			this->Controls->Add(this->txtFind);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtDepartment);
			this->Controls->Add(this->label1);
			this->Name = L"frmDepartment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Department";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ department = txtDepartment->Text->Trim();
		if (department == "") {
			MessageBox::Show("Please Enter Department", "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT * from department where dept_name = @dept";
			sqlCmd->Parameters->AddWithValue("@dept", department);
			sqlDR = sqlCmd->ExecuteReader();
			if (sqlDR->Read()) {
				MessageBox::Show("Department already exist", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
			}
			else {
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlCmd->CommandText = "INSERT INTO department(dept_name) VALUES (@department)";
				sqlCmd->Parameters->AddWithValue("@department", department);
				sqlCmd->ExecuteNonQuery();
				sqlCmd->Cancel();
				MessageBox::Show("Department is saved successfully");
			}
			sqlConn->Close();
			LoadData();
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnFind_Click(System::Object^ sender, System::EventArgs^ e) {
		int departmentID = Convert::ToInt32(txtFind->Text->Trim());
		if (departmentID <= 0) {
			MessageBox::Show("Please enter a valid Department ID: ", "Data Entry Error",
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
			sqlCmd->CommandText = "SELECT * FROM department where department_id = @deptID";
			sqlCmd->Parameters->AddWithValue("@deptID", departmentID);
			sqlDR = sqlCmd->ExecuteReader();
			if (sqlDR->Read()) {
				MessageBox::Show("Department Found");
				txtDepartment->Text = sqlDR["dept_name"]->ToString();
				globalDeptID = Convert::ToInt32(sqlDR["department_id"]);
				sqlDT->Load(sqlDR);
				sqlDR->Close();
				dataGridView1->DataSource = nullptr;
				dataGridView1->DataSource = sqlDT;
				dataGridView1->Columns[0]->Width = 100;
				dataGridView1->Columns[1]->Width = 250;
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
			}
			else {
				MessageBox::Show("The Department ID does not exist", "Data Entry Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				sqlDR->Close();
				sqlCmd->Cancel();
				sqlConn->Close();
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Databse Connection Error: " + e->ToString(), "Date Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			sqlDR->Close();
			sqlCmd->Cancel();
			sqlConn->Close();
			return;
		}
	}
	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalDeptID == 0 || txtDepartment->Text->Trim() == "") {
			MessageBox::Show("No Department Selected for update", "Select Department");
			return;
		}
		if (sqlConn->State == ConnectionState::Open) {
			sqlConn->Close();
		}
		String^ department = txtDepartment->Text;
		try {
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "UPDATE department SET dept_name = @department where department_id = @deptID";
			sqlCmd->Parameters->AddWithValue("@deptID", globalDeptID);
			sqlCmd->Parameters->AddWithValue("@department", department);
			sqlCmd->BeginExecuteNonQuery();
			MessageBox::Show("Update is successful");
			//Load the data in the department table to the DataGridView Control
			sqlCmd->CommandText = "SELECT * FROM department ORDER By department_id DESC";
			sqlDR = sqlCmd->ExecuteReader();
			sqlDT->Load(sqlDR);
			sqlDR->Close();
			dataGridView1->DataSource = sqlDT;
			dataGridView1->Columns[0]->Width = 100;
			dataGridView1->Columns[1]->Width = 250;
			sqlCmd->Cancel();
			txtDepartment->Text = "";
			sqlConn->Close();
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
			   MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM department", sqlConn);
			   da->Fill(dt);

			   dataGridView1->DataSource = dt;
			   dataGridView1->Columns[0]->Width = 100;
			   dataGridView1->Columns[1]->Width = 250;
		   }
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalDeptID == 0 || txtDepartment->Text->Trim() == "") {
			MessageBox::Show("No Department Selected for update", "Select or Find Department");
			return;
		}
		if (sqlConn->State == ConnectionState::Open) {
			sqlConn->Close();
		}
		String^ department = txtDepartment->Text;
		try {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
			sqlConn->ConnectionString = ConnectionStr;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->Parameters->Clear();
			sqlCmd->CommandText = "DELETE FROM department where department_id = @deptID";
			sqlCmd->Parameters->AddWithValue("@deptID", globalDeptID);
			sqlCmd->BeginExecuteNonQuery();
			MessageBox::Show("The department is deleted successfully");
			//Load the data in the department table to the DataGridView Control

			LoadData();
			sqlCmd->Cancel();
			txtDepartment->Text = "";
			sqlConn->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
