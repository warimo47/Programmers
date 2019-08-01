#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
	long long answer = 0;

	vector<int> arr;

	while (n)
	{
		arr.push_back(n % 10);
		n = n / 10;
	}

	sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });

	for (int ar : arr)
	{
		answer = answer * 10 + ar;
	}

	return answer;
}

int main()
{
	cout << solution(118372) << "\n";

	getchar();

	return 0;
}