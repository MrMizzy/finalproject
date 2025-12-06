#include "newFrmLogin.h"
#include "frmMain.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	System::Windows::Forms::DialogResult result = MessageBox::Show("Welcome to Ashesi Academic Record Management System. Are you a new user?", "Welcome",
		MessageBoxButtons::YesNo);

    if (result == System::Windows::Forms::DialogResult::Yes) {
        finalproject::newfrmRegister frmRegister;
        frmRegister.ShowDialog();
	}

    finalproject::newfrmLogin frmLogin;
    frmLogin.ShowDialog();
    User^ user = frmLogin.user;

    if (user->id != 0) {
        finalproject::frmMain frMain(user);
        Application::Run(% frMain);
    }
    else {
        MessageBox::Show("Authentication Canceled", "",
            MessageBoxButtons::OK);
    }
}