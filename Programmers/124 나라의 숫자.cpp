#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(int n)
{
	if (n == 1) return "1";
	if (n == 2) return "2";
	string answer = "";

	int num = n;

	vector<int> digits{ 0, 3, 12, 39, 120, 363, 1092, 3279, 9840, 29523, 88572, 265719, 797160, 2391483, 7174452, 21523359, 64570080, 193710243 };
	int digitCount = 0;
	
	for (int dc : digits)
	{
		if (num <= dc) break;
		++digitCount;
	}

	int divisionValue;

	for (int i = digitCount; i > 0; --i)
	{
		divisionValue = (digits[i] - digits[i - 1]) / 3;


		if (num / i == 0)
		{
			answer = '4' + answer;
		}
		else if(num % 3 == 1)
		{
			answer = '1' + answer;
		}
		else
		{
			answer = '2' + answer;
		}
		num = num - (num % 3);
	}

	return answer;
}

int main()
{
	for (int i = 1; i < 500; ++i)
	{
		cout << solution(i) << "\n";
	}

	getchar();

	return 0;
}