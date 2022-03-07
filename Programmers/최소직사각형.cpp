#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
	int temp;

	for (int i = 0; i < sizes.size(); ++i)
	{
		if (sizes[i][1] > sizes[i][0])
		{
			temp = sizes[i][1];
			sizes[i][1] = sizes[i][0];
			sizes[i][0] = temp;
		}
	}

	int firstMax = 0;
	int secondMax = 0;

	for (int i = 0; i < sizes.size(); ++i)
	{
		if (firstMax < sizes[i][0])
		{
			firstMax = sizes[i][0];
		}

		if (secondMax < sizes[i][1])
		{
			secondMax = sizes[i][1];
		}
	}

	return firstMax * secondMax;
}

int main()
{
	cout << solution({ { 60, 50 }, { 30, 70 }, { 60, 30 }, { 80, 40 } }) << "\n\n";

	cout << solution({ { 10, 7 }, { 12, 3 }, { 8, 15 }, { 14, 7 }, { 5, 15 } }) << "\n\n";

	cout << solution({ { 4, 4 }, { 19, 6 }, { 6, 16 }, { 18, 7 }, { 7, 11 } }) << "\n\n";

	getchar();

	return 0;
}