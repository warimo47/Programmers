#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s)
{
	string copy = s;
	char temp;
	int aaN, bbN;
	
	for (int i = 0; i < copy.size() - 1; ++i)
	{
		for (int j = i + 1; j < copy.size(); ++j)
		{
			aaN = copy[i];
			if (aaN < 97) aaN + 200;
			bbN = copy[j];
			if (bbN < 97) bbN + 200;

			if (aaN < bbN)
			{
				temp = copy[j];
				copy[j] = copy[i];
				copy[i] = temp;
			}
		}
	}

	return copy;
}

int main()
{
	cout << solution("Zbcdefg") << "\n";

	getchar();

	return 0;
}