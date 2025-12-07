#pragma once
#include "user.h"
#include "frmDepartment.h"
#include "frmProgrammes.h"
#include "frmCourses.h"
#include "newfrmRegister.h"
#include "frmEnroll.h"
#include "frmRegFac.h"
#include "frmRegStu.h"
#include "frmGrades.h"
#include "frmAssign.h"
#include "frmTranscript.h"
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
	private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateTranscriptToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCourseToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ administrationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ systemSetupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addDepartmentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^ addCourseToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ registerAdminToolStripMenuItem;
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
			this->generateTranscriptToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerAdminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->systemSetupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addDepartmentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(524, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// studentToolStripMenuItem
			// 
			this->studentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->registerToolStripMenuItem,
					this->generateTranscriptToolStripMenuItem
			});
			this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
			this->studentToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->studentToolStripMenuItem->Text = L"Student";
			// 
			// registerToolStripMenuItem
			// 
			this->registerToolStripMenuItem->Name = L"registerToolStripMenuItem";
			this->registerToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->registerToolStripMenuItem->Text = L"Register Course";
			this->registerToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerToolStripMenuItem_Click);
			// 
			// generateTranscriptToolStripMenuItem
			// 
			this->generateTranscriptToolStripMenuItem->Name = L"generateTranscriptToolStripMenuItem";
			this->generateTranscriptToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->generateTranscriptToolStripMenuItem->Text = L"Generate Transcript";
			this->generateTranscriptToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::generateTranscriptToolStripMenuItem_Click);
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->enterGradesToolStripMenuItem,
					this->manageCourseToolStripMenuItem
			});
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			// 
			// enterGradesToolStripMenuItem
			// 
			this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
			this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
			this->enterGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::enterGradesToolStripMenuItem_Click);
			// 
			// manageCourseToolStripMenuItem
			// 
			this->manageCourseToolStripMenuItem->Name = L"manageCourseToolStripMenuItem";
			this->manageCourseToolStripMenuItem->Size = System::Drawing::Size(228, 22);
			this->manageCourseToolStripMenuItem->Text = L"Manage Course Assignments";
			this->manageCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::generateReportToolStripMenuItem_Click);
			// 
			// administrationToolStripMenuItem
			// 
			this->administrationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->registerFacultyToolStripMenuItem,
					this->registerStudentToolStripMenuItem, this->registerAdminToolStripMenuItem
			});
			this->administrationToolStripMenuItem->Name = L"administrationToolStripMenuItem";
			this->administrationToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->administrationToolStripMenuItem->Text = L"Administration";
			// 
			// registerFacultyToolStripMenuItem
			// 
			this->registerFacultyToolStripMenuItem->Name = L"registerFacultyToolStripMenuItem";
			this->registerFacultyToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->registerFacultyToolStripMenuItem->Text = L"Register Faculty";
			this->registerFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerFacultyToolStripMenuItem_Click);
			// 
			// registerStudentToolStripMenuItem
			// 
			this->registerStudentToolStripMenuItem->Name = L"registerStudentToolStripMenuItem";
			this->registerStudentToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->registerStudentToolStripMenuItem->Text = L"Register Student";
			this->registerStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerStudentToolStripMenuItem_Click);
			// 
			// registerAdminToolStripMenuItem
			// 
			this->registerAdminToolStripMenuItem->Name = L"registerAdminToolStripMenuItem";
			this->registerAdminToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->registerAdminToolStripMenuItem->Text = L"Register Admin";
			this->registerAdminToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::registerAdminToolStripMenuItem_Click);
			// 
			// systemSetupToolStripMenuItem
			// 
			this->systemSetupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addDepartmentToolStripMenuItem,
					this->addCourseToolStripMenuItem, this->addCourseToolStripMenuItem1
			});
			this->systemSetupToolStripMenuItem->Name = L"systemSetupToolStripMenuItem";
			this->systemSetupToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->systemSetupToolStripMenuItem->Text = L"System Setup";
			// 
			// addDepartmentToolStripMenuItem
			// 
			this->addDepartmentToolStripMenuItem->Name = L"addDepartmentToolStripMenuItem";
			this->addDepartmentToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->addDepartmentToolStripMenuItem->Text = L"Add Department";
			this->addDepartmentToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addDepartmentToolStripMenuItem_Click);
			// 
			// addCourseToolStripMenuItem
			// 
			this->addCourseToolStripMenuItem->Name = L"addCourseToolStripMenuItem";
			this->addCourseToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->addCourseToolStripMenuItem->Text = L"Add Programme";
			this->addCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addCourseToolStripMenuItem_Click);
			// 
			// addCourseToolStripMenuItem1
			// 
			this->addCourseToolStripMenuItem1->Name = L"addCourseToolStripMenuItem1";
			this->addCourseToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
			this->addCourseToolStripMenuItem1->Text = L"Add Course";
			this->addCourseToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMain::addCourseToolStripMenuItem1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripLabel1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(524, 25);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(524, 415);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
	private: System::Void registerFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmRegFac frmReg;
		frmReg.ShowDialog();
	}
	private: System::Void registerStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmRegStu frmReg;
		frmReg.ShowDialog();
	}
	private: System::Void registerAdminToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::newfrmRegister frmReg;
		frmReg.ShowDialog();
	}
	private: System::Void generateReportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmAssign frmAssign(currentUser);
		frmAssign.ShowDialog();
	}
	private: System::Void enterGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		finalproject::frmGrades frmGrd;
		frmGrd.ShowDialog();
	}
private: System::Void generateTranscriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	finalproject::frmTranscript frmTran;
	frmTran.ShowDialog();
}
};
}
