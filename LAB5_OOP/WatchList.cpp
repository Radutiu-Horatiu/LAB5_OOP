#include "WatchList.h"
#include "Validate.h"
#include "Repository.h"
using namespace std;


bool WatchList::isEmpty()
{
    if (watchlist.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool WatchList::remove_film_from_watchlist(int ID)
{
    if (!watchlist.empty())
    {
        for (int i = 0; i < watchlist.size(); i++)
        {
            if (watchlist[i] == ID)
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

bool WatchList::add_film_to_watchlist(int id)
{
  
    Validate v;

    if (!(v.validate_uniqueness(id, *this)))
    {
        return false; //Film already in watchlist.
    }
    else
    {
        watchlist.push_back(id);
        return true; //Film successfully added to watchlist.
    }

}

bool WatchList::find_film_by_id(int id)
{
    for (int i = 0; i < watchlist.size(); i++)
        if (watchlist[i] == id)
            return true;

    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of WatchList.cpp
////////////////////////////////////////////////////////////////////////////////////////////////////

