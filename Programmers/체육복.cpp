#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;

	vector<int> sum;

	for (int i = 0; i <= n; ++i) sum.push_back(1);

	for (int lc : lost) sum[lc] = sum[lc] - 1;

	for (int rc : reserve) sum[rc] = sum[rc] + 1;

	sum[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (sum[i] == 0)
		{
			if (sum[i - 1] == 2)
			{
				sum[i - 1] = 1;
				++answer;
			}
			else 
			{
				if (i + 1 <= n)
				{
					if (sum[i + 1] == 2)
					{
						sum[i + 1] = 1;
						++answer;
					}
				}
			}
		}
		else
		{
			++answer;
		}
	}

	return answer;
}

int main()
{
	vector<int> lost{ 2, 4 };
	vector<int> reserve{ 1, 3, 5 };
	
	cout << solution(5, lost, reserve) << "\n";

	lost = { 2, 4 };
	reserve = { 3 };
	cout << solution(5, lost, reserve) << "\n";

	lost = { 3 };
	reserve = { 1 };
	cout << solution(3, lost, reserve) << "\n";

	getchar();

	return 0;
}