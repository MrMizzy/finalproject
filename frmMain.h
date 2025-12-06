#pragma once
#include "user.h"
#include "frmDepartment.h"
#include "frmProgrammes.h"
#include "frmCourses.h"
#include "newfrmRegister.h"
#include "frmEnroll.h"
namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
		User^ currentUser = nullptr;
	public:
		frmMain(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			currentUser = user;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateReportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ administrationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ systemSetupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addDepartmentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addUsersToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^ addCourseToolStripMenuItem1;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateReportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->systemSetupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addDepartmentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addUsersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourseToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->studentToolStripMenuItem,
					this->facultyToolStripMenuItem, this->administrationToolStripMenuItem, this->systemSetupToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(698, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// studentToolStripMenuItem
			// 
			this->studentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->registerToolStripMenuItem,
					this->viewCourseToolStripMenuItem
			});
			this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
			this->studentToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->studentToolStripMenuItem->Text = L"Student";
			// 
			// registerToolStripMenuItem
			// 
			this->registerToolStripMenuItem->Name = L"registerToolStripMenuItem";
			this->registerToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->registerToolStripMenuItem->Text = L"Register Course";
			this->registerToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerToolStripMenuItem_Click);
			// 
			// viewCourseToolStripMenuItem
			// 
			this->viewCourseToolStripMenuItem->Name = L"viewCourseToolStripMenuItem";
			this->viewCourseToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->viewCourseToolStripMenuItem->Text = L"View Grades";
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->enterGradesToolStripMenuItem,
					this->generateReportToolStripMenuItem
			});
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			// 
			// enterGradesToolStripMenuItem
			// 
			this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
			this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
			// 
			// generateReportToolStripMenuItem
			// 
			this->generateReportToolStripMenuItem->Name = L"generateReportToolStripMenuItem";
			this->generateReportToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->generateReportToolStripMenuItem->Text = L"Generate Report";
			// 
			// administrationToolStripMenuItem
			// 
			this->administrationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->registerFacultyToolStripMenuItem,
					this->registerStudentToolStripMenuItem
			});
			this->administrationToolStripMenuItem->Name = L"administrationToolStripMenuItem";
			this->administrationToolStripMenuItem->Size = System::Drawing::Size(121, 24);
			this->administrationToolStripMenuItem->Text = L"Administration";
			// 
			// registerFacultyToolStripMenuItem
			// 
			this->registerFacultyToolStripMenuItem->Name = L"registerFacultyToolStripMenuItem";
			this->registerFacultyToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->registerFacultyToolStripMenuItem->Text = L"Register Faculty";
			// 
			// registerStudentToolStripMenuItem
			// 
			this->registerStudentToolStripMenuItem->Name = L"registerStudentToolStripMenuItem";
			this->registerStudentToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->registerStudentToolStripMenuItem->Text = L"Register Student";
			// 
			// systemSetupToolStripMenuItem
			// 
			this->systemSetupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addFacultyToolStripMenuItem,
					this->addDepartmentToolStripMenuItem, this->addCourseToolStripMenuItem, this->addUsersToolStripMenuItem, this->addCourseToolStripMenuItem1
			});
			this->systemSetupToolStripMenuItem->Name = L"systemSetupToolStripMenuItem";
			this->systemSetupToolStripMenuItem->Size = System::Drawing::Size(112, 24);
			this->systemSetupToolStripMenuItem->Text = L"System Setup";
			// 
			// addFacultyToolStripMenuItem
			// 
			this->addFacultyToolStripMenuItem->Name = L"addFacultyToolStripMenuItem";
			this->addFacultyToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->addFacultyToolStripMenuItem->Text = L"Add Faculty";
			// 
			// addDepartmentToolStripMenuItem
			// 
			this->addDepartmentToolStripMenuItem->Name = L"addDepartmentToolStripMenuItem";
			this->addDepartmentToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->addDepartmentToolStripMenuItem->Text = L"Add Department";
			this->addDepartmentToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addDepartmentToolStripMenuItem_Click);
			// 
			// addCourseToolStripMenuItem
			// 
			this->addCourseToolStripMenuItem->Name = L"addCourseToolStripMenuItem";
			this->addCourseToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->addCourseToolStripMenuItem->Text = L"Add Programme";
			this->addCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addCourseToolStripMenuItem_Click);
			// 
			// addUsersToolStripMenuItem
			// 
			this->addUsersToolStripMenuItem->Name = L"addUsersToolStripMenuItem";
			this->addUsersToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->addUsersToolStripMenuItem->Text = L"Add Users";
			this->addUsersToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addUsersToolStripMenuItem_Click);
			// 
			// addCourseToolStripMenuItem1
			// 
			this->addCourseToolStripMenuItem1->Name = L"addCourseToolStripMenuItem1";
			this->addCourseToolStripMenuItem1->Size = System::Drawing::Size(224, 26);
			this->addCourseToolStripMenuItem1->Text = L"Add Course";
			this->addCourseToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMain::addCourseToolStripMenuItem1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripLabel1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 28);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(698, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(0, 22);
			this->toolStripLabel1->Click += gcnew System::EventHandler(this, &frmMain::toolStripLabel1_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(698, 511);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmMain";
			this->Text = L"Ashesi Academic Record Management System";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMain::frmMain_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void registerToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmEnroll frmEnrl(currentUser);
		frmEnrl.ShowDialog();
	}
	private: System::Void toolStripLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void frmMain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// Optional Confirmation
		if (MessageBox::Show("Do you want to exit?", "Confirm Exit", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

			// Close the entire application
			Application::Exit();
			// return;
		}
		else {
			e->Cancel = true; // cancel closing
			return;
		}


	}
	private: System::Void addDepartmentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmDepartment frmDept;
		frmDept.ShowDialog();
	}
	private: System::Void addCourseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmProgrammes frmPrg;
		frmPrg.ShowDialog();
	}
	private: System::Void addCourseToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmCourses frmCrse;
		frmCrse.ShowDialog();
	}
	private: System::Void addUsersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::newfrmRegister frmReg;
		frmReg.ShowDialog();
	}
};
}
