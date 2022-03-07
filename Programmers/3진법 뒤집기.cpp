#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	string rTriad = "";

	while (n / 3)
	{
		rTriad += to_string(n % 3);
		n = n / 3;
	}

	rTriad += to_string(n % 3);

	int answer = 0;

	int mul = 1;

	for (int i = rTriad.size() - 1; i > -1; --i)
	{
		answer += (rTriad[i] - '0') * mul;
		mul *= 3;
	}

	return answer;
}

int main()
{
	cout << solution(45) << "\n\n";

	cout << solution(125) << "\n\n";

	getchar();

	return 0;
}