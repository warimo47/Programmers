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

string solution(int n)
{
	string answer = "1";

	if (n > 3000000)
	{
		answer = "12121441412244";
		n -= 3000000;
	}
	else if (n > 2000000)
	{
		answer = "4142114444242";
		n -= 2000000;
	}
	else if (n > 1000000)
	{
		answer = "1212144141241";
		n -= 1000000;
	}
	else
	{
		answer = "1";
	}

	if (n == 1) return "1";

	for (int i = 0; i < n - 1; ++i)
	{
		answer = myPlus(answer, answer.size() - 1);
	}

	return answer;
}

int main()
{
	cout << solution(1000000) << "\n";

	cout << solution(2000000) << "\n";

	cout << solution(3000000) << "\n";

	cout << solution(4000000) << "\n";

	cout << solution(5000000) << "\n";

	getchar();

	return 0;
}