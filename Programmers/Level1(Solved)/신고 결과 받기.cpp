#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void getReport(string report, string* reporter, string* reportedUser)
{
	for (int i = 0; i < report.size(); ++i)
	{
		if (report[i] == ' ')
		{
			*reporter = report.substr(0, i);
			*reportedUser = report.substr(i + 1, report.size() - (i + 1));
			return;
		}
	}
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
	vector<int> answer;
	map<string, int> id_table;
	map<string, vector<int>> reportTable;
	vector<int> temp;

	for (int i = 0; i < id_list.size(); ++i)
	{
		temp.push_back(0);
	}

	for (int i = 0; i < id_list.size(); ++i)
	{
		answer.push_back(0);
		id_table.insert(pair<string, int>(id_list[i], i));
		reportTable.insert(pair<string, vector<int>>(id_list[i], temp));
	}

	string reporterLoopValue;
	string reportedUserLoopValue;

	for (int i = 0; i < report.size(); ++i)
	{
		getReport(report[i], &reporterLoopValue, &reportedUserLoopValue);

		reportTable[reportedUserLoopValue][id_table[reporterLoopValue]] = 1;
	}

	int reportedCount = 0;

	for (int i = 0; i < id_list.size(); ++i)
	{
		reportedCount = 0;

		for (int c = 0; c < id_list.size(); ++c)
		{
			reportedCount += reportTable[id_list[i]][c];
		}

		if (reportedCount > (k - 1))
		{
			for (int c = 0; c < id_list.size(); ++c)
			{
				if (reportTable[id_list[i]][c] == 1)
				{
					answer[c]++;
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> answer = solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" }, 2);

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	answer = solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" }, 3);

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	getchar();

	return 0;
}