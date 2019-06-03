#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	int ready = 0;
	bool isPrint = true;

	while (true)
	{
		ready = priorities[0];
		isPrint = true;

		for (int i = 1; i < priorities.size(); ++i)
		{
			if (ready < priorities[i])
			{
				priorities.push_back(ready);
				priorities.erase(priorities.begin());

				isPrint = false;
				break;
			}
		}

		if (isPrint)
		{
			answer++;
			priorities.erase(priorities.begin());

			if (location == 0) return answer;
		}

		location--;
		
		if (location < 0) location = priorities.size() - 1;
	}

	return answer;
}

int main()
{
	vector<int> priorities = { 2, 1, 3, 2 };
	int location = 2;

	cout << solution(priorities, location) << "\n";

	priorities.clear();
	priorities = { 1, 1, 9, 1, 1, 1 };
	location = 0;

	cout << solution(priorities, location) << "\n";

	getchar();

	return 0;
}