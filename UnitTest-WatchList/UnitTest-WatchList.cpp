#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB5_OOP/Film.h"
#include "../LAB5_OOP/Validate.h"
#include "../LAB5_OOP/WatchList.h"
#include "../LAB5_OOP/Repository.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestWatchList
{
	TEST_CLASS(WatchListClass)
	{
	public:
		
		TEST_METHOD(AddFilmToWatchList)
		{
			WatchList TesterWatchList;

			vector<int> TestFilmIdContainer;

			Assert::IsTrue(TesterWatchList.get_watchlist().empty());

			int film_1_id(1);
			int film_2_id(2);
			int film_3_id(3);
			int film_4_id(4);
			int film_5_id(5);
			int film_6_id(6);
			int film_7_id(7);
			int film_8_id(8);
			int film_9_id(9);
			int film_10_id(10);
			int film_11_id(11);
			int film_12_id(12);
			int film_13_id(13);
			int film_14_id(14);
			int film_15_id(15);

			TestFilmIdContainer.push_back(film_1_id);
			TestFilmIdContainer.push_back(film_2_id);
			TestFilmIdContainer.push_back(film_3_id);
			TestFilmIdContainer.push_back(film_4_id);
			TestFilmIdContainer.push_back(film_5_id);
			TestFilmIdContainer.push_back(film_6_id);
			TestFilmIdContainer.push_back(film_7_id);
			TestFilmIdContainer.push_back(film_8_id);
			TestFilmIdContainer.push_back(film_9_id);
			TestFilmIdContainer.push_back(film_10_id);
			TestFilmIdContainer.push_back(film_11_id);
			TestFilmIdContainer.push_back(film_12_id);
			TestFilmIdContainer.push_back(film_13_id);
			TestFilmIdContainer.push_back(film_14_id);
			TestFilmIdContainer.push_back(film_15_id);

			for (int i = 0; i < TestFilmIdContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmIdContainer[i]));
			}

			for (int i = 0; i < TestFilmIdContainer.size(); i++)
			{
				Assert::IsFalse(TesterWatchList.add_film_to_watchlist(TestFilmIdContainer[i]));
			}
		}

		TEST_METHOD(GetWatchList)
		{
			WatchList TesterWatchList;

			vector<int> TestFilmIdContainer;
			vector<int> GetWatchListTesterVector;

			Assert::IsTrue(TesterWatchList.get_watchlist().empty());

			int film_1_id(1);
			int film_2_id(2);
			int film_3_id(3);
			int film_4_id(4);
			int film_5_id(5);
			int film_6_id(6);
			int film_7_id(7);
			int film_8_id(8);
			int film_9_id(9);
			int film_10_id(10);
			int film_11_id(11);
			int film_12_id(12);
			int film_13_id(13);
			int film_14_id(14);
			int film_15_id(15);

			TestFilmIdContainer.push_back(film_1_id);
			TestFilmIdContainer.push_back(film_2_id);
			TestFilmIdContainer.push_back(film_3_id);
			TestFilmIdContainer.push_back(film_4_id);
			TestFilmIdContainer.push_back(film_5_id);
			TestFilmIdContainer.push_back(film_6_id);
			TestFilmIdContainer.push_back(film_7_id);
			TestFilmIdContainer.push_back(film_8_id);
			TestFilmIdContainer.push_back(film_9_id);
			TestFilmIdContainer.push_back(film_10_id);
			TestFilmIdContainer.push_back(film_11_id);
			TestFilmIdContainer.push_back(film_12_id);
			TestFilmIdContainer.push_back(film_13_id);
			TestFilmIdContainer.push_back(film_14_id);
			TestFilmIdContainer.push_back(film_15_id);

			for (int i = 0; i < TestFilmIdContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmIdContainer[i]));
			}

			GetWatchListTesterVector = TesterWatchList.get_watchlist();

			Assert::IsTrue(TestFilmIdContainer.size() == GetWatchListTesterVector.size());

			for (int i = 0; i < GetWatchListTesterVector.size(); i++)
			{
				Assert::AreEqual(TestFilmIdContainer[i], GetWatchListTesterVector[i]);
			}

		}

		TEST_METHOD(RemoveFilmFromWatchList)
		{
			WatchList TesterWatchList;

			vector<int> TestFilmIdContainer;

			Assert::IsFalse(TesterWatchList.remove_film_from_watchlist(0));

			int film_1_id(14);
			int film_2_id(13);
			int film_3_id(12);
			int film_4_id(11);
			int film_5_id(10);
			int film_6_id(9);
			int film_7_id(8);
			int film_8_id(7);
			int film_9_id(6);
			int film_10_id(5);
			int film_11_id(4);
			int film_12_id(3);
			int film_13_id(2);
			int film_14_id(1);
			int film_15_id(0);

			TestFilmIdContainer.push_back(film_1_id);
			TestFilmIdContainer.push_back(film_2_id);
			TestFilmIdContainer.push_back(film_3_id);
			TestFilmIdContainer.push_back(film_4_id);
			TestFilmIdContainer.push_back(film_5_id);
			TestFilmIdContainer.push_back(film_6_id);
			TestFilmIdContainer.push_back(film_7_id);
			TestFilmIdContainer.push_back(film_8_id);
			TestFilmIdContainer.push_back(film_9_id);
			TestFilmIdContainer.push_back(film_10_id);
			TestFilmIdContainer.push_back(film_11_id);
			TestFilmIdContainer.push_back(film_12_id);
			TestFilmIdContainer.push_back(film_13_id);
			TestFilmIdContainer.push_back(film_14_id);
			TestFilmIdContainer.push_back(film_15_id);

			for (int i = 0; i < TestFilmIdContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmIdContainer[i]));
			}

			for (int i = 0; i < TestFilmIdContainer.size(); i++)
			{
				if (i == 0)
					Assert::IsTrue(TesterWatchList.get_watchlist().size() == TestFilmIdContainer.size());
				else
					Assert::IsFalse(TesterWatchList.get_watchlist().size() == TestFilmIdContainer.size());

				Assert::IsTrue(TesterWatchList.remove_film_from_watchlist(i));
				Assert::IsTrue(TesterWatchList.get_watchlist().size() == TestFilmIdContainer.size() - i - 1);

				if (i == TestFilmIdContainer.size() - 1)
					Assert::IsTrue(TesterWatchList.get_watchlist().empty());
			}

		}

		TEST_METHOD(FindFilmById)
		{
			WatchList TesterWatchList;

			vector<int> TestFilmIdContainer;

			Assert::IsTrue(TesterWatchList.get_watchlist().empty());

			int film_1_id(14);
			int film_2_id(13);
			int film_3_id(12);
			int film_4_id(11);
			int film_5_id(10);
			int film_6_id(9);
			int film_7_id(8);
			int film_8_id(7);
			int film_9_id(6);
			int film_10_id(5);
			int film_11_id(4);
			int film_12_id(3);
			int film_13_id(2);
			int film_14_id(1);
			int film_15_id(0);

			TestFilmIdContainer.push_back(film_1_id);
			TestFilmIdContainer.push_back(film_2_id);
			TestFilmIdContainer.push_back(film_3_id);
			TestFilmIdContainer.push_back(film_4_id);
			TestFilmIdContainer.push_back(film_5_id);
			TestFilmIdContainer.push_back(film_6_id);
			TestFilmIdContainer.push_back(film_7_id);
			TestFilmIdContainer.push_back(film_8_id);
			TestFilmIdContainer.push_back(film_9_id);
			TestFilmIdContainer.push_back(film_10_id);
			TestFilmIdContainer.push_back(film_11_id);
			TestFilmIdContainer.push_back(film_12_id);
			TestFilmIdContainer.push_back(film_13_id);
			TestFilmIdContainer.push_back(film_14_id);
			TestFilmIdContainer.push_back(film_15_id);

			for (int i = 0; i < TestFilmIdContainer.size(); i++)
			{
				Assert::IsTrue(TesterWatchList.add_film_to_watchlist(TestFilmIdContainer[i]));
			}

			for (int i = 0; i < TesterWatchList.get_watchlist().size(); i++)
			{
				Assert::IsTrue(TesterWatchList.find_film_by_id(i));
			}

		}
	};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of UnitTest-WatchList.cpp
////////////////////////////////////////////////////////////////////////////////////////////////////

