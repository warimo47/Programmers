#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
	vector<int> answer;
	vector<int> myQueue;

	string number;

	for (auto str : operations)
	{
		number = str.substr(2, str.size() - 2);

		if (str[0] == 'I')
		{
			myQueue.push_back(atoi(number.c_str()));
		}
		else
		{
			if (str[2] == '1')
			{
				if (myQueue.size() > 0)
					myQueue.pop_back();
			}
			else
			{
				if (myQueue.size() > 0)
					myQueue.erase(myQueue.begin());
			}
		}

		sort(myQueue.begin(), myQueue.end());
	}

	if (myQueue.size() == 0)
	{
		myQueue.push_back(0);
	}

	answer.push_back(myQueue[myQueue.size() - 1]);
	answer.push_back(myQueue[0]);

	return answer;
}

int main()
{
	vector<string> operations1 = { "I 16", "D 1" };

	vector<int> ans1 = solution(operations1);

	cout << ans1[0] << " " << ans1[1] << "\n";

	vector<string> operations2 = { "I 7", "I 5", "I -5", "D -1"};

	vector<int> ans2 = solution(operations2);

	cout << ans2[0] << " " << ans2[1] << "\n";

	getchar();

	return 0;
}