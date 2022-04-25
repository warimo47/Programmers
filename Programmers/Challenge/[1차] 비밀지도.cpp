#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;

	string line = "";

	bool makeWall = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = pow(2, n - 1); j > 0; j /= 2)
		{
			makeWall = false;

			if (arr1[i] >= j)
			{
				arr1[i] -= j;
				line += "#";
				makeWall = true;
			}

			if (arr2[i] >= j)
			{
				arr2[i] -= j;
				if (makeWall == false)
				{
					line += "#";
					makeWall = true;
				}
			}

			if (makeWall == false) line += " ";
		}

		answer.push_back(line);
		line = "";
	}

	return answer;
}

int main()
{
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };

	vector<string> answer = solution(5, arr1, arr2);

	for (auto ans : answer)
	{
		cout << ans << "\n";
	}

	cout << "\n";

	arr1 = { 46, 33, 33, 22, 31, 50 };
	arr2 = { 27, 56, 19, 14, 14, 10 };

	answer = solution(6, arr1, arr2);

	for (auto ans : answer)
	{
		cout << ans << "\n";
	}

	getchar();

	return 0;
}