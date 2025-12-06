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
namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for stuMain
	/// </summary>
	public ref class stuMain : public System::Windows::Forms::Form
	{
		User^ currentUser = nullptr;
	public:
		stuMain(User^ user)
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
		~stuMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
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
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->studentToolStripMenuItem });
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
			this->registerToolStripMenuItem->Click += gcnew System::EventHandler(this, &stuMain::registerToolStripMenuItem_Click);
			// 
			// viewCourseToolStripMenuItem
			// 
			this->viewCourseToolStripMenuItem->Name = L"viewCourseToolStripMenuItem";
			this->viewCourseToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->viewCourseToolStripMenuItem->Text = L"View Grades";
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
			this->toolStripLabel1->Click += gcnew System::EventHandler(this, &stuMain::toolStripLabel1_Click);
			// 
			// stuMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(698, 511);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"stuMain";
			this->Text = L"Ashesi Academic Record Management System";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &stuMain::stuMain_FormClosing);
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
	private: System::Void stuMain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
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
	};
}
