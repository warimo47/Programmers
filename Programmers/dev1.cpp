#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> dist)
{
	vector<vector<int>> candidate1;
	vector<vector<int>> candidate2;

	vector<int> temp;

	temp.push_back(0);

	candidate1.push_back(temp);

	vector<int> firstLine = dist[0];

	for (int j = 1; j < firstLine.size(); ++j)
	{
		candidate2.clear();

		for (auto c1 : candidate1)
		{
			temp = c1;
			temp.push_back(firstLine[j]);
			candidate2.push_back(temp);
			temp = c1;
			temp.push_back(-firstLine[j]);
			candidate2.push_back(temp);
		}

		for (int i = 0; i < candidate2.size(); ++i)
		{
			for (int s = 1; s < j; ++s)
			{
				if ((candidate2[i][j] - candidate2[i][s]) * (candidate2[i][j] - candidate2[i][s]) != dist[s][j] * dist[s][j])
				{
					candidate2.erase(candidate2.begin() + i);
					--i;
					break;
				}
			}
		}

		candidate1 = candidate2;
	}

	vector<vector<int>> answer;
	vector<pair<int, int>> sorting;

	for (int c = 0; c < candidate1.size(); ++c)
	{
		for (int cc = 0; cc < candidate1[c].size(); ++cc)
		{
			sorting.push_back(pair<int, int>(cc, candidate1[c][cc]));
		}

		sort(sorting.begin(), sorting.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
		
		temp.clear();
		for (auto s : sorting)
		{
			temp.push_back(s.first);
		}

		answer.push_back(temp);
		sorting.clear();
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	vector<vector<int>> answer = solution({ {0, 5, 2, 4, 1}, {5, 0, 3, 9, 6}, {2, 3, 0, 6, 3}, {4, 9, 6, 0, 3}, {1, 6, 3, 3, 0} });

	for (vector<int> aa : answer)
	{
		for (int aaa : aa)
		{
			cout << aaa << " ";
		}
		cout << "\n";
	}

	cout << "\n";

	answer = solution({ {0, 2, 3, 1}, {2, 0, 1, 1}, {3, 1, 0, 2}, {1, 1, 2, 0} });

	for (vector<int> aa : answer)
	{
		for (int aaa : aa)
		{
			cout << aaa << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	

	getchar();

	return 0;
}