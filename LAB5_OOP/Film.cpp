#include "Film.h"

using namespace std;

Film::Film() {}

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