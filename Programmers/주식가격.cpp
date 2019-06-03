#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer;

	for (int p : prices)
	{
		answer.push_back(0);
	}

	int nowPrice;

	for (int i = 0; i < prices.size(); ++i)
	{
		nowPrice = prices[i];

		for (int j = i + 1; j < prices.size(); ++j)
		{
			if (nowPrice > prices[j])
			{
				answer[i] = j - i;
				break;
			}
			else
			{
				answer[i] += 1;
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> prices = { 1, 2, 3, 2, 3 };
	vector<int> answer;

	answer = solution(prices);

	for (int h : answer)
	{
		cout << h << " ";
	}

	cout << "\n\n";

	getchar();

	return 0;
}