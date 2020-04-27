#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB5_OOP/Film.h"
#include "../LAB5_OOP/Validate.h"
#include "../LAB5_OOP/Repository.h"
#include "../LAB5_OOP/WatchList.h"

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

			WatchList TesterWatchList;
			Repository TesterRepository;

			Assert::IsTrue(TesterRepository.isEmpty());
			Assert::IsTrue(TesterWatchList.isEmpty());

			vector<int> AllIdVector;

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

			int film_1_id(175);
			int film_2_id(25735);
			int film_3_id(3753755);
			int film_4_id(4225);
			int film_5_id(55243);
			int film_6_id(6752);
			int film_7_id(77352);
			int film_8_id(824);
			int film_9_id(972);
			int film_10_id(10547);
			int film_11_id(11275);
			int film_12_id(12275);
			int film_13_id(130);
			int film_14_id(1475);
			int film_15_id(1531357);

			TesterRepository.add_film(film_1);
			TesterRepository.add_film(film_2);
			TesterRepository.add_film(film_3);
			TesterRepository.add_film(film_4);
			TesterRepository.add_film(film_5);
			TesterRepository.add_film(film_6);
			TesterRepository.add_film(film_7);
			TesterRepository.add_film(film_8);
			TesterRepository.add_film(film_9);
			TesterRepository.add_film(film_10);
			TesterRepository.add_film(film_11);
			TesterRepository.add_film(film_12);
			TesterRepository.add_film(film_13);
			TesterRepository.add_film(film_14);
			TesterRepository.add_film(film_15);

			AllIdVector.push_back(film_1_id);
			AllIdVector.push_back(film_2_id);
			AllIdVector.push_back(film_3_id);
			AllIdVector.push_back(film_4_id);
			AllIdVector.push_back(film_5_id);
			AllIdVector.push_back(film_6_id);
			AllIdVector.push_back(film_7_id);
			AllIdVector.push_back(film_8_id);
			AllIdVector.push_back(film_9_id);
			AllIdVector.push_back(film_10_id);
			AllIdVector.push_back(film_11_id);
			AllIdVector.push_back(film_12_id);
			AllIdVector.push_back(film_13_id);
			AllIdVector.push_back(film_14_id);
			AllIdVector.push_back(film_15_id);

			for (int i = 0; i < 15; i++)
			{
				TesterWatchList.add_film_to_watchlist(AllIdVector[i]);
			}

			for (int i = 0; i < AllIdVector.size(); i++)
			{
				Assert::IsFalse(v.validate_uniqueness(AllIdVector[i], TesterWatchList));
			}	

			for (int i = 0; i < AllIdVector.size(); i++)
			{
				Assert::IsTrue(v.validate_uniqueness(i, TesterWatchList));
			}

			for (int i = 0; i < AllIdVector.size(); i++)
			{
				Assert::IsFalse(v.validate_uniqueness(AllIdVector[i], TesterRepository));
			}

			for (int i = 0; i < AllIdVector.size(); i++)
			{
				Assert::IsTrue(v.validate_uniqueness(i, TesterRepository));
			}
		}
	};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of UnitTest-Validate.cpp
////////////////////////////////////////////////////////////////////////////////////////////////////

