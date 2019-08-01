#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
	int answer = 0;
	int sum = 0;

	sort(d.begin(), d.end());

	for (int i = 0; i < d.size(); ++i)
	{
		sum = sum + d[i];
		if (sum > budget) break;
		++answer;
	}

	return answer;
}

int main()
{
	vector<int> arr = { 1,3,2,5,4 };

	cout << solution(arr, 9) << "\n";

	arr = { 2,2,3,3 };
	cout << solution(arr, 10) << "\n";

	getchar();

	return 0;
}