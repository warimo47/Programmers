#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

struct work
{
	bool isRead;
	int startTime;
	int timeLength;
	int endTime;
	int startPoint;
	int endPoint;
	char newChar;
};

void changeStruct(string* pro, work *work)
{
	string subStr1 = "";

	if ((*pro)[0] == 'r')
	{
		work->isRead = true;
		subStr1 = pro->substr(5, pro->size() - 5);
	}
	else
	{
		work->isRead = false;
		subStr1 = pro->substr(6, pro->size() - 6);
	}

	string subStr2 = "";

	for (int i = 0; subStr1.size(); ++i)
	{
		if (subStr1[i] == ' ')
		{
			work->startTime = stoi(subStr1.substr(0, i));
			subStr2 = subStr1.substr(i + 1, subStr1.size() - (i + 1));
			break;
		}
	}

	for (int i = 0; subStr2.size(); ++i)
	{
		if (subStr2[i] == ' ')
		{
			work->timeLength = stoi(subStr2.substr(0, i));
			subStr1 = subStr2.substr(i + 1, subStr2.size() - (i + 1));
			break;
		}
	}

	for (int i = 0; subStr1.size(); ++i)
	{
		if (subStr1[i] == ' ')
		{
			work->startPoint = stoi(subStr1.substr(0, i));
			subStr2 = subStr1.substr(i + 1, subStr1.size() - (i + 1));
			break;
		}
	}

	if (work->isRead == true)
	{
		work->endPoint = stoi(subStr2);
	}
	else
	{
		for (int i = 0; subStr2.size(); ++i)
		{
			if (subStr2[i] == ' ')
			{
				work->endPoint = stoi(subStr2.substr(0, i));
				work->newChar = subStr2[i + 1];
				break;
			}
		}
	}
}

void fillLaftWork(vector<string>* processes, vector<work>* laftwork)
{
	work temp;

	for (string pro : *processes)
	{
		changeStruct(&pro, &temp);
		laftwork->push_back(temp);
	}
}

void processing(vector<work> *nowWork, vector<work> *waitWork, vector<work>* laftWork, string *arrStr, vector<string> *answer, int *lastNowTime, int *workingTime)
{
	int nowTime;

	if (laftWork->size() > 0)
	{
		nowTime = (*laftWork)[0].startTime;
		waitWork->push_back((*laftWork)[0]);
		laftWork->erase(laftWork->begin());
	}
	else
	{
		if (waitWork->size() > 0)
		{
			nowTime = (*waitWork)[0].startTime;
		}
		else
		{
			nowTime = (*nowWork)[0].startTime;
		}
	}

	for (int i = 0; i < nowWork->size(); ++i)
	{
		if ((*nowWork)[i].endTime <= nowTime)
		{
			nowWork->erase(nowWork->begin() + i);
			i--;
		}
	}

	bool isHaveWirte = false;
	
	if (nowWork->size() == 0)
	{
		for (int i = 0; i < waitWork->size(); ++i)
		{
			if ((*waitWork)[i].isRead == false)
			{
				isHaveWirte = true;
				(*waitWork)[i].endTime = nowTime + (*waitWork)[i].timeLength;
				nowWork->push_back((*waitWork)[i]);

				for (int t = (*waitWork)[i].startPoint; t <= (*waitWork)[i].endPoint; ++t)
				{
					(*arrStr)[t] = (*waitWork)[i].newChar;
				}

				waitWork->erase(waitWork->begin() + i);
				break;
			}
		}

		if (isHaveWirte == false)
		{
			for (int i = 0; i < waitWork->size(); ++i)
			{
				(*waitWork)[i].endTime = nowTime + (*waitWork)[i].timeLength;
				nowWork->push_back((*waitWork)[i]);

				answer->push_back(arrStr->substr((*waitWork)[i].startPoint, (*waitWork)[i].endPoint - (*waitWork)[i].startPoint + 1));
			}

			waitWork->clear();
		}
	}
	else
	{
		if ((*nowWork)[0].isRead == true)
		{
			for (int i = 0; i < waitWork->size(); ++i)
			{
				if ((*waitWork)[i].isRead == false)
				{
					isHaveWirte = true;
					break;
				}
			}

			if (isHaveWirte == false)
			{
				for (int i = 0; i < waitWork->size(); ++i)
				{
					(*waitWork)[i].endTime = nowTime + (*waitWork)[i].timeLength - 1;
					nowWork->push_back((*waitWork)[i]);
					answer->push_back(arrStr->substr((*waitWork)[i].startPoint, (*waitWork)[i].endPoint - (*waitWork)[i].startPoint + 1));
				}

				waitWork->clear();
			}
		}
	}

	(*workingTime) += nowTime - *lastNowTime;
	*lastNowTime = nowTime;
}

vector<string> solution(vector<string> arr, vector<string> processes)
{
	vector<string> answer;

	string arrStr = "";
	for (string a : arr) arrStr += a;

	vector<work> nowWork;
	vector<work> waitWork;
	vector<work> laftWork;

	fillLaftWork(&processes, &laftWork);

	int lastNowTime = 0;
	int workingTime = 1;

	while(true)
	{
		if (nowWork.size() == 0 && waitWork.size() == 0 && laftWork.size() == 0) break;

		processing(&nowWork, &waitWork, &laftWork, &arrStr, &answer, &lastNowTime, &workingTime);
	}

	answer.push_back(to_string(workingTime));

	return answer;
}

int main()
{
	vector<string> answer;
	answer = solution({ "1", "2", "4", "3", "3", "4", "1", "5" }, { "read 1 3 1 2", "read 2 6 4 7", "write 4 3 3 5 2", "read 5 2 2 5", "write 6 1 3 3 9", "read 9 1 0 7" });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution({ "1", "1", "1", "1", "1", "1", "1" }, { "write 1 12 1 5 8", "read 2 3 0 2", "read 5 5 1 2", "read 7 5 2 5", "write 13 4 0 1 3", "write 19 3 3 5 5", "read 30 4 0 6", "read 32 3 1 5" });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	getchar();

	return 0;
}