#include <vector>
#include <iostream>

using namespace std;

void solution()
{
	vector<int> checkList;
	bool check = false;

	long long answer = 2;

	cout << "2, ";
	int count = 1;

	for (int i = 3; i <= 100; i = i + 2)
	{
		check = true;

		for (int cl : checkList)
		{
			if (i % cl == 0)
			{
				check = false;
				break;
			}
		}

		if (check == true)
		{
			cout << i << ", ";
			checkList.push_back(i);
			++count;
			if (count % 10 == 0) cout << "\n";
		}
	}
}

int main()
{
	solution();

	getchar();

	return 0;
}