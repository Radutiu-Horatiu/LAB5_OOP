#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB5_OOP/Film.h"
#include "../LAB5_OOP/Validate.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestValidate
{
	TEST_CLASS(ValidateClass)
	{
	public:
		
		TEST_METHOD(ValidateString)
		{
			Validate v;

			string test1 = "71246918246128s79804";
			string test2 = "71246918246128079804";
			string test3 = "asdasdasd";
			string test4 = "71246918246128079804s";
			string test5 = "1Hello, 1There";
			string test6 = "11111111!11111111";
			string test7 = "ASF#@A*HF#AYFH#ASF2rf3f";
			string test8 = "hjg9278uhf09WEG@$G&#@";
			string test9 = "21652166";
			string test10 = "4954f4u9yghjifj28j$@G@";

			Assert::IsTrue(v.validate_string(test1));
			Assert::IsFalse(v.validate_string(test2));
			Assert::IsTrue(v.validate_string(test3));
			Assert::IsTrue(v.validate_string(test4));
			Assert::IsTrue(v.validate_string(test5));
			Assert::IsTrue(v.validate_string(test6));
			Assert::IsTrue(v.validate_string(test7));
			Assert::IsTrue(v.validate_string(test8));
			Assert::IsFalse(v.validate_string(test9));
			Assert::IsTrue(v.validate_string(test10));
		}

		TEST_METHOD(ValidateInt)
		{
			Validate v; 

			string test1 = "71246918246128s79804";
			string test2 = "71246918246128079804";
			string test3 = "asdasdasd";
			string test4 = "71246918246128079804s";
			string test5 = "1Hello, 1There";
			string test6 = "11111111!11111111";
			string test7 = "ASF#@A*HF#AYFH#ASF2rf3f";
			string test8 = "hjg9278uhf09WEG@$G&#@";
			string test9 = "21652166";
			string test10 = "4954f4u9yghjifj28j$@G@";

			Assert::IsFalse(v.validate_int(test1));
			Assert::IsTrue(v.validate_int(test2));
			Assert::IsFalse(v.validate_int(test3));
			Assert::IsFalse(v.validate_int(test4));
			Assert::IsFalse(v.validate_int(test5));
			Assert::IsFalse(v.validate_int(test6));
			Assert::IsFalse(v.validate_int(test7));
			Assert::IsFalse(v.validate_int(test8));
			Assert::IsTrue(v.validate_int(test9));
			Assert::IsFalse(v.validate_int(test10));
		}

		TEST_METHOD(ValidateUniqueness)
		{
			Validate v;

			vector<Film> TestFilmContainer;

			Film film_1("Interstellar", "Sci-Fi", "2014", "www.imdb.com/video/vi1586278169?playlistId=tt0816692&ref_=tt_ov_vi", 175);
			Film film_2("Joker", "Drama", "2019", "www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2", 25735);
			Film film_3("The Godfather", "Drama", "1972", "www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1", 3753755);
			Film film_4("The Dark Knight", "Action", "2008", "www.imdb.com/video/vi324468761?ref_=ttvi_vi_imdb_1", 4225);
			Film film_5("The Lord of the Rings: The Return of the King", "Adventure", "2003", "www.imdb.com/video/vi2073101337?ref_=ttvi_vi_imdb_1", 55243);
			Film film_6("Fight Club", "Drama", "1999", "www.imdb.com/video/vi781228825", 6752);
			Film film_7("Forrest Gump", "Romance", "1994", "www.imdb.com/video/vi3567517977?ref_=ttvi_vi_imdb_1", 77352);
			Film film_8("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 824);
			Film film_9("Example2", "Horror", "2015", "www.example2-link.com/asfaw", 972);
			Film film_10("Example1", "Action", "2012", "www.example1-link.com/jhfiawfa", 10547);
			Film film_11("Example2", "Drama", "1879", "www.example2-link.com/asgh38adf", 11275);
			Film film_12("Example3", "Sci-Fi", "2014", "www.example3-link.com/hsaf832uhjid832", 12275);
			Film film_13("Example4", "Horror", "2015", "www.example4-link.com/g43rgsfgw", 130);
			Film film_14("Example5", "Horror", "2007", "www.example5-link.com/gh2389gygwhjd982", 1475);
			Film film_15("Example6", "Thriller", "2002", "www.example6-link.com/gh238g928G@$GW", 1531357);

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
				Assert::IsFalse(v.validate_uniqueness(TestFilmContainer[i].get_id(), TestFilmContainer));
			}	

			for (int i = 0; i < TestFilmContainer.size(); i++)
			{
				Assert::IsTrue(v.validate_uniqueness(i, TestFilmContainer));
			}
		}
	};
}
