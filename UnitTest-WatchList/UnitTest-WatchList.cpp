#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB5_OOP/Film.h"
#include "../LAB5_OOP/Validate.h"
#include "../LAB5_OOP/WatchList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestWatchList
{
	TEST_CLASS(WatchListClass)
	{
	public:
		
		TEST_METHOD(AddFilmToWatchList)
		{
			WatchList TesterWatchList;

			vector<Film> TestFilmContainer;

			Film film_1("Interstellar", "Sci-Fi", "2014", "www.imdb.com/video/vi1586278169?playlistId=tt0816692&ref_=tt_ov_vi", 1);
			Film film_2("Joker", "Drama", "2019", "www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2", 2);
			Film film_3("The Godfather", "Drama", "1972", "www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1", 3);
			Film film_4("The Dark Knight", "Action", "2008", "www.imdb.com/video/vi324468761?ref_=ttvi_vi_imdb_1", 4);
			Film film_5("The Lord of the Rings: The Return of the King", "Adventure", "2003", "www.imdb.com/video/vi2073101337?ref_=ttvi_vi_imdb_1", 5);
			Film film_6("Fight Club", "Drama", "1999", "www.imdb.com/video/vi781228825", 6);
			Film film_7("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 7);
			Film film_8("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 8);
			Film film_9("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 9);
			Film film_10("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 10);
			Film film_11("Example2", "Drama", "1879", "www.example2-link.com/asgh38adf", 11);
			Film film_12("Example3", "Sci-Fi", "2014", "www.example3-link.com/hsaf832uhjid832", 12);
			Film film_13("Example4", "Horror", "2015", "www.example4-link.com/g43rgsfgw", 13);
			Film film_14("Example5", "Horror", "2007", "www.example5-link.com/gh2389gygwhjd982", 14);
			Film film_15("Example6", "Thriller", "2002", "www.example6-link.com/gh238g928G@$GW", 15);

			TestFilmContainer.push_back(film_1);
			TestFilmContainer.push_back(film_2);
			TestFilmContainer.push_back(film_3);
			TestFilmContainer.push_back(film_4);
			TestFilmContainer.push_back(film_5);
			TestFilmContainer.push_back(film_6);
			TestFilmContainer.push_back(film_7);
			TestFilmContainer.push_back(film_8);
			TestFilmContainer.push_back(film_9);
			TestFilmContainer.push_back(film_10);
			TestFilmContainer.push_back(film_11);
			TestFilmContainer.push_back(film_12);
			TestFilmContainer.push_back(film_13);
			TestFilmContainer.push_back(film_14);
			TestFilmContainer.push_back(film_15);

			for (int i = 0; i < TestFilmContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmContainer[i]));
			}

			for (int i = 0; i < TestFilmContainer.size(); i++)
			{
				Assert::IsFalse(TesterWatchList.add_film_to_watchlist(TestFilmContainer[i]));
			}
		}

		TEST_METHOD(GetWatchList)
		{
			WatchList TesterWatchList;

			vector<Film> TestFilmContainer;
			vector<Film> GetWatchListTesterVector;

			Assert::IsTrue(TesterWatchList.get_watchlist().empty());

			Film film_1("Interstellar", "Sci-Fi", "2014", "www.imdb.com/video/vi1586278169?playlistId=tt0816692&ref_=tt_ov_vi", 1);
			Film film_2("Joker", "Drama", "2019", "www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2", 2);
			Film film_3("The Godfather", "Drama", "1972", "www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1", 3);
			Film film_4("The Dark Knight", "Action", "2008", "www.imdb.com/video/vi324468761?ref_=ttvi_vi_imdb_1", 4);
			Film film_5("The Lord of the Rings: The Return of the King", "Adventure", "2003", "www.imdb.com/video/vi2073101337?ref_=ttvi_vi_imdb_1", 5);
			Film film_6("Fight Club", "Drama", "1999", "www.imdb.com/video/vi781228825", 6);
			Film film_7("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 7);
			Film film_8("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 8);
			Film film_9("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 9);
			Film film_10("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 10);
			Film film_11("Example2", "Drama", "1879", "www.example2-link.com/asgh38adf", 11);
			Film film_12("Example3", "Sci-Fi", "2014", "www.example3-link.com/hsaf832uhjid832", 12);
			Film film_13("Example4", "Horror", "2015", "www.example4-link.com/g43rgsfgw", 13);
			Film film_14("Example5", "Horror", "2007", "www.example5-link.com/gh2389gygwhjd982", 14);
			Film film_15("Example6", "Thriller", "2002", "www.example6-link.com/gh238g928G@$GW", 15);

			TestFilmContainer.push_back(film_1);
			TestFilmContainer.push_back(film_2);
			TestFilmContainer.push_back(film_3);
			TestFilmContainer.push_back(film_4);
			TestFilmContainer.push_back(film_5);
			TestFilmContainer.push_back(film_6);
			TestFilmContainer.push_back(film_7);
			TestFilmContainer.push_back(film_8);
			TestFilmContainer.push_back(film_9);
			TestFilmContainer.push_back(film_10);
			TestFilmContainer.push_back(film_11);
			TestFilmContainer.push_back(film_12);
			TestFilmContainer.push_back(film_13);
			TestFilmContainer.push_back(film_14);
			TestFilmContainer.push_back(film_15);

			for (int i = 0; i < TestFilmContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmContainer[i]));
			}

			GetWatchListTesterVector = TesterWatchList.get_watchlist();

			Assert::IsTrue(TestFilmContainer.size() == GetWatchListTesterVector.size());

			for (int i = 0; i < GetWatchListTesterVector.size(); i++)
			{
				Assert::AreEqual(TestFilmContainer[i].get_id(), GetWatchListTesterVector[i].get_id());
				Assert::AreEqual(TestFilmContainer[i].get_title(), GetWatchListTesterVector[i].get_title());
				Assert::AreEqual(TestFilmContainer[i].get_trailer(), GetWatchListTesterVector[i].get_trailer());
				Assert::AreEqual(TestFilmContainer[i].get_year(), GetWatchListTesterVector[i].get_year());
				Assert::AreEqual(TestFilmContainer[i].get_number_likes(), GetWatchListTesterVector[i].get_number_likes());
				Assert::AreEqual(TestFilmContainer[i].get_genre(), GetWatchListTesterVector[i].get_genre());
			}

		}

		TEST_METHOD(RemoveFilmFromWatchList)
		{
			WatchList TesterWatchList;

			vector<Film> TestFilmContainer;

			Assert::IsFalse(TesterWatchList.remove_film_from_watchlist(0));

			Film film_1("Interstellar", "Sci-Fi", "2014", "www.imdb.com/video/vi1586278169?playlistId=tt0816692&ref_=tt_ov_vi", 14);
			Film film_2("Joker", "Drama", "2019", "www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2", 13);
			Film film_3("The Godfather", "Drama", "1972", "www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1", 12);
			Film film_4("The Dark Knight", "Action", "2008", "www.imdb.com/video/vi324468761?ref_=ttvi_vi_imdb_1", 11);
			Film film_5("The Lord of the Rings: The Return of the King", "Adventure", "2003", "www.imdb.com/video/vi2073101337?ref_=ttvi_vi_imdb_1", 10);
			Film film_6("Fight Club", "Drama", "1999", "www.imdb.com/video/vi781228825", 9);
			Film film_7("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 8);
			Film film_8("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 7);
			Film film_9("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 6);
			Film film_10("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 5);
			Film film_11("Example2", "Drama", "1879", "www.example2-link.com/asgh38adf", 4);
			Film film_12("Example3", "Sci-Fi", "2014", "www.example3-link.com/hsaf832uhjid832", 3);
			Film film_13("Example4", "Horror", "2015", "www.example4-link.com/g43rgsfgw", 2);
			Film film_14("Example5", "Horror", "2007", "www.example5-link.com/gh2389gygwhjd982", 1);
			Film film_15("Example6", "Thriller", "2002", "www.example6-link.com/gh238g928G@$GW", 0);

			TestFilmContainer.push_back(film_1);
			TestFilmContainer.push_back(film_2);
			TestFilmContainer.push_back(film_3);
			TestFilmContainer.push_back(film_4);
			TestFilmContainer.push_back(film_5);
			TestFilmContainer.push_back(film_6);
			TestFilmContainer.push_back(film_7);
			TestFilmContainer.push_back(film_8);
			TestFilmContainer.push_back(film_9);
			TestFilmContainer.push_back(film_10);
			TestFilmContainer.push_back(film_11);
			TestFilmContainer.push_back(film_12);
			TestFilmContainer.push_back(film_13);
			TestFilmContainer.push_back(film_14);
			TestFilmContainer.push_back(film_15);

			for (int i = 0; i < TestFilmContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmContainer[i]));
			}

			for (int i = 0; i < TestFilmContainer.size(); i++)
			{
				if (i == 0)
					Assert::IsTrue(TesterWatchList.get_watchlist().size() == TestFilmContainer.size());
				else
					Assert::IsFalse(TesterWatchList.get_watchlist().size() == TestFilmContainer.size());

				Assert::IsTrue(TesterWatchList.remove_film_from_watchlist(i));
				Assert::IsTrue(TesterWatchList.get_watchlist().size() == TestFilmContainer.size() - i - 1);

				if (i == TestFilmContainer.size() - 1)
					Assert::IsTrue(TesterWatchList.get_watchlist().empty());
			}

		}
	};
}
