#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int solution(string numbers)
{
	int answer = 0;
	int bitCount = 1;

	vector<int> arr;
	arr.resize(10);

	for (int i = 0; i < numbers.size(); ++i)
	{
		bitCount *= 10;
		++arr[numbers[i] - '0'];
	}

	set<int> primeSet;

	primeSet.insert(2);
	bool check;

	for (int i = 3; i < bitCount; i = i + 2)
	{
		check = true;

		for (int pn : primeSet)
		{
			if (i % pn == 0)
			{
				check = false;
				break;
			}
		}

		if (check == true) primeSet.insert(i);
	}

	vector<int> arr2;
	int tempNum = 0;

	for (int pn : primeSet)
	{
		arr2.clear();
		arr2.resize(10);
		tempNum = 0;

		while (pn)
		{
			++arr2[pn % 10];
			pn = pn / 10;
		}

		if (arr == arr2)
		{
			++answer;
		}
	}

	return answer;
}

int main()
{
	cout << solution("17") << "\n\n";
	
	cout << solution("011") << "\n\n";
	
	getchar();

	return 0;
}