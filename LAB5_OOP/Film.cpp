#include "Film.h"

using namespace std;

Film::Film()
{
	title = "?";
	genre = "?";
	trailer = "?";
}

Film::Film(string t, string g, int y, int nr_l, string tr)
{
	title = t;
	genre = g;
	year = y;
	number_likes = nr_l;
	trailer = tr;
}

Film::~Film()
{
}