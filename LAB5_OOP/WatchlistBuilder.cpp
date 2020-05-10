#include "WatchlistBuilder.h"
#include <fstream>

using namespace std;

void copy_line_by_line_from_and_store_into(string source, string destination)
{
    ofstream write;
    write.open(destination, ofstream::out | ofstream::trunc);

    ifstream file(source);
    string str;
    while (getline(file, str))
        write << str << '\n';
}

void WatchlistBuilder::build_watchlist_html(string filename, vector <int> watchlist, Repository& repo)
{
    ofstream fin;
    fin.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    copy_line_by_line_from_and_store_into("header.html", filename);

    for (int i = 0; i < watchlist.size(); i++)
    {
        Film film = repo.get_film_by_id(watchlist[i]);
        fin << "<tr><th scope = 'row'>" << i + 1 << "</th><td><strong>" << film.get_title() << "</strong></td><td>" << film.get_genre() << "<td>" << film.get_year() << "</td><td>" << film.get_number_likes() << "</td><td><a href=\"https://" << film.get_trailer() << "\" target='_blank'>Click link!</a></td></tr>" << '\n';
    }

    ifstream file("footer.html");
    string str;
    while (getline(file, str))
        fin << str << '\n';
}

void WatchlistBuilder::build_watchlist_csv(string filename, vector <int> watchlist, Repository& repo)
{
    ofstream fin;
    fin.open("watchlist.csv");

    fin << "#,Titel,Genre,Year,Likes,Trailer\n";

    for (int i = 0; i < watchlist.size(); i++)
    {
        Film film = repo.get_film_by_id(watchlist[i]);
        fin << i + 1 << "," << film.get_title() << "," << film.get_genre() << "," << film.get_year() << "," << film.get_number_likes() << "," << film.get_trailer() << '\n';
    }

    fin.close();
}