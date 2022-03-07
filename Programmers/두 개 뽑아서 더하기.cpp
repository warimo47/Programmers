#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
	set<int> setCon;

	for (int i = 0; i < numbers.size() - 1; ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			setCon.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> answer(setCon.begin(), setCon.end());

	return answer;
}

int main()
{
	vector<int> s = solution({ 2, 1, 3, 4, 1 });

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}

	cout << "\n\n";

	s = solution({ 5, 0, 2, 7 });

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}

	cout << "\n\n";

	getchar();

	return 0;
}