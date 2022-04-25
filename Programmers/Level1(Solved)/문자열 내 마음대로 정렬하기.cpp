#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number = 0;

bool compare(string a, string b)
{
	if (a[number] == b[number])
	{
		return a.compare(b) < 0 ? true : false;
	}

	return a[number] < b[number];
}

vector<string> solution(vector<string> strings, int n)
{
	vector<string> answer = strings;
	number = n;

	sort(answer.begin(), answer.end(), compare);

	return answer;
}

int main()
{
	vector<string> str1{ "sun", "bed", "car" };

	vector<string> answer = solution(str1, 1);

	for (string st : answer)
	{
		cout << st << " ";
	}
	cout << "\n";

	vector<string> str2{ "abce", "abcd", "cdx" };

	answer = solution(str2, 2);

	for (string st : answer)
	{
		cout << st << " ";
	}
	cout << "\n";

	getchar();

	return 0;
}