#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer;

	vector<int> Temp;

	int singleTemp = 0;

	for (int i = 0; i < arr1.size(); ++i)
	{
		for (int k = 0; k < arr2[0].size(); ++k)
		{
			singleTemp = 0;

			for (int j = 0; j < arr1[i].size(); ++j)
			{
				singleTemp += arr1[i][j] * arr2[j][k];
			}

			Temp.push_back(singleTemp);
		}

		answer.push_back(Temp);

		Temp.clear();
	}
	
	return answer;
}

int main()
{
	vector<vector<int>> arr1;
	vector<vector<int>> arr2;

	arr1 = { { 2, 3, 2 }, { 4, 2, 4 } };
	arr2 = { { 5, 4 }, { 2, 4 }, { 3, 1 } };

	solution(arr1, arr2);

	arr1 = { { 1, 4 }, { 3, 2 }, { 4, 1 } };
	arr2 = { { 3, 3 }, { 3, 3 } };

	solution(arr1, arr2);

	arr1 = { { 2, 3, 2 }, { 4, 2, 4 }, { 3, 1, 4 } };
	arr2 = { { 5, 4, 3 }, { 2, 4, 1}, { 3, 1, 1 } };

	solution(arr1, arr2);

	getchar();

	return 0;
}