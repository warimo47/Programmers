#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
	set<int> setCon;

	for (int i = 0; i < nums.size(); ++i)
	{
		setCon.insert(nums[i]);
	}

	if (setCon.size() < (nums.size() / 2))
		return setCon.size();
	else
		return nums.size() / 2;
}

int main()
{
	cout << solution({ 3, 1, 2, 3 }) << "\n\n";

	cout << solution({ 3, 3, 3, 2, 2, 4 }) << "\n\n";

	cout << solution({ 3, 3, 3, 2, 2, 2 }) << "\n\n";

	getchar();

	return 0;
}