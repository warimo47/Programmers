#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string number, int k)
{
	set<string> candidates;
	set<string>::iterator iter;
	string tempNumber;

	for (int i = 0; i < k; ++i)
	{
		candidates.empty();
		
		for (int j = 0; j < number.size(); ++j)
		{
			tempNumber = number;
			tempNumber.erase(tempNumber.begin() + j);

			candidates.insert(tempNumber);
		}

		iter = candidates.end();
		iter--;
		number = *iter;
	}

	return number;
}

int main()
{
	cout << solution("1924", 2) << "\n\n";

	cout << solution("1231234", 3) << "\n\n";

	cout << solution("4177252841", 4) << "\n\n";

	getchar();

	return 0;
}