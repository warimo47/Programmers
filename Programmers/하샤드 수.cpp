#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x)
{
	bool answer = true;

	int xx = x;
	int y = 0;

	while (xx)
	{
		y = y + xx % 10;
		xx = xx / 10;
	}

	return x % y == 0 ? true : false;
}

int main()
{
	cout << solution(11) << "\n";

	getchar();

	return 0;
}