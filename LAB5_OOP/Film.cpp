#include "Film.h"

using namespace std;

Film::Film()
{
	title = "?";
	genre = "?";
	year = "?";
	trailer = "?";
	
}

Film::Film(string TITLE, string GENRE, string YEAR, string TRAILER, int ID)
{
	title = TITLE;
	genre = GENRE;
	year = YEAR;
	trailer = TRAILER;
	id = ID;
}

Film::~Film()
{
}