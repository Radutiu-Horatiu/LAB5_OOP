#include "Film.h"

using namespace std;

Film::Film() {}

bool Film::operator==(const Film& rhs)
{
	if (this->id != rhs.id) return false;
	if (this->title != rhs.title) return false;
	if (this->genre != rhs.genre) return false;
	if (this->year != rhs.year) return false;
	if (this->number_likes != rhs.number_likes) return false;
	if (this->trailer != rhs.trailer) return false;

	return true;
}

Film::Film(const Film& film)
{
	this->id = film.id;
	this->title = film.title;
	this->genre = film.genre;
	this->year = film.year;
	this->number_likes = film.number_likes;
	this->trailer = film.trailer;
}

Film::Film(string title, string genre, string year, string trailer, int id)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->trailer = trailer;
	this->id = id;
}

Film::~Film()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of Film.cpp
////////////////////////////////////////////////////////////////////////////////////////////////////

