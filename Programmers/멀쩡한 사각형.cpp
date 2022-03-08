#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long w, long long h)
{
	long long cannotUse = 0;

	long long total = w * h;

	// y = h/w * x
	// x = y * w/h

	long long start = 0;

	for (long long x = 1; x < w + 1; ++x)
	{
		if ((x * h) % w)
		{
			cannotUse += x * h / w + 1 - start;
		}
		else
		{
			cannotUse += x * h / w - start;
		}
		start = x * h / w;
	}

	return total - cannotUse;
}

int main()
{
	cout << solution(8, 12) << "\n\n";

	cout << solution(3, 11) << "\n\n";

	cout << solution(13, 11) << "\n\n";

	getchar();

	return 0;
}