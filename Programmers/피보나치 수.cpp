#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
	if (n == 1) return 1;

	vector<int> fibonacci{ 0, 1 };

	for (int i = 2; i < n + 1; ++i)
	{
		fibonacci.push_back((fibonacci[i - 2] + fibonacci[i - 1]) % 1234567);
	}

	return fibonacci[n] % 1234567;
}

int main()
{
	cout << solution(111) << "\n\n";
	cout << solution(3) << "\n\n";
	cout << solution(5) << "\n\n";

	getchar();

	return 0;
}