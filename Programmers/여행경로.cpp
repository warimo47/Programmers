#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool searchWay(string start, multimap<string, string> leftAirport, vector<string>* path)
{
	if (leftAirport.size() == 0) return true;

	while (true)
	{
		multimap<string, string>::iterator iter = leftAirport.lower_bound(start);
		string nextAirport = iter->second;

		leftAirport.erase(iter);

		path->push_back(nextAirport);

		if (searchWay(nextAirport, leftAirport, path) == true)
		{
			return true;
		}
	}
}

bool sortCompare(vector<string> a, vector<string> b)
{
	if (a[1].compare(b[1]) == -1)
	{
		return true;
	}
	else if (a[1].compare(b[1]) == 1)
	{
		return false;
	}
	else
	{
		return a[0].compare(b[0]) == -1;
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	sort(tickets.begin(), tickets.end(), sortCompare);

	multimap<string, string> airport;

	for (int i = 0; i < tickets.size(); ++i)
	{
		// sort(tickets[i].begin(), tickets[i].end());
		airport.insert(pair<string, string>(tickets[i][0], tickets[i][1]));
	}

	vector<string> path;
	path.push_back("ICN");

	searchWay("ICN", airport, &path);

	return path;
}

int main()
{
	vector<string> answer;

	answer = solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";
	
	answer = solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";

	getchar();

	return 0;
}