#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
	vector<int> vMP_IF;
	vMP_IF.resize(sticker.size());
	vector<int> vMP_NIF;
	vMP_NIF.resize(sticker.size());

	if (sticker.size() == 1) return sticker[0];
	
	vMP_IF[0] = sticker[0];
	vMP_IF[1] = sticker[0];
	vMP_NIF[0] = 0;
	vMP_NIF[1] = sticker[1];

	max(1, 2);

	for (int i = 2; i < sticker.size() - 1; ++i)
	{
		if (vMP_IF[i - 1] < vMP_IF[i - 2] + sticker[i])
		{
			vMP_IF[i] = vMP_IF[i - 2] + sticker[i];
		}
		else
		{
			vMP_IF[i] = vMP_IF[i - 1];
		}

		if (vMP_NIF[i - 1] < vMP_NIF[i - 2] + sticker[i])
		{
			vMP_NIF[i] = vMP_NIF[i - 2] + sticker[i];
		}
		else
		{
			vMP_NIF[i] = vMP_NIF[i - 1];
		}
	}

	vMP_IF[sticker.size() - 1] = vMP_IF[sticker.size() - 2];

	if (vMP_NIF[sticker.size() - 2] < vMP_NIF[sticker.size() - 3] + sticker[sticker.size() - 1])
	{
		vMP_NIF[sticker.size() - 1] = vMP_NIF[sticker.size() - 3] + sticker[sticker.size() - 1];
	}
	else
	{
		vMP_NIF[sticker.size() - 1] = vMP_NIF[sticker.size() - 2];
	}

	return vMP_IF[vMP_IF.size() - 1] < vMP_NIF[vMP_NIF.size() - 1] ? vMP_NIF[vMP_NIF.size() - 1] : vMP_IF[vMP_IF.size() - 1];
}

int main()
{
	vector<int> sticker = { 14, 6, 5, 11, 3, 9, 2, 10 };

	cout << solution(sticker) << "\n\n";

	sticker = { 1, 3, 2, 5, 4 };

	cout << solution(sticker) << "\n\n";

	getchar();

	return 0;
}