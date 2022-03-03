#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gMax;
int nowNetworksNum = 0;
vector<vector<int>> gComputers;
vector<bool> isAlreadySearchedList;
vector<int> includedNetworkInfo;

void searchNode(int target)
{
	for (int i = 0; i < gMax; ++i)
	{
		if (target == i) continue;

		if (gComputers[target][i] == 1)
		{
			includedNetworkInfo[i] = nowNetworksNum;

			if (isAlreadySearchedList[i] == false)
			{
				isAlreadySearchedList[i] = true;
				searchNode(i);
			}
		}
	}
}

int solution(int max, vector<vector<int>> computers)
{
	gMax = max;
	nowNetworksNum = 0;
	gComputers = computers;
	isAlreadySearchedList.clear();
	includedNetworkInfo.clear();

	for (int i = 0; i < gMax; ++i)
	{
		isAlreadySearchedList.push_back(false);
		includedNetworkInfo.push_back(-1);
	}

	includedNetworkInfo[0] = 0;

	for (int i = 0; i < gMax; ++i)
	{
		if (isAlreadySearchedList[i] == true) continue;

		isAlreadySearchedList[i] = true;
		searchNode(i);

		nowNetworksNum++;
	}

	return nowNetworksNum;
}

int main()
{
	cout << solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} }) << "\n\n";

	cout << solution(3, { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} }) << "\n\n";

	getchar();

	return 0;
}