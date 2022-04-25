#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	if (arr.size() == 1)
	{
		answer.push_back(-1);
		return answer;
	}

	int min = 9999999999;
	int minIndex = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (min > arr[i])
		{
			min = arr[i];
			minIndex = i;
		}
	}

	arr.erase(arr.begin() + minIndex);
	
	return arr;
}

int main()
{
	vector<int> arr{ 4, 3, 2, 1 };
	vector<int> answer = solution(arr);

	for (int an : answer)
	{
		cout << an << " ";
	}

	cout << "\n";

	arr = { 10 };
	answer = solution(arr);

	for (int an : answer)
	{
		cout << an << " ";
	}
	
	cout << "\n";

	getchar();

	return 0;
}