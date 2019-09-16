#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<int>> baseball)
{
	int answer = 0;
	
	map<int, bool> tempArray;

	int strikeNum = baseball[0][1];

	int firstNum = baseball[0][0] / 100;
	int secondNum = baseball[0][0] % 100 / 10;
	int thirdNum = baseball[0][0] % 10;

	if (strikeNum == 3)
	{
		return 1;
	}
	else if (strikeNum == 2)
	{
		// first & second
		for (int i = 1; i < 10; ++i)
		{
			if (i == firstNum || i == secondNum || i == thirdNum) continue;
			tempArray.insert(make_pair<int, bool>(firstNum * 100 + secondNum * 10 + i, true));
			tempArray.insert(make_pair<int, bool>(firstNum * 100 + i * 10 + thirdNum, true));
			tempArray.insert(make_pair<int, bool>(i * 100 + secondNum * 10 + thirdNum, true));
		}
	}
	else if (strikeNum == 1)
	{
		if (baseball[0][2] == 2)
		{
			// first
			tempArray.insert(make_pair<int, bool>(firstNum * 100 + thirdNum * 10 + secondNum, true));

			// second
			tempArray.insert(make_pair<int, bool>(thirdNum * 100 + secondNum * 10 + firstNum, true));

			// third
			tempArray.insert(make_pair<int, bool>(secondNum * 100 + firstNum * 10 + thirdNum, true));
		}
		else if (baseball[0][2] == 1)
		{
			// first : S & second : B
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(firstNum * 100 + i * 10 + secondNum, true));
			}

			// first : S & third : B
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(firstNum * 100 + thirdNum * 10 + i, true));
			}

			// second : S & first : B
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(i * 100 + secondNum * 10 + firstNum, true));
			}

			// second : S & third : B
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(thirdNum * 100 + secondNum * 10 + i, true));
			}

			// third : S & first : B
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(i * 100 + firstNum * 10 + thirdNum, true));
			}

			// third : S & second : B
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(secondNum * 100 + i * 10 + thirdNum, true));
			}
		}
		else
		{
			// first
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == secondNum || j == thirdNum || i == thirdNum || j == secondNum || i == firstNum || j == firstNum) continue;
					tempArray.insert(make_pair<int, bool>(firstNum * 100 + i * 10 + j, true));
				}
			}

			// second
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == secondNum || j == thirdNum || i == thirdNum || j == secondNum || i == firstNum || j == firstNum) continue;
					tempArray.insert(make_pair<int, bool>(i * 100 + secondNum * 10 + j, true));
				}
			}

			// third
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == secondNum || j == thirdNum || i == thirdNum || j == secondNum || i == firstNum || j == firstNum) continue;
					tempArray.insert(make_pair<int, bool>(i * 100 + j * 10 + thirdNum, true));
				}
			}
		}
	}
	else
	{
		if (baseball[0][2] == 3)
		{
			tempArray.insert(make_pair<int, bool>(thirdNum * 100 + firstNum * 10 + secondNum, true));
			tempArray.insert(make_pair<int, bool>(secondNum * 100 + thirdNum * 10 + firstNum, true));
		}
		else if (baseball[0][2] == 2)
		{
			// first & second
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(secondNum * 100 + firstNum * 10 + i, true));
			}

			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(i * 100 + firstNum * 10 + secondNum, true));
			}

			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(secondNum * 100 + i * 10 + firstNum, true));
			}

			// first & third
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(thirdNum * 100 + firstNum * 10 + i, true));
			}

			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(thirdNum * 100 + i * 10 + firstNum, true));
			}

			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(i * 100 + thirdNum * 10 + firstNum, true));
			}

			// second & third
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(secondNum * 100 + thirdNum * 10 + i, true));
			}

			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(i * 100 + thirdNum * 10 + secondNum, true));
			}

			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.insert(make_pair<int, bool>(thirdNum * 100 + i * 10 + secondNum, true));
			}
		}
		else if (baseball[0][2] == 1)
		{
			// first
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
					tempArray.insert(make_pair<int, bool>(i * 100 + firstNum * 10 + j, true));
				}
			}

			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
					tempArray.insert(make_pair<int, bool>(i * 100 + j * 10 + firstNum, true));
				}
			}

			// second
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
					tempArray.insert(make_pair<int, bool>(secondNum * 100 + i * 10 + j, true));
				}
			}

			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
					tempArray.insert(make_pair<int, bool>(i * 100 + j * 10 + secondNum, true));
				}
			}

			// third
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
					tempArray.insert(make_pair<int, bool>(thirdNum * 100 + i * 10 + j, true));
				}
			}

			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
					tempArray.insert(make_pair<int, bool>(i * 100 + thirdNum * 10 + j, true));
				}
			}
		}
		else
		{
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 1; j < 10; ++j)
				{
					for (int k = 1; k < 10; ++k)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum || k == firstNum || k == secondNum || k == thirdNum) continue;
						tempArray.insert(make_pair<int, bool>(i * 100 + j * 10 + k, true));
					}
				}
			}
		}
	}



	for (int bb = 1; bb < baseball.size(); ++bb)
	{
		firstNum = baseball[bb][0] / 100;
		secondNum = baseball[bb][0] % 100 / 10;
		thirdNum = baseball[bb][0] % 10;

		for (pair<int, bool> pp : tempArray)
		{
			pp.second = true;
		}

		if (baseball[bb][1] == 3) return 1;
		else if (baseball[bb][1] == 2)
		{
			// first & second
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.find(firstNum * 100 + secondNum * 10 + i)->second = false;
			}

			// first & third
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.find(firstNum * 100 + i * 10 + thirdNum)->second = false;
			}

			// second & third
			for (int i = 1; i < 10; ++i)
			{
				if (i == firstNum || i == secondNum || i == thirdNum) continue;
				tempArray.find(i * 100 + secondNum * 10 + thirdNum)->second = false;
			}
		}
		else if (baseball[bb][1] == 1)
		{
			if (baseball[bb][2] == 2)
			{
				// first
				tempArray.find(firstNum * 100 + thirdNum * 10 + secondNum)->second = false;

				// second
				tempArray.find(thirdNum * 100 + secondNum * 10 + firstNum)->second = false;

				// third
				tempArray.find(secondNum * 100 + firstNum * 10 + thirdNum)->second = false;
			}
			else if (baseball[bb][2] == 1)
			{
				// first : S & second : B
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(firstNum * 100 + i * 10 + secondNum)->second = false;
				}

				// first : S & third : B
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(firstNum * 100 + thirdNum * 10 + i)->second = false;
				}

				// second : S & first : B
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(i * 100 + secondNum * 10 + firstNum)->second = false;
				}

				// second : S & third : B
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(thirdNum * 100 + secondNum * 10 + i)->second = false;
				}

				// third : S & first : B
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(i * 100 + firstNum * 10 + thirdNum)->second = false;
				}

				// third : S & second : B
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(secondNum * 100 + i * 10 + thirdNum)->second = false;
				}
			}
			else
			{
				// first
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == secondNum || j == thirdNum || i == thirdNum || j == secondNum || i == firstNum || j == firstNum) continue;
						tempArray.find(firstNum * 100 + i * 10 + j)->second = false;
					}
				}

				// second
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == secondNum || j == thirdNum || i == thirdNum || j == secondNum || i == firstNum || j == firstNum) continue;
						tempArray.find(i * 100 + secondNum * 10 + j)->second = false;
					}
				}

				// third
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == secondNum || j == thirdNum || i == thirdNum || j == secondNum || i == firstNum || j == firstNum) continue;
						tempArray.find(i * 100 + j * 10 + thirdNum)->second = false;
					}
				}
			}
		}
		else
		{
			if (baseball[bb][2] == 3)
			{
				tempArray.find(thirdNum * 100 + firstNum * 10 + secondNum)->second = false;
				tempArray.find(secondNum * 100 + thirdNum * 10 + firstNum)->second = false;
			}
			else if (baseball[bb][2] == 2)
			{
				// first & second
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(secondNum * 100 + firstNum * 10 + i)->second = false;
				}

				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(i * 100 + firstNum * 10 + secondNum)->second = false;
				}

				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(secondNum * 100 + i * 10 + firstNum)->second = false;
				}

				// first & third
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(thirdNum * 100 + firstNum * 10 + i)->second = false;
				}

				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(thirdNum * 100 + i * 10 + firstNum)->second = false;
				}

				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(i * 100 + thirdNum * 10 + firstNum)->second = false;
				}

				// second & third
				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(secondNum * 100 + thirdNum * 10 + i)->second = false;
				}

				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(i * 100 + thirdNum * 10 + secondNum)->second = false;
				}

				for (int i = 1; i < 10; ++i)
				{
					if (i == firstNum || i == secondNum || i == thirdNum) continue;
					tempArray.find(thirdNum * 100 + i * 10 + secondNum)->second = false;
				}
			}
			else if (baseball[bb][2] == 1)
			{
				// first
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
						tempArray.find(i * 100 + firstNum * 10 + j)->second = false;
					}
				}

				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
						tempArray.find(i * 100 + j * 10 + firstNum)->second = false;
					}
				}

				// second
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
						tempArray.find(secondNum * 100 + i * 10 + j)->second = false;
					}
				}

				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
						tempArray.find(i * 100 + j * 10 + secondNum)->second = false;
					}
				}

				// third
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
						tempArray.find(thirdNum * 100 + i * 10 + j)->second = false;
					}
				}

				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum) continue;
						tempArray.find(i * 100 + thirdNum * 10 + j)->second = false;
					}
				}
			}
			else
			{
				for (int i = 1; i < 10; ++i)
				{
					for (int j = 1; j < 10; ++j)
					{
						for (int k = 1; k < 10; ++k)
						{
							if (i == firstNum || i == secondNum || i == thirdNum || j == firstNum || j == secondNum || j == thirdNum || k == firstNum || k == secondNum || k == thirdNum) continue;
							tempArray.find(i * 100 + j * 10 + k)->second = false;
						}
					}
				}
			}
		}

		for (pair<int, bool> pp : tempArray)
		{
			if (pp.second == true)
			{
				tempArray.erase(pp.first);
			}
		}
	}


	return tempArray.size();
}

int main()
{
	vector<vector<int>> baseball = { { 123, 1, 1 }, { 356, 1, 0 }, { 327, 2, 0 }, { 489, 0, 1 } };

	cout << solution(baseball) << "\n\n";

	getchar();

	return 0;
}