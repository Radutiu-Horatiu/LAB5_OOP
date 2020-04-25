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

	Repository::read_file(Repository::get_films(), "filme.txt");
	Repository::read_file(WatchList::get_watchlist(), "watchlist.txt");

	string option = " ";

	while (option != "0")
	{
		cout << "Menu\n\nOption 1 - Admin\nOption 2 - User\nOption 0 - Exit\n";

		cout << "\nYour option: ";
		cin >> option;

		if (option == "1")
		{
			cout << "\nAdmin menu\nPlease enter password: ";

			string password;
			cin >> password;

			if (password == "admin")
				show_admin_menu();
			else
				cout << "\nIncorrect password!\n";
		}
		else if (option == "2")
		{
			show_user_menu();
		}
		else if (option == "0")
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

	string opt = " ";

	cout << "\nYour option: ";
	cin >> opt;

	if (opt == "1")
	{
		Controller::admin_add_film_to_repository();
	}
	else if (opt == "2")
	{
		Controller::admin_delete_film_from_repository();
	}
	else if (opt == "3")
	{
		Controller::admin_update_film_from_repository();
	}
	else if (opt == "0")
	{
		return;
	}
	else
		cout << "\nInvalid option!\n";

	show_admin_menu();
}

void Console::show_user_menu()
{

	cout << "\nUser menu\n\nOption 1 - Show films by genres\nOption 2 - Delete film from watchlist\nOption 3 - See watchlist\nOption 0 - Exit\n";

	string option = " ";

	cout << "\nYour option: ";
	cin >> option;

	if (option == "1")
	{
		Controller::user_show_films_by_genres();
	}
	else if (option == "2")
	{
		Controller::user_delete_film_from_watchlist();
	}
	else if (option == "3")
	{
		Controller::user_show_watchlist();
	}
	else if (option == "0")
	{
		return;
	}
	else
		cout << "\nInvalid option!\n";

	show_user_menu();

}