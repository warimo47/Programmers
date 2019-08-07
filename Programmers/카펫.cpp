#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red)
{
	vector<int> answer;

	for (int i = 1; i <= red / i; ++i)
	{
		if (red % i != 0) continue;

		if (brown == i * 2 + red / i * 2 + 4)
		{
			answer.push_back(red / i + 2);
			answer.push_back(i + 2);
			break;
		}
	}

	return answer;
}

int main()
{
	vector<int> ans = solution(10, 2);

	cout << ans[0] << " " << ans[1] << "\n\n";

	ans = solution(8, 1);

	cout << ans[0] << " " << ans[1] << "\n\n";

	ans = solution(24, 24);

	cout << ans[0] << " " << ans[1] << "\n\n";

	getchar();

	return 0;
}