#include "Controller.h"
#include <iostream>
#include <string>
#include "Validate.h"
using namespace std;

Controller::Controller()
{
	repo.read_file(repo.get_films(), "filme.txt");
	repo.read_file(watchlist.get_watchlist(), "watchlist.txt");
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

	if (repo.add_film(title, genre, year, trailer, id))
	{
		repo.write_file(repo.get_films(), "filme.txt");
		cout << "\nFilm added successfully!\n";
	}
	else
		cout << "\nSomething went wrong.\n";

}

void Controller::admin_delete_film_from_repository()
{
	cout << "\nDelete film\nList of films:\n";

	repo.print_films(repo.get_films());

	int id;
	cout << "\nID of film to delete: ";
	cin >> id;

	while (cin.fail()) {
		cout << "Error ID must be integer: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> id;
	}

	if (repo.remove_film(id))
	{
		repo.write_file(repo.get_films(), "filme.txt");
		cout << "\nFilm deleted successfully!\n";
	}
	else
		cout << "\nSomething went wrong.\n";
}

void Controller::admin_update_film_from_repository()
{
	cout << "\nUpdate film\nList of films:\n";

	repo.print_films(repo.get_films());

	int id;
	cout << "\nID of film to update: ";
	cin >> id;

	while (cin.fail()) {
		cout << "Error ID must be integer: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> id;
	}

	Validate v;
	if (v.validate_uniqueness(id, repo))
	{
		cout << "Film does not exist!\n";
		return;
	}

	string title;
	string genre;
	string year;
	string trailer;

	cout << "New title: ";
	cin >> title;

	cout << "New genre: ";
	cin >> genre;

	cout << "New year: ";
	cin >> year;

	cout << "New trailer-link: ";
	cin >> trailer;

	if (repo.update_film(id, title, genre, year, trailer))
	{
		repo.write_file(repo.get_films(), "filme.txt");
		cout << "\nFilm updated successfully!\n";
	}
	else
		cout << "\nSomething went wrong.\n";
}

void Controller::user_show_films_by_genres()
{
	cout << "\nBrowse films by genre\n";

	cout << "Example: DRAMA ACTION THRILLER SF CRIME\n";

	cout << "\nChoose genre: ";

	string genre;
	cin >> genre;

	vector <Film> result = repo.show_films_to_user(genre);

	cout << "\nFilms found:\n";
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << "ID: " << result[i].get_id() << " Title: " << result[i].get_title() << " Genre: " << result[i].get_genre() <<
			" Year: " << result[i].get_year() << " Likes: " << result[i].get_number_likes() << "\n";

		repo.open_link_in_browser(result[i].get_trailer());

		string answer;

		cout << "\nAdd to watchlist?\nY - yes, N - no\nAnswer: ";
		cin >> answer;

		if (answer == "y" or answer == "Y")
		{

			if (watchlist.add_film_to_watchlist(result[i].get_id()))
			{
				repo.write_file(watchlist.get_watchlist(), "watchlist.txt");
				cout << "\nFilm successfully added to your watchlist!\n\n";
			}
			else
				cout << "\nSomething went wrong.\n";
		}

		cout << "Watch another trailer?\nY - yes, N - no\nAnswer: ";
		string answer2;
		cin >> answer2;

		if (answer2 == "n" or answer2 == "N")
			break;
	}

}

void Controller::user_delete_film_from_watchlist()
{
	cout << "\nRemove from watchlist\n\n";

	cout << "Your watchlist:\n";

	user_show_watchlist();

	int id;
	cout << "\nID of film to remove: ";
	cin >> id;

	while (cin.fail()) {
		cout << "Error ID must be integer: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> id;
	}

	if (watchlist.remove_film_from_watchlist(id))
	{
		cout << "\nFilm removed from watchlist successfully!\n";

		string like;

		cout << "Liked the movie?\nY - yes, N - no\nAnswer: ";
		cin >> like;

		if (like == "Y" or like == "y")
		{
			for (int i = 0; i < repo.get_films().size(); i++)
				if (repo.get_films()[i].get_id() == id)
				{
					repo.get_films()[i].set_number_likes(repo.get_films()[i].get_number_likes() + 1);

					repo.write_file(repo.get_films(), "filme.txt");
					repo.write_file(watchlist.get_watchlist(), "watchlist.txt");

					cout << "\nLike submitted!\n";
				}
		}
	}
	else
		cout << "\nSomething went wrong.\n";

}

void Controller::user_show_watchlist()
{
	cout << "\nWatchlist\n\n";

	vector <Film> films;
	
	for (int i = 0; i < watchlist.get_watchlist().size(); i++)
	{
		Film film = repo.get_film_by_id(watchlist.get_watchlist()[i]);
		films.push_back(film);
	}

	repo.print_films(films);
}
