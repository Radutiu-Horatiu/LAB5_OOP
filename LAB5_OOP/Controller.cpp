#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::admin_add_film_to_repository()
{
	cout << "\nAdd film\n";

	string title;
	string genre;
	string year;
	string trailer;
	int id;

	cout << "Title: ";
	cin >> title;

	cout << "Genre: ";
	cin >> genre;

	cout << "Year: ";
	cin >> year;

	cout << "Trailer-link: ";
	cin >> trailer;

	cout << "ID: ";
	cin >> id;

	while (cin.fail()) {
		cout << "Error ID must be integer: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> id;
	}

	if (add_film(title, genre, year, trailer, id))
	{
		write_file(get_films(), "filme.txt");
		cout << "\nFilm added successfully!\n";
	}
	else
		cout << "\nSomething went wrong.\n";

}

void Controller::admin_delete_film_from_repository()
{
}

void Controller::admin_update_film_from_repository()
{
}

void Controller::user_show_films_by_genres()
{
}

void Controller::user_delete_film_from_watchlist()
{
}

void Controller::user_show_watchlist()
{
}
