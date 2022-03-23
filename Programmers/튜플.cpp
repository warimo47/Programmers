#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
	vector<int> answer;

	s = s.substr(1, s.size() - 2);

	vector<vector<int>> tuple;
	vector<int> temp;

	int num = -1;
	bool isCounting = false;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '{')
		{
			isCounting = true;
		}
		else if (s[i] == '}')
		{
			isCounting = false;
			temp.push_back(num);
			tuple.push_back(temp);
			temp.clear();
			num = -1;
		}
		else if (s[i] == ',')
		{
			if (isCounting)
			{
				temp.push_back(num);
				num = -1;
			}
		}
		else
		{
			if (num == -1)
			{
				num = s[i] - '0';
			}
			else
			{
				num = num * 10 + s[i] - '0';
			}
		}
	}

	sort(tuple.begin(), tuple.end(), [](vector<int> a, vector<int> b) {return a.size() < b.size(); });

	for (int tt = 0; tt < tuple.size(); ++tt)
	{
		answer.push_back(tuple[tt][0]);

		for (int j = tt + 1; j < tuple.size(); ++j)
		{
			for (int i = 0; i < tuple[j].size(); ++i)
			{
				if (tuple[j][i] == answer[answer.size() - 1])
				{
					tuple[j].erase(tuple[j].begin() + i);
					break;
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> answer = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution("{{20,111},{111}}");
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution("{{123}}");
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	getchar();

	return 0;
}