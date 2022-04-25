#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeCandidate(string now, string left, vector<string> *candidates)
{
	if (left.size() == 0)
	{
		candidates->push_back(now);
		return;
	}

	string new_left;

	for (int i = 0; i < left.size(); ++i)
	{
		new_left = left.substr(0, i) + left.substr(i + 1, left.size() - i);
		makeCandidate(now + left[i], new_left, candidates);
	}
}

int solution(int n, vector<string> data)
{
	string friends = "ACFJMNRT";

	vector<string> candidates;

	makeCandidate("", friends, &candidates);

	char hitter;
	int hitterIndex;
	char target;
	int targetIndex;
	int min;
	int max;
	char condition;
	int diff;

	vector<string> newCandidates;

	for (string d : data)
	{
		hitter = d[0];
		target = d[2];
		condition = d[3];
		diff = d[4] - '0';

		for (string c : candidates)
		{
			for (int i = 0; i < c.size(); ++i)
			{
				if (c[i] == hitter)
				{
					hitterIndex = i;
				}
				if (c[i] == target)
				{
					targetIndex = i;
				}
			}

			if (hitterIndex < targetIndex)
			{
				min = hitterIndex;
				max = targetIndex;
			}
			else
			{
				min = targetIndex;
				max = hitterIndex;
			}

			switch (condition)
			{
			case '=':
				if (min + diff + 1 == max)
				{
					newCandidates.push_back(c);
				}
				break;
			case '<':
				if (min + diff + 1 > max)
				{
					newCandidates.push_back(c);
				}
				break;
			case '>':
				if (min + diff + 1 < max)
				{
					newCandidates.push_back(c);
				}
				break;
			}
		}

		candidates = newCandidates;
		newCandidates.clear();
	}

	return candidates.size();
}

int main()
{
	cout << solution(2, { "N~F=0", "R~T>2" }) << "\n\n";

	cout << solution(2, { "M~C<2", "C~M>1" }) << "\n\n";

	getchar();

	return 0;
}