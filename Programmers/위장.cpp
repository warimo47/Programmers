#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 1;

	vector<int> clothesCount;
	vector<pair<string, int>> clothesType;
	bool allreadyHave = false;

	for (vector<string> cs : clothes)
	{
		allreadyHave = false;

		for (pair<string, int> ct : clothesType)
		{
			if (cs[1] == ct.first)
			{
				allreadyHave = true;
				clothesCount[ct.second] += 1;
				break;
			}
		}

		if (!allreadyHave)
		{
			clothesType.push_back(pair<string, int>(cs[1], clothesCount.size()));
			clothesCount.push_back(1);
		}
	}

	for (int cc : clothesCount)
	{
		answer = answer * (cc + 1);
	}

	return answer - 1;
}

int main()
{
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

	cout << solution(clothes) << "\n";

	clothes = {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}} ;

	cout << solution(clothes) << "\n";

	getchar();

	return 0;
}