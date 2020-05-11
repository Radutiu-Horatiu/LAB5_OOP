#include "htmlBuilder.h"
#include <fstream>

using namespace std;

void htmlBuilder::build_watchlist(vector <int> watchlist, Repository& repo)
{
    string filename = "watchlist.html";
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
