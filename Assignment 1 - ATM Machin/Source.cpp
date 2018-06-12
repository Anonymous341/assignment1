#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
using std::cout;
int account, pause, wrong = 0, bal, menu_sel, def_bal12341 = 50000, def_bal12342 = 1000, def_bal12343 = 25000, def_bal12344 = 700, def_bal12345 = 100000, amount, account_login;
string pass, p_input, name_12341="aabb", name, name_12342="ccdd", name_12343="eeff", name_12344="gghh", name_12345="iijj";
void login(), verification(), balance(), transfer(), withdraw();
bool logged_in, username_v;
int main()
{
	cout << "Enter your account number or username: \t";
	cin >> account_login;
	login();
	verification();
	while (logged_in == true)
	{
	mode:
		cout << "Please enter the mode of operation. \n 1. View the balance in the account \n 2. Make transaction \n 3. Withdrawal \n 0. Logout and Exit \n";
		cin >> menu_sel;
		switch (menu_sel)
		{
		case 1:
			balance();
			goto mode;
		case 2:
			transfer();
			goto mode;
		case 3:
			withdraw();
			goto mode;
		case 0:
			logged_in = false;
			break;
		}
	}
}

void login()
{
	switch (account_login)
	{
	case 12341:
		pass = "a1b2c3";
		bal = def_bal12341;
		name = name_12341;
		username_v = true;
		break;
	case 12342:
		pass = "a2b2c3";
		bal = def_bal12342;
		name = name_12342;
		username_v = true;
		break;
	case 12343:
		pass = "A3b2c3";
		bal = def_bal12343;
		name = name_12343;
		username_v = true;
		break;
	case 12344:
		pass = "A4b2c3";
		bal = def_bal12344;
		name = name_12344;
		username_v = true;
		break;
	case 12345:
		pass = "A5b2c3";
		bal = def_bal12345;
		name = name_12345;
		username_v = true;
		break;
	default:
		cout << "Username or Account Number is invalid!";
		username_v = false;
		break;
	}
}

void verification()
{
Reenter:
	cout << "Please enter your password: \t";
	cin >> p_input;
	if (p_input == pass)
	{
		cout << "Welcome Back to account " << name << " !";
		logged_in = true;
	}
	else if (wrong<2)
	{
		cout << "Wrong Password! Please try again!\n";
		logged_in = false;
		wrong++;
		goto Reenter;
	}
	else
	{
		cout << "Account has been locked. Please refer to your nearest branch.\n";
		logged_in = false;
	}
}

void balance()
{
	cout << "Your Balance is " << bal << ". \n";
}

void transfer()
{
	cout << "Please enter the amount to be transfered from your account: ";
	cin >> amount;
	cout << "Please enter the account number for the money to be transferred to: ";
	cin >> account;

	if (account != account_login)
	{
		bal = bal - amount;
		cout << "Transaction is in progress...";
		switch (account)
		{
		case 12341:
			def_bal12341 = def_bal12341 + amount;
			break;
		case 12342:
			def_bal12342 = def_bal12342 + amount;
			break;
		case 12343:
			def_bal12343 = def_bal12343 + amount;
			break;
		case 12344:
			def_bal12344 = def_bal12344 + amount;
			break;
		case 12345:
			def_bal12345 = def_bal12345 + amount;
			break;
		default:
			cout << "Username or Account Number is invalid!";
			break;
		}
		cout << "Transaction from your account of " << amount << " to account " << account << " has been completed." << "Thank you for your business!\n";
	}
	else if (account == account_login)
	{
		cout << "You cannot transfer to your own account!\n";
	}
}

void withdraw()
{
	cout << "Please enter the amount to be withdrawn from your account: ";
	cin >> amount;
	bal = bal - amount;
	cout << "You have withdrawn " << amount << " from your account. \n Your balance is " << bal << ".\n";
}