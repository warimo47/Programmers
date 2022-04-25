#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(int n)
{
	string answer = "";

	while (n)
	{
		switch (n % 3)
		{
		case 0:
			n = n / 3 - 1;
			answer = "4" + answer;
			break;
		case 1:
			n = n / 3;
			answer = "1" + answer;
			break;
		case 2:
			n = n / 3;
			answer = "2" + answer;
			break;
		}
	}
	
	return answer;
}

int main()
{
	for (int i = 1; i < 11; ++i)
	{
		cout << i << "\t" << solution(i) << "\n";
	}

	cout << 243 << "\t" << solution(243) << "\n";

	cout << 247 << "\t" << solution(247) << "\n";

	cout << 272 << "\t" << solution(272) << "\n";
	

	getchar();

	return 0;
}