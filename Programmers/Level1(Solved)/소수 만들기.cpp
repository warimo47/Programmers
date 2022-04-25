#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkPrimenum(int num)
{
	if (num < 2) return false;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int solution(vector<int> nums)
{
	int answer = 0;

	for (int a = 0; a < nums.size() - 2; ++a)
	{
		for (int b = a + 1; b < nums.size() - 1; ++b)
		{
			for (int c = b + 1; c < nums.size(); ++c)
			{
				if (checkPrimenum(nums[a] + nums[b] + nums[c]) == true)
					answer++;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 1, 2, 3, 4 }) << "\n\n";

	cout << solution({ 1, 2, 7, 6, 4 }) << "\n\n";

	getchar();

	return 0;
}