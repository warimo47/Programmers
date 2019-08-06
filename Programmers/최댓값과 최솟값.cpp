#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s)
{
	string answer = "";

	int singleNum = 0;

	int sign = 1;

	vector<int> arr;

	for (char ss : s)
	{
		if (ss == '-')
		{
			sign = -1;
		}
		else if (ss == ' ')
		{
			arr.push_back(singleNum * sign);
			singleNum = 0;
			sign = 1;
		}
		else
		{
			singleNum = singleNum * 10 + ss - 48;
		}
	}
	arr.push_back(singleNum * sign);

	sort(arr.begin(), arr.end());

	return answer + to_string(arr[0]) + ' ' + to_string(arr[arr.size() - 1]);
}

int main()
{
	string str = "1 2 3 4";
	cout << solution(str) << "\n\n";
	
	str = "-1 -2 -3 -4";
	cout << solution(str) << "\n\n";

	str = "-1 -1";
	cout << solution(str) << "\n\n";

	getchar();

	return 0;
}