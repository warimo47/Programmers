#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int date2Num(string date)
{
	string mounth = date.substr(5, 2);

	int returnValue = 0;

	if (mounth.compare("01") == 0)
	{
		returnValue = 0;
	}
	else if (mounth.compare("02") == 0)
	{
		returnValue = 31;
	}
	else if (mounth.compare("03") == 0)
	{
		returnValue = 31 + 28;
	}
	else if (mounth.compare("04") == 0)
	{
		returnValue = 31 + 28 + 31;
	}
	else if (mounth.compare("05") == 0)
	{
		returnValue = 31 + 28 + 31 + 30;
	}
	else if (mounth.compare("06") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31;
	}
	else if (mounth.compare("07") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31 + 30;
	}
	else if (mounth.compare("08") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31 + 30 + 31;
	}
	else if (mounth.compare("09") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
	}
	else if (mounth.compare("10") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
	}
	else if (mounth.compare("11") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
	}
	else if (mounth.compare("12") == 0)
	{
		returnValue = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
	}

	string dates = date.substr(8, 2);

	return returnValue + stoi(dates) - 1;
}

int getPrice(string dayPrice)
{
	return stoi(dayPrice.substr(11, dayPrice.size() - 10));
}

vector<int> solution(vector<string> purchase)
{
	vector<int> answer = {0, 0, 0, 0, 0};

	// queue<int, int> timerQueue;

	int dayNum = 0;
	int tempPrice = 0;

	vector<int> gradeList;

	for (int i = 0; i < 365; ++i)
	{
		gradeList.push_back(0);
	}

	vector<pair<int, int>> eventList;

	for (int i = 0; i < purchase.size(); ++i)
	{
		dayNum = date2Num(purchase[i]);

		tempPrice = getPrice(purchase[i]);

		eventList.push_back(pair<int, int>(dayNum, tempPrice));
		eventList.push_back(pair<int, int>(dayNum + 30, -tempPrice));
	}

	eventList.push_back(pair<int, int>(3000, 0));

	sort(eventList.begin(), eventList.end());

	int eventIndex = 0;
	int nowPrice = 0;
	int nowGrade = 0;

	for (int i = 0; i < 365; ++i)
	{
		if (i == eventList[eventIndex].first)
		{
			nowPrice += eventList[eventIndex].second;

			eventIndex++;

			if (nowPrice < 10000)
			{
				nowGrade = 0;
			}
			else if (nowPrice < 20000)
			{
				nowGrade = 1;
			}
			else if (nowPrice < 50000)
			{
				nowGrade = 2;
			}
			else if (nowPrice < 100000)
			{
				nowGrade = 3;
			}
			else
			{
				nowGrade = 4;
			}
		}

		gradeList[i] = nowGrade;
	}

	for (int i = 0; i < 365; ++i)
	{
		answer[gradeList[i]]++;
	}

	return answer;
}

int main()
{
	vector<int> answer = solution({ "2019/01/01 5000", "2019/01/20 15000", "2019/02/09 90000" });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	answer = solution({ "2019/01/30 5000", "2019/04/05 10000", "2019/06/10 20000", "2019/08/15 50000", "2019/12/01 100000" });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	answer = solution({});

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	getchar();

	return 0;
}