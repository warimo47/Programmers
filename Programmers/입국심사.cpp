#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

unsigned long long solution(int n, vector<int> times)
{
	priority_queue<pair<unsigned long long, unsigned long long>, vector<pair<unsigned long long, unsigned long long>>, greater<pair<unsigned long long, unsigned long long>>> waitTimes;

	for (auto t : times)
	{
		waitTimes.push(pair<unsigned long long, unsigned long long>(t, t));
	}

	pair<unsigned long long, unsigned long long> temp;

	while(true)
	{
		if (n == 0) break;

		temp = waitTimes.top();
		waitTimes.pop();
		temp.first += temp.second;
		waitTimes.push(temp);

		n--;
	}

	priority_queue<unsigned long long> waitTimes2;

	while(true)
	{
		if (waitTimes.empty() == true) break;

		temp = waitTimes.top();
		waitTimes.pop();
		temp.first -= temp.second;

		waitTimes2.push(temp.first);
	}

	return waitTimes2.top();
}

int main()
{
	vector<int> timesArray = { 7, 10 };

	std::cout << solution(6, timesArray) << " | 28" << std::endl;

	timesArray = { 2, 5, 11 };

	std::cout << solution(9, timesArray) << " | 12" << std::endl;

	getchar();

	return 0;
}