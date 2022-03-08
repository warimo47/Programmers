#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;

	map<string, string> mmc;

	vector<pair<string, string>> events;

	string eventType = "";
	string userID = "";
	string nickName = "";

	int firstBlankPos = 0;

	for (string r : record)
	{
		eventType = "";

		if (r[0] == 'E')
		{
			eventType = "Enter";
			for (int i = 7; i < r.size(); ++i)
			{
				if (r[i] == ' ')
				{
					userID = r.substr(6, i - 6);
					nickName = r.substr(i + 1, r.size() - i);
					break;
				}
			}
		}
		else if (r[0] == 'L')
		{
			eventType = "Leave";
			userID = r.substr(6, r.size() - 6);
			nickName = "";
		}
		else
		{
			eventType = "Change";
			for (int i = 8; i < r.size(); ++i)
			{
				if (r[i] == ' ')
				{
					userID = r.substr(7, i - 7);
					nickName = r.substr(i + 1, r.size() - i);
					break;
				}
			}
		}

		if (eventType.compare("Enter") == 0)
		{
			events.push_back(pair<string, string>("Enter", userID));

			if (mmc.find(userID) == mmc.end())
			{
				mmc.insert(pair<string, string>(userID, nickName));
			}
			else
			{
				mmc.erase(userID);
				mmc.insert(pair<string, string>(userID, nickName));
			}
		}
		else if (eventType.compare("Leave") == 0)
		{
			events.push_back(pair<string, string>("Leave", userID));
		}
		else if (eventType.compare("Change") == 0)
		{
			mmc.erase(userID);
			mmc.insert(pair<string, string>(userID, nickName));
		}
	}

	for (pair<string, string> e : events)
	{
		if (e.first.compare("Enter") == 0)
		{
			answer.push_back(mmc.find(e.second)->second + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else
		{
			answer.push_back(mmc.find(e.second)->second + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}

	return answer;
}

int main()
{
	vector<string> answer = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });

	for (string a : answer)
	{
		cout << a << "\n";
	}

	cout << "\n\n";

	getchar();

	return 0;
}