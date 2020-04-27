#pragma once
#include <string>

using namespace std;

class Film
{
private:

	string title = "?";
	string genre = "?";
	string year = "?";
	int number_likes = 0;
	string trailer = "?";
	int id = 0;

public:

	string get_title() { return title; }
	void set_title(string new_title) { title = new_title; }

	string get_genre() { return genre; }
	void set_genre(string new_genre) { genre = new_genre; }

	string get_year() { return year; }
	void set_year(string new_year) { year = new_year; }

	int get_number_likes() { return number_likes; }
	void set_number_likes(int new_number_likes) { number_likes = new_number_likes; }

	string get_trailer() { return trailer; }
	void set_trailer(string new_trailer) { trailer = new_trailer; }

	int get_id() { return id; }
	void set_id(int new_id) { id = new_id; }

	Film();

	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Horatiu, 4/27/2020. </remarks>
	///
	/// <param name="TITLE">  	The title. </param>
	/// <param name="GENRE">  	The genre. </param>
	/// <param name="YEAR">   	The year of appearance. </param>
	/// <param name="TRAILER">	The trailer. </param>
	/// <param name="ID">	  	The identifier. </param>
	Film(string title, string genre, string year, string trailer, int id);

	~Film();
};
