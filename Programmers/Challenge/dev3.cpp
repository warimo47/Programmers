#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool search(vector<vector<int>> *edges, int a, int b, int k, int searchCount, vector<bool> *isLive)
{
	if (k == searchCount) return false;

	if (a == b) return true;

	for (auto ee : *edges)
	{
		if (ee[0] == a)
		{
			if (search(edges, ee[1], b, k, searchCount + 1, isLive) == true)
			{

			}
			else
			{

			}
		}
		else if (ee[1] == a)
		{
			if (search(edges, ee[0], b, k, searchCount + 1, isLive) == true)
			{

			}
			else
			{

			}
		}
	}
}

int solution(int n, vector<vector<int>> edges, int k, int a, int b)
{
	int answer = -1;

	vector<bool> isLive;

	search(&edges, a, b, k, 0, &isLive);

	return answer;
}

int main()
{
	cout << solution(8, { {0, 1}, {1, 2}, {2, 3}, {4, 0}, {5, 1}, {6, 1}, {7, 2}, {7, 3}, {4, 5}, {5, 6}, {6, 7} }, 4, 0, 3) << "\n\n";

	getchar();

	return 0;
}