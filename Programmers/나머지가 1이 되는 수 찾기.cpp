#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 1) return i;
	}
}

int main()
{
	cout << solution(10) << "\n\n";

	cout << solution(12) << "\n\n";

	getchar();

	return 0;
}