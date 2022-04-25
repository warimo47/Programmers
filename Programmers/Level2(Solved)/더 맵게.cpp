#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K)
{
	multiset<int> setScoville;

	int answer = 0;
	int newValue = 0;
	int firstValue = 0;
	int secondValue = 0;
	bool valueUpdate = false;

	for (int sc : scoville)
	{
		setScoville.insert(sc);
	}

	while (true)
	{
		if (*setScoville.begin() >= K) return answer;

		if (setScoville.size() == 1) return -1;

		firstValue = *setScoville.begin();
		setScoville.erase(setScoville.begin());

		secondValue = *setScoville.begin();
		setScoville.erase(setScoville.begin());
		
		newValue = firstValue + secondValue * 2;

		setScoville.insert(newValue);

		++answer;
	}

	return answer;
}

int main()
{
	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };

	cout << solution(scoville, 7) << "\n\n";

	scoville = { 1, 1, 2, 2, 10, 12 };

	cout << solution(scoville, 7) << "\n\n";

	getchar();

	return 0;
}