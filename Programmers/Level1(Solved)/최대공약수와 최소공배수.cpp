#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m)
{
	vector<int> answer;
	int big, small;

	if (n > m)
	{
		big = n;
		small = m;
	}
	else if (n < m)
	{
		big = m;
		small = n;
	}
	else
	{
		answer.push_back(n);
		answer.push_back(n);

		return answer;
	}

	if (big % small == 0)
	{
		answer.push_back(small);
		answer.push_back(big);

		return answer;
	}

	int num = 1;

	for (int i = 2; i <= small; ++i)
	{
		if (big % i == 0 && small % i == 0)
		{
			num = i;
		}
	}

	answer.push_back(num);

	answer.push_back(big / answer[0] * small);

	return answer;
}

int main()
{
	vector<int> answer = solution(3, 12);
	cout << answer[0] << " " << answer[1] << "\n";

	answer = solution(9, 27);
	cout << answer[0] << " " << answer[1] << "\n";

	answer = solution(110, 200);
	cout << answer[0] << " " << answer[1] << "\n";

	answer = solution(15, 12);
	cout << answer[0] << " " << answer[1] << "\n";

	answer = solution(2, 999);
	cout << answer[0] << " " << answer[1] << "\n";

	answer = solution(15, 15);
	cout << answer[0] << " " << answer[1] << "\n";
	

	getchar();

	return 0;
}