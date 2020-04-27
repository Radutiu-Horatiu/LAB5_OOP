#include "WatchList.h"
#include "Validate.h"
#include "Repository.h"
using namespace std;


bool WatchList::remove_film_from_watchlist(int ID)
{
    if (!watchlist.empty())
    {
        for (int i = 0; i < watchlist.size(); i++)
        {
            if (watchlist[i].get_id() == ID)
            {
                watchlist.erase(watchlist.begin() + i);
                return true; //Film found and deleted.
            }
        }

        return false; //Film not found
    }
    else
    {
        return false; //Watchlist is empty.
    }
}

bool WatchList::add_film_to_watchlist(int id, Repository& repo)
{
    Film filmToBeAdded = repo.get_film_by_id(id);

    Validate v;

    if (!(v.validate_uniqueness(filmToBeAdded.get_id(), *this)))
    {
        return false; //Film already in watchlist.
    }
    else
    {
        watchlist.push_back(filmToBeAdded);
        return true; //Film successfully added to watchlist.
    }

}

bool WatchList::find_film_by_id(int id)
{
    for (int i = 0; i < watchlist.size(); i++)
        if (watchlist[i].get_id() == id)
            return true;

    return false;
}