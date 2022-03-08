#include <vector>
#include <string>
#include <iostream>

using namespace std;

string myPlus(string _str, int _step)
{
	if (_step == -1)
	{
		_str = "1" + _str;
		return _str;
	}

	switch (_str[_step])
	{
	case '1':
		_str[_step] = '2';
		break;
	case '2':
		_str[_step] = '4';
		break;
	case '4':
		_str[_step] = '1';
		_str = myPlus(_str, _step - 1);
		break;
	}

	return _str;
}

string otfPlus(string a, string b)
{
	string returnValue = "";

	int aIndex = a.size() - 1;
	int bIndex = b.size() - 1;

	int upNum = 0;
	int nowNum = 0;

	while (true)
	{
		if (aIndex == -1) break;
		if (bIndex == -1) break;

		if (a[aIndex] == '1')
		{
			nowNum += 1;
		}
		else if (a[aIndex] == '2')
		{
			nowNum += 2;
		}
		else
		{
			nowNum += 3;
		}

		if (b[bIndex] == '1')
		{
			nowNum += 1;
		}
		else if (b[bIndex] == '2')
		{
			nowNum += 2;
		}
		else
		{
			nowNum += 3;
		}

		if (upNum == 1)
		{
			nowNum += 1;
		}
		else if (upNum == 2)
		{
			nowNum += 2;
		}

		switch (nowNum)
		{
		case 2:
			returnValue = "2" + returnValue;
			upNum = 0;
			break;
		case 3:
			returnValue = "4" + returnValue;
			upNum = 0;
			break;
		case 4:
			returnValue = "1" + returnValue;
			upNum = 1;
			break;
		case 5:
			returnValue = "2" + returnValue;
			upNum = 1;
			break;
		case 6:
			returnValue = "4" + returnValue;
			upNum = 1;
			break;
		case 7:
			returnValue = "1" + returnValue;
			upNum = 2;
			break;
		case 8:
			returnValue = "2" + returnValue;
			upNum = 2;
			break;
		}

		aIndex -= 1;
		bIndex -= 1;
	}

	return returnValue;
}

string mulCount2otfNum(int mc)
{
	string returnValue = "4";

	mc--;

	while (mc)
	{
		returnValue = "2" + returnValue;
		mc--;
	}

	return returnValue;
}

string solution(int n)
{
	long long nn = n;

	int mulCount = 0;

	vector<string> otfNums;

	while (nn)
	{
		mulCount = 0;

		for (int i = 1; i < nn; i *= 3, ++mulCount)
		{
			if (nn < i * 3)
			{
				otfNums.push_back(mulCount2otfNum(mulCount));
				nn -= i;
				break;
			}
		}
	}

	string answer = otfNums[0];

	for (int i = 1; i < otfNums.size(); ++i)
	{
		answer = otfPlus(answer, otfNums[i]);
	}
	
	return answer;
}

int main()
{
	
	cout << 243 << "\t" << solution(243) << "\n";

	cout << 247 << "\t" << solution(247) << "\n";

	cout << 272 << "\t" << solution(272) << "\n";
	

	getchar();

	return 0;
}