#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB5_OOP/Repository.h"
#include "../LAB5_OOP/Film.h"
#include "../LAB5_OOP/Validate.h"
#include "../LAB5_OOP/WatchList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRepository
{
	TEST_CLASS(RepositoryClass)
	{
	public:
		
		TEST_METHOD(AddFilms)
		{
			Repository repo_1;
			Repository repo_2;

			Assert::IsTrue(repo_1.isEmpty());
			Assert::IsTrue(repo_2.isEmpty());

			Assert::IsTrue(repo_1.add_film("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 548756));
			Assert::IsFalse(repo_1.add_film("Example1", "2012", "Action", "www.example1-link.com/jhfiawfa", 25997));
			Assert::IsTrue(repo_1.add_film("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 25997));
			Assert::IsFalse(repo_1.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 25997));

			Assert::IsTrue(repo_2.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 198652));
			Assert::IsFalse(repo_2.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 198652));

			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());
		}

		TEST_METHOD(RemoveFilms)
		{
			Repository repo_1;
			Repository repo_2;

			Assert::IsTrue(repo_1.isEmpty());
			Assert::IsTrue(repo_2.isEmpty());

			repo_1.add_film("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 548756);
			repo_1.add_film("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 25997);
			repo_2.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 198652);

			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());

			Assert::IsTrue(repo_1.remove_film(548756));
			Assert::IsTrue(repo_1.remove_film(25997));
			Assert::IsFalse(repo_1.remove_film(198652));

			Assert::IsTrue(repo_2.remove_film(198652));

			Assert::IsTrue(repo_1.isEmpty());
			Assert::IsTrue(repo_2.isEmpty());

		}

		TEST_METHOD(GetFilms)
		{
			Repository repo_1;
			Repository repo_2;

			Assert::IsTrue(repo_1.isEmpty());
			Assert::IsTrue(repo_2.isEmpty());

			Assert::IsTrue(repo_1.add_film("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 548756));
			Assert::IsFalse(repo_1.add_film("Example1", "2012", "Action", "www.example1-link.com/jhfiawfa", 25997));
			Assert::IsTrue(repo_1.add_film("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 25997));
			Assert::IsFalse(repo_1.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 25997));

			Assert::IsTrue(repo_2.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 198652));
			Assert::IsFalse(repo_2.add_film("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 198652));

			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());

			vector<Film> RetunredVectorFromRepo1;
			vector<Film> RetunredVectorFromRepo2;

			Assert::IsTrue(RetunredVectorFromRepo1.empty());
			Assert::IsTrue(RetunredVectorFromRepo2.empty());

			RetunredVectorFromRepo1 = repo_1.get_films();
			RetunredVectorFromRepo2 = repo_2.get_films();

			Assert::IsFalse(RetunredVectorFromRepo1.empty());
			Assert::IsFalse(RetunredVectorFromRepo2.empty());

			Film Repo1FirstFilm;
			Film Repo2FirstFilm;

			Repo1FirstFilm = RetunredVectorFromRepo1[0];
			Repo2FirstFilm = RetunredVectorFromRepo2[0];

			Assert::AreEqual(string("Forrest Gump"), Repo1FirstFilm.get_title());
			Assert::AreEqual(string("Romance"), Repo1FirstFilm.get_genre());
			Assert::AreEqual(string("1994"), Repo1FirstFilm.get_year());
			Assert::AreEqual(string("www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1"), Repo1FirstFilm.get_trailer());
			Assert::AreEqual(548756, Repo1FirstFilm.get_id());
			Assert::AreEqual(0, Repo1FirstFilm.get_number_likes());

			Assert::AreEqual(string("Example2"), Repo2FirstFilm.get_title());
			Assert::AreEqual(string("Horror"), Repo2FirstFilm.get_genre());
			Assert::AreEqual(string("2015"), Repo2FirstFilm.get_year());
			Assert::AreEqual(string("www.example2-link.com/asfaw"), Repo2FirstFilm.get_trailer());
			Assert::AreEqual(198652, Repo2FirstFilm.get_id());
			Assert::AreEqual(0, Repo2FirstFilm.get_number_likes());

			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());
		}

		TEST_METHOD(UpdateFilms)
		{
			Repository repo_1;
			Repository repo_2;

			Assert::IsTrue(repo_1.isEmpty());
			Assert::IsTrue(repo_2.isEmpty());

			Assert::IsTrue(repo_1.add_film("Example_3", "Sci-Fi", "2018", "www.example3-link.com/jawgfbiaw3", 19465));
			Assert::IsTrue(repo_2.add_film("Example_4", "Thriller", "1995", "www.example4-link.com/54fawh8793", 1584));
	
			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());

			Assert::IsFalse(repo_1.update_film(1584, "UpdatedExample_3", "Drama", "2017", "www.UPDATEDexample3-link.com/jf382f"));
			Assert::IsTrue(repo_1.update_film(19465, "UpdatedExample_3", "Drama", "2017", "www.UPDATEDexample3-link.com/jf382f"));
			Assert::IsTrue(repo_2.update_film(1584, "UpdatedExample_4", "Horror", "2000", "www.UPDATEDexample4-link.com/jhf83af2a"));

			vector<Film> RetunredVectorFromRepo1;
			vector<Film> RetunredVectorFromRepo2;

			Assert::IsTrue(RetunredVectorFromRepo1.empty());
			Assert::IsTrue(RetunredVectorFromRepo2.empty());

			RetunredVectorFromRepo1 = repo_1.get_films();
			RetunredVectorFromRepo2 = repo_2.get_films();

			Assert::IsFalse(RetunredVectorFromRepo1.empty());
			Assert::IsFalse(RetunredVectorFromRepo2.empty());

			Film Repo1Film;
			Film Repo2Film;

			Repo1Film = RetunredVectorFromRepo1[0];
			Repo2Film = RetunredVectorFromRepo2[0];

			Assert::AreEqual(string("UpdatedExample_3"), Repo1Film.get_title());
			Assert::AreEqual(string("Drama"), Repo1Film.get_genre());
			Assert::AreEqual(string("2017"), Repo1Film.get_year());
			Assert::AreEqual(string("www.UPDATEDexample3-link.com/jf382f"), Repo1Film.get_trailer());
			Assert::AreEqual(19465, Repo1Film.get_id());
			Assert::AreEqual(0, Repo1Film.get_number_likes());

			Assert::AreEqual(string("UpdatedExample_4"), Repo2Film.get_title());
			Assert::AreEqual(string("Horror"), Repo2Film.get_genre());
			Assert::AreEqual(string("2000"), Repo2Film.get_year());
			Assert::AreEqual(string("www.UPDATEDexample4-link.com/jhf83af2a"), Repo2Film.get_trailer());
			Assert::AreEqual(1584, Repo2Film.get_id());
			Assert::AreEqual(0, Repo2Film.get_number_likes());

			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());
		}

		TEST_METHOD(ShowFilmsToUser)
		{
			Repository repo_1;
			Repository repo_2;

			Assert::IsTrue(repo_1.isEmpty());
			Assert::IsTrue(repo_2.isEmpty());

			repo_1.add_film("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 219);
			repo_1.add_film("Example2", "Drama", "1879", "www.example2-link.com/asgh38adf", 196);
			repo_1.add_film("Example3", "Sci-Fi", "2014", "www.example3-link.com/hsaf832uhjid832", 2319);

			repo_2.add_film("Example4", "Horror", "2015", "www.example4-link.com/g43rgsfgw", 198652);
			repo_2.add_film("Example5", "Horror", "2007", "www.example5-link.com/gh2389gygwhjd982", 1895196);
			repo_2.add_film("Example6", "Thriller", "2002", "www.example6-link.com/gh238g928G@$GW", 247);

			Assert::IsFalse(repo_1.isEmpty());
			Assert::IsFalse(repo_2.isEmpty());

			vector<Film> RetunredVectorFromRepo1;
			vector<Film> RetunredVectorFromRepo2;
			vector<Film> ReturnedVectorFromRepo_1_GENRES;
			vector<Film> ReturnedVectorFromRepo_2_GENRES;

			Assert::IsTrue(RetunredVectorFromRepo1.empty());
			Assert::IsTrue(RetunredVectorFromRepo2.empty());
			Assert::IsTrue(ReturnedVectorFromRepo_1_GENRES.empty());
			Assert::IsTrue(ReturnedVectorFromRepo_2_GENRES.empty());

			RetunredVectorFromRepo1 = repo_1.get_films();
			RetunredVectorFromRepo2 = repo_2.get_films();
			ReturnedVectorFromRepo_1_GENRES = repo_1.show_films_to_user("none");
			ReturnedVectorFromRepo_2_GENRES = repo_2.show_films_to_user("Action");

			Assert::IsFalse(RetunredVectorFromRepo1.empty());
			Assert::IsFalse(RetunredVectorFromRepo2.empty());
			Assert::IsFalse(ReturnedVectorFromRepo_1_GENRES.empty());
			Assert::IsFalse(ReturnedVectorFromRepo_2_GENRES.empty());


			for (int i = 0; i < RetunredVectorFromRepo1.size(); i++)
			{
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_id(), ReturnedVectorFromRepo_1_GENRES[i].get_id());
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_title(), ReturnedVectorFromRepo_1_GENRES[i].get_title());
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_trailer(), ReturnedVectorFromRepo_1_GENRES[i].get_trailer());
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_year(), ReturnedVectorFromRepo_1_GENRES[i].get_year());
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_number_likes(), ReturnedVectorFromRepo_1_GENRES[i].get_number_likes());
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_genre(), ReturnedVectorFromRepo_1_GENRES[i].get_genre());
			}

			for (int i = 0; i < RetunredVectorFromRepo2.size(); i++)
			{
				Assert::AreEqual(RetunredVectorFromRepo2[i].get_id(), ReturnedVectorFromRepo_2_GENRES[i].get_id());
				Assert::AreEqual(RetunredVectorFromRepo2[i].get_title(), ReturnedVectorFromRepo_2_GENRES[i].get_title());
				Assert::AreEqual(RetunredVectorFromRepo2[i].get_trailer(), ReturnedVectorFromRepo_2_GENRES[i].get_trailer());
				Assert::AreEqual(RetunredVectorFromRepo2[i].get_year(), ReturnedVectorFromRepo_2_GENRES[i].get_year());
				Assert::AreEqual(RetunredVectorFromRepo2[i].get_number_likes(), ReturnedVectorFromRepo_2_GENRES[i].get_number_likes());
				Assert::AreEqual(RetunredVectorFromRepo2[i].get_genre(), ReturnedVectorFromRepo_2_GENRES[i].get_genre());
			}
			
			Assert::IsTrue(RetunredVectorFromRepo1.size() == ReturnedVectorFromRepo_2_GENRES.size());

			for (int i = 0; i < RetunredVectorFromRepo1.size(); i++)
				for (int j = 0; j < ReturnedVectorFromRepo_2_GENRES.size(); j++)
			{
				Assert::AreNotEqual(RetunredVectorFromRepo1[i].get_id(), ReturnedVectorFromRepo_2_GENRES[j].get_id());
				Assert::AreNotEqual(RetunredVectorFromRepo1[i].get_title(), ReturnedVectorFromRepo_2_GENRES[j].get_title());
				Assert::AreNotEqual(RetunredVectorFromRepo1[i].get_trailer(), ReturnedVectorFromRepo_2_GENRES[j].get_trailer());
				Assert::AreNotEqual(RetunredVectorFromRepo1[i].get_year(), ReturnedVectorFromRepo_2_GENRES[j].get_year());
				Assert::AreEqual(RetunredVectorFromRepo1[i].get_number_likes(), ReturnedVectorFromRepo_2_GENRES[j].get_number_likes());
				Assert::AreNotEqual(RetunredVectorFromRepo1[i].get_genre(), ReturnedVectorFromRepo_2_GENRES[j].get_genre());
			}

			ReturnedVectorFromRepo_1_GENRES = repo_1.show_films_to_user("Action");
			ReturnedVectorFromRepo_2_GENRES = repo_2.show_films_to_user("none");

			Assert::IsFalse(ReturnedVectorFromRepo_1_GENRES.size() == 3);
			Assert::IsTrue(ReturnedVectorFromRepo_1_GENRES.size() == 1);
			Assert::IsTrue(ReturnedVectorFromRepo_1_GENRES[0].get_id() == 219);
			Assert::IsTrue(ReturnedVectorFromRepo_2_GENRES.size() == 3);

			ReturnedVectorFromRepo_1_GENRES = repo_1.show_films_to_user("Drama");
			ReturnedVectorFromRepo_2_GENRES = repo_2.show_films_to_user("thriller");

			Assert::IsTrue(ReturnedVectorFromRepo_1_GENRES.size() == ReturnedVectorFromRepo_2_GENRES.size());

			Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[0].get_id(), ReturnedVectorFromRepo_2_GENRES[0].get_id());
			Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[0].get_title(), ReturnedVectorFromRepo_2_GENRES[0].get_title());
			Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[0].get_trailer(), ReturnedVectorFromRepo_2_GENRES[0].get_trailer());
			Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[0].get_year(), ReturnedVectorFromRepo_2_GENRES[0].get_year());
			Assert::AreEqual(ReturnedVectorFromRepo_1_GENRES[0].get_number_likes(), ReturnedVectorFromRepo_2_GENRES[0].get_number_likes());
			Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[0].get_genre(), ReturnedVectorFromRepo_2_GENRES[0].get_genre());


			ReturnedVectorFromRepo_1_GENRES = repo_1.show_films_to_user("Sci-Fi");
			ReturnedVectorFromRepo_2_GENRES = repo_2.show_films_to_user("horror");

			Assert::IsFalse(ReturnedVectorFromRepo_1_GENRES.size() == ReturnedVectorFromRepo_2_GENRES.size());

			for (int i = 0; i < ReturnedVectorFromRepo_1_GENRES.size(); i++)
				for (int j = 0; j < ReturnedVectorFromRepo_2_GENRES.size(); j++)
				{
					Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[i].get_id(), ReturnedVectorFromRepo_2_GENRES[j].get_id());
					Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[i].get_title(), ReturnedVectorFromRepo_2_GENRES[j].get_title());
					Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[i].get_trailer(), ReturnedVectorFromRepo_2_GENRES[j].get_trailer());
					Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[i].get_year(), ReturnedVectorFromRepo_2_GENRES[j].get_year());
					Assert::AreEqual(ReturnedVectorFromRepo_1_GENRES[i].get_number_likes(), ReturnedVectorFromRepo_2_GENRES[j].get_number_likes());
					Assert::AreNotEqual(ReturnedVectorFromRepo_1_GENRES[i].get_genre(), ReturnedVectorFromRepo_2_GENRES[j].get_genre());
				}
		}

		TEST_METHOD(GetAndFindFilmById)
		{
			Repository repo_1;

			Assert::IsTrue(repo_1.isEmpty());

			repo_1.add_film("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 219);
			repo_1.add_film("Example2", "Drama", "1879", "www.example2-link.com/asgh38adf", 196);
			repo_1.add_film("Example3", "Sci-Fi", "2014", "www.example3-link.com/hsaf832uhjid832", 2319);

			Assert::IsFalse(repo_1.isEmpty());

			Film film1 = repo_1.get_film_by_id(219);
			Film film2 = repo_1.get_film_by_id(196);
			Film film3 = repo_1.get_film_by_id(2319);

			Assert::IsTrue(repo_1.get_films()[0] == film1);
			Assert::IsTrue(repo_1.get_films()[1] == film2);
			Assert::IsTrue(repo_1.get_films()[2] == film3);

			Assert::IsTrue(repo_1.find_film_by_id(film1.get_id()));
			Assert::IsTrue(repo_1.find_film_by_id(film2.get_id()));
			Assert::IsTrue(repo_1.find_film_by_id(film3.get_id()));
		}
	};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of UnitTest-Repository.cpp
////////////////////////////////////////////////////////////////////////////////////////////////////

