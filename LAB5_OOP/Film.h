#pragma once
#include <string>

using namespace std;

class Film
{
private:

	string title;
	string genre;
	int year = 0;
	int number_likes = 0;
	string trailer;

public:

	string get_title() { return title; }
	void set_title(string new_title) { title = new_title; }

	string get_genre() { return genre; }
	void set_genre(string new_genre) { genre = new_genre; }

	int get_year() { return year; }
	void set_year(int new_year) { year = new_year; }

	int get_number_likes() { return number_likes; }
	void set_number_likes(int new_number_likes) { number_likes = new_number_likes; }

	string get_trailer() { return trailer; }
	void set_trailer(string new_trailer) { trailer = new_trailer; }

	Film();

	Film(string t, string g, int y, int nr_l, string tr);

	~Film();
};
