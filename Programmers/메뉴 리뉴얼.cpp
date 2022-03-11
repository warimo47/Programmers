#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;



	return answer;
}

int main()
{
	vector<string> answer = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
	for (string a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	getchar();

	return 0;
}