#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int> > v)
{
	vector<int> ans;

	ans.push_back(0);
	ans.push_back(0);

	if (v[0][0] == v[1][0])
	{
		ans[0] = v[2][0];
	}
	else
	{
		if (v[0][0] == v[2][0])
		{
			ans[0] = v[1][0];
		}
		else
		{
			ans[0] = v[0][0];
		}
	}

	if (v[0][1] == v[1][1])
	{
		ans[1] = v[2][1];
	}
	else
	{
		if (v[0][1] == v[2][1])
		{
			ans[1] = v[1][1];
		}
		else
		{
			ans[1] = v[0][1];
		}
	}

	return ans;
}

int main()
{
	vector<vector<int> > v;
	vector<int> a;

	v = { { 1, 4 }, { 3, 4 }, { 3, 10 } };
	a = solution(v);
	cout << a[0] << " " << a[1] << "\n\n";

	v = { { 1, 1 }, { 2, 2 }, { 1, 2 } };
	a = solution(v);
	cout << a[0] << " " << a[1] << "\n\n";

	getchar();

	return 0;
}