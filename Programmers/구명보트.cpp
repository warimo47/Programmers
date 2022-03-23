#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> people, int limit)
{
	sort(people.begin(), people.end());

	int minIndex = 0;
	int maxIndex = people.size() - 1;
	int answer = 0;

	while(true)
	{
		if (minIndex > maxIndex)
		{
			break;
		}
		else if (minIndex == maxIndex)
		{
			answer++;
			break;
		}

		if (people[maxIndex] + people[minIndex] <= limit)
		{
			answer++;
			minIndex++;
			maxIndex--;
		}
		else
		{
			answer++;
			maxIndex--;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 70, 50, 80, 50 }, 100) << "\n\n";

	cout << solution({ 70, 80, 50 }, 100) << "\n\n";

	getchar();

	return 0;
}