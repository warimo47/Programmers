#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
	int answer = citations.size();
	int count = 0;

	sort(citations.begin(), citations.end(), [](int a, int b) {return a > b; });

	while(true)
	{
		if (count >= answer) break;

		if (citations[count] >= answer)
		{
			count++;
		}
		else
		{
			answer--;
		}
	}

	return answer;
}

int main()
{
	vector<int> clothes = { 3, 0, 6, 1, 5 };

	cout << solution(clothes) << "\n";

	clothes = { 25, 8, 5, 3, 3 };

	cout << solution(clothes) << "\n";

	clothes = { 10, 8, 5, 4, 3 };

	cout << solution(clothes) << "\n";

	clothes = { 5, 5, 5, 5, 3 };

	cout << solution(clothes) << "\n";

	clothes = { 10, 10, 1, 1, 10, 10, 10, 7 };

	cout << solution(clothes) << "\n";

	getchar();

	return 0;
}