#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;

	int checkChar = 0;
	bool imposible = false;

	for (string sk : skill_trees)
	{
		imposible = false;

		checkChar = 0;

		for (char sskk : sk)
		{
			for (int i = 0; i < skill.size(); ++i)
			{
				if (sskk == skill[i])
				{
					if (i == checkChar)
					{
						checkChar++;
					}
					else if (i > checkChar)
					{
						imposible = true;
						break;
					}
				}
			}

			if (imposible) break;
		}

		if (imposible == false) answer++;
	}

	return answer;
}

int main()
{
	vector<string> skill_trees;

	skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
	cout << solution("CBD", skill_trees) << "\n\n";

	getchar();

	return 0;
}