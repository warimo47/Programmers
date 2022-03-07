#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
	int answer = 0;

	vector<int> slot;

	for (int i = 0; i < 10; ++i)
	{
		slot.push_back(i);
	}

	for (int i = 0; i < numbers.size(); ++i)
	{
		slot[numbers[i]] = 0;
	}

	for (int i = 0; i < 10; ++i)
	{
		answer += slot[i];
	}

	return answer;
}

int main()
{
	cout << solution({ 1, 2, 3, 4, 6, 7, 8, 0 }) << "\n\n";

	cout << solution({ 5, 8, 4, 0, 6, 7, 9 }) << "\n\n";

	getchar();

	return 0;
}