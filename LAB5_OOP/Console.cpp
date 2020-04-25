#include "Console.h"
#include <iostream>
#include <string>

using namespace std;

Console::Console()
{
}

Console::~Console()
{
}

void Console::show_menu()
{

	char option = ' ';

	while (option != '0')
	{
		cout << "Menu\n\nOption 1 - Admin\nOption 2 - User\nOption 0 - Exit\n";

		cout << "\nYour option: ";
		cin >> option;

		if (option == '1')
		{
			cout << "\nAdmin menu\nPlease enter password: ";

			string password;
			cin >> password;

			if (password == "admin")
				show_admin_menu();
			else
				cout << "\nIncorrect password!\n";
		}
		else if (option == '2')
		{

		}
		else if (option == '0')
		{
			break;
		}
		else
			cout << "\nInvalid option!\n";
	}

}

void Console::show_admin_menu()
{

	cout << "\nOption 1 - Add film\nOption 2 - Delete film\nOption 3 - Update film\nOption 0 - Exit\n";

	char option = ' ';

	while (option != '0')
	{
		cout << "\nYour option: ";
		cin >> option;

		if (option == '1')
		{
			
		}
		else if (option == '2')
		{

		}
		else if (option == '3')
		{

		}
		else if (option == '0')
		{
			break;
		}
		else
			cout << "\nInvalid option!\n";
	}
}

void Console::show_user_menu()
{

	cout << "\nUser menu\n\nOption 1 - Show films by genres\nOption 2 - Delete film from watchlist\nOption 3 - See watchlist\nOption 0 - Exit\n";

	char option = ' ';

	while (option != '0')
	{
		cout << "\nYour option: ";
		cin >> option;

		if (option == '1')
		{

		}
		else if (option == '2')
		{

		}
		else if (option == '3')
		{

		}
		else if (option == '0')
		{
			break;
		}
		else
			cout << "\nInvalid option!\n";
	}
}