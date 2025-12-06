#pragma once
using namespace System;
public ref class User {
public:
	int id;
	String^ fName;
	String^ lName;
	String^ email;
	String^ password;
	int roleNum;
	User() {
		id = 0;
	}
};