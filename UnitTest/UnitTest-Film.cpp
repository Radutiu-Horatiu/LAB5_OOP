#include "pch.h"
#include "CppUnitTest.h"
#include"../LAB5_OOP/Film.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFilm
{
	TEST_CLASS(FilmClass)
	{
	public:
		
		TEST_METHOD(ConstructorTests)
		{
			/* Test - 1 */
			Film filmTesterObject_1;
			
			Assert::AreEqual(string("?"), filmTesterObject_1.get_title());
			Assert::AreEqual(string("?"), filmTesterObject_1.get_genre());
			Assert::AreEqual(string("?"), filmTesterObject_1.get_year());
			Assert::AreEqual(string("?"), filmTesterObject_1.get_trailer());
			Assert::AreEqual(0, filmTesterObject_1.get_number_likes());
			Assert::AreEqual(0, filmTesterObject_1.get_id());
			
			/* Test - 2 */
			Film filmTesterObject_2("Interstellar", "Sci-Fi", "2014", "www.imdb.com/video/vi1586278169?playlistId=tt0816692&ref_=tt_ov_vi", 7634);

			Assert::AreNotEqual(string("?"), filmTesterObject_2.get_title());
			Assert::AreNotEqual(string("?"), filmTesterObject_2.get_genre());
			Assert::AreNotEqual(string("?"), filmTesterObject_2.get_year());
			Assert::AreNotEqual(string("?"), filmTesterObject_2.get_trailer());
			Assert::AreEqual(0, filmTesterObject_2.get_number_likes());
			Assert::AreNotEqual(0, filmTesterObject_2.get_id());

			Assert::AreEqual(string("Interstellar"), filmTesterObject_2.get_title());
			Assert::AreEqual(string("Sci-Fi"), filmTesterObject_2.get_genre());
			Assert::AreEqual(string("2014"), filmTesterObject_2.get_year());
			Assert::AreEqual(string("www.imdb.com/video/vi1586278169?playlistId=tt0816692&ref_=tt_ov_vi"), filmTesterObject_2.get_trailer());
			Assert::AreEqual(7634, filmTesterObject_2.get_id());


			/* Test - 3 */
			Film filmTesterObject_3("Joker", "Drama", "2019", "www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2", 9867);
			
			Assert::AreNotEqual(string("?"), filmTesterObject_3.get_title());
			Assert::AreNotEqual(string("?"), filmTesterObject_3.get_genre());
			Assert::AreNotEqual(string("?"), filmTesterObject_3.get_year());
			Assert::AreNotEqual(string("?"), filmTesterObject_3.get_trailer());
			Assert::AreEqual(0, filmTesterObject_3.get_number_likes());
			Assert::AreNotEqual(0, filmTesterObject_3.get_id());
			
			Assert::AreEqual(string("Joker"), filmTesterObject_3.get_title());
			Assert::AreEqual(string("Drama"), filmTesterObject_3.get_genre());
			Assert::AreEqual(string("2019"), filmTesterObject_3.get_year());
			Assert::AreEqual(string("www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2"), filmTesterObject_3.get_trailer());
			Assert::AreNotEqual(string("www.imdb.com/video/vi2883960089?ref_=ttvi_vi_imdb_2 "), filmTesterObject_3.get_trailer());
			Assert::AreEqual(9867, filmTesterObject_3.get_id());
		}

		TEST_METHOD(GetterTests)
		{
			/* Test - 4 */
			Film filmTesterObject_4("The Godfather", "Drama", "1972", "www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1", 1289);
			
			Assert::AreNotEqual(string("TheGodfather"), filmTesterObject_4.get_title());
			Assert::AreEqual(string("The Godfather"), filmTesterObject_4.get_title());
			Assert::AreNotEqual(string(" Drama"), filmTesterObject_4.get_genre());
			Assert::AreEqual(string("Drama"), filmTesterObject_4.get_genre());
			Assert::AreNotEqual(string("1972 "), filmTesterObject_4.get_year());
			Assert::AreEqual(string("1972"), filmTesterObject_4.get_year());
			Assert::AreEqual(0, filmTesterObject_4.get_number_likes());
			Assert::AreEqual(1289, filmTesterObject_4.get_id());
			Assert::AreNotEqual(string(" www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1"), filmTesterObject_4.get_trailer());
			Assert::AreEqual(string("www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1"), filmTesterObject_4.get_trailer());

			/* Test - 5 */
			Film filmTesterObject_5("The Dark Knight", "Action", "2008", "www.imdb.com/video/vi324468761?ref_=ttvi_vi_imdb_1", 1290);

			Assert::AreNotEqual(string("The DarkKnight"), filmTesterObject_5.get_title());
			Assert::AreEqual(string("The Dark Knight"), filmTesterObject_5.get_title());
			Assert::AreNotEqual(string("action"), filmTesterObject_5.get_genre());
			Assert::AreEqual(string("Action"), filmTesterObject_5.get_genre());
			Assert::AreNotEqual(string("208"), filmTesterObject_5.get_year());
			Assert::AreEqual(string("2008"), filmTesterObject_5.get_year());
			Assert::AreEqual(0, filmTesterObject_5.get_number_likes());
			Assert::AreNotEqual(1290, filmTesterObject_5.get_number_likes());
			Assert::AreNotEqual(1289, filmTesterObject_5.get_id());
			Assert::AreEqual(1290, filmTesterObject_5.get_id());
			Assert::AreNotEqual(string(" www.imdb.com/video/vi1348706585?ref_=ttvi_vi_imdb_1"), filmTesterObject_5.get_trailer());
			Assert::AreNotEqual(string("www.imdb.com/video/vi324468761??ref_=ttvi_vi_imdb_1"), filmTesterObject_5.get_trailer());
			Assert::AreEqual(string("www.imdb.com/video/vi324468761?ref_=ttvi_vi_imdb_1"), filmTesterObject_5.get_trailer());
		}

		TEST_METHOD(SetterTests)
		{
			/* Test - 6 */
			Film filmTesterObject_6;

			filmTesterObject_6.set_title("The Lord of the Rings: The Return of the King");
			filmTesterObject_6.set_genre("Adventure");
			filmTesterObject_6.set_year("2003");
			filmTesterObject_6.set_trailer("www.imdb.com/video/vi2073101337?ref_=ttvi_vi_imdb_1");
			filmTesterObject_6.set_id(1784);

			Assert::AreEqual(string("The Lord of the Rings: The Return of the King"), filmTesterObject_6.get_title());
			Assert::AreNotEqual(string("The Lord of the Rings:The Return of the King"), filmTesterObject_6.get_title());
			Assert::AreEqual(string("Adventure"), filmTesterObject_6.get_genre());
			Assert::AreEqual(string("2003"), filmTesterObject_6.get_year());
			Assert::AreNotEqual(0, filmTesterObject_6.get_id());
			Assert::AreNotEqual(1784, filmTesterObject_6.get_number_likes());
			Assert::AreEqual(0, filmTesterObject_6.get_number_likes());
			filmTesterObject_6.set_number_likes(1784);
			Assert::AreEqual(1784, filmTesterObject_6.get_number_likes());
			Assert::AreEqual(filmTesterObject_6.get_id(), filmTesterObject_6.get_number_likes());
			Assert::AreEqual(string("www.imdb.com/video/vi2073101337?ref_=ttvi_vi_imdb_1"), filmTesterObject_6.get_trailer());
			Assert::AreNotEqual(string("www.imdb.com/video/vi2073101337?ref__=ttvi_vi_imdb_1"), filmTesterObject_6.get_trailer());



			/* Test - 7 */
			Film filmTesterObject_7;
			
			filmTesterObject_7.set_title("Fight Club");
			filmTesterObject_7.set_genre("Drama");
			filmTesterObject_7.set_year("1999");
			filmTesterObject_7.set_trailer("www.imdb.com/video/vi781228825");
			filmTesterObject_7.set_id(1864295);
			filmTesterObject_7.set_number_likes(1864296);

			Assert::AreNotEqual(string("Fight Club"), filmTesterObject_6.get_title());
			Assert::AreEqual(string("Fight Club"), filmTesterObject_7.get_title());
			Assert::AreNotEqual(string("199"), filmTesterObject_7.get_year());
			Assert::AreEqual(string("1999"), filmTesterObject_7.get_year());
			Assert::AreNotEqual(string("Fight Club"), filmTesterObject_7.get_genre());
			Assert::AreEqual(string("Drama"), filmTesterObject_7.get_genre());
			Assert::AreEqual(string("www.imdb.com/video/vi781228825"), filmTesterObject_7.get_trailer());
			Assert::AreNotEqual(1864295, filmTesterObject_7.get_number_likes());
			Assert::AreNotEqual(1864296, filmTesterObject_7.get_id());
			Assert::AreNotEqual(filmTesterObject_7.get_id(), filmTesterObject_7.get_number_likes());			
		}
	};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of UnitTest-Film.cpp
////////////////////////////////////////////////////////////////////////////////////////////////////

