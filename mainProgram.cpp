#include "newFrmLogin.h"
#include "frmMain.h"
#include "facMain.h"
#include "stuMain.h"
using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    finalproject::newfrmLogin frmLogin;
    frmLogin.ShowDialog();
    User^ user = frmLogin.user;

    if (user->id != 0) {
        // Logic to determine which form to open based on user role
        if (user->roleNum == 0) {
            // Admin user logic
            finalproject::frmMain frMain(user);
            Application::Run(% frMain);
        }
        else if (user->roleNum == 1) {
            // Faculty user logic
			finalproject::facMain facmain(user);
			Application::Run(% facmain);
        }
        else if (user->roleNum == 2) {
            // Student user logic
			finalproject::stuMain stumain(user);
			Application::Run(% stumain);
		}
    }
    else {
        MessageBox::Show("Authentication Canceled", "",
            MessageBoxButtons::OK);
    }
}