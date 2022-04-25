#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

void getMenu(vector<string> *orders, int c, vector<string> *answer)
{
	vector<set<char>> candidate1;
	vector<set<char>> candidate2;

	set<char> temp;

	int ordSize = 0;

	for (int ord = 0; ord < orders->size(); ++ord)
	{
		ordSize = (*orders)[ord].size();
		if (ordSize < c) continue;

		for (int i = 0; i < ordSize; ++i)
		{
			temp.insert((*orders)[ord][i]);
			candidate1.push_back(temp);
			temp.clear();
		}

		for (int i = 0; i < c - 1; ++i)
		{
			for (int j = 0; j < ordSize; ++j)
			{
				for (set<char> c : candidate1)
				{
					temp = c;
					temp.insert((*orders)[ord][j]);
					candidate2.push_back(temp);
				}
			}
			candidate1 = candidate2;
			candidate2.clear();
		}

		for (int i = 0; i < candidate1.size(); ++i)
		{
			if (candidate1[i].size() != c)
			{
				candidate1.erase(candidate1.begin() + i);
				--i;
			}
		}
	}

	
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	for (int c : course)
	{
		getMenu(&orders, c, &answer);
	}

	return answer;
}

int main()
{
	vector<string> answer = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	getchar();

	return 0;
}