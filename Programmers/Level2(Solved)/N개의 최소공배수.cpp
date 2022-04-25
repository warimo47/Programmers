#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> arr)
{
	int answer = 1;
	bool allOne = true;
	int mulNum = 2;
	bool check = false;

	sort(arr.begin(), arr.end());

	while (true)
	{
		allOne = true;
		check = false;

		for (int ar : arr)
		{
			if (ar != 1) allOne = false;
		}

		if (allOne == true) break;

		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] % mulNum == 0)
			{
				arr[i] = arr[i] / mulNum;
				check = true;
			}
		}

		if (check == true)
		{
			answer *= mulNum;
		}
		else
		{
			mulNum++;
		}
	}

	return answer;
}

int main()
{
	vector<int> arr{ 2, 6, 8, 14 };

	cout << solution(arr) << "\n\n";

	arr = { 1, 2, 3 };
	cout << solution(arr) << "\n\n";

	arr = { 4, 8, 12 };
	cout << solution(arr) << "\n\n";

	arr = { 5, 7, 10, 14, 28 };
	cout << solution(arr) << "\n\n";


	getchar();

	return 0;
}