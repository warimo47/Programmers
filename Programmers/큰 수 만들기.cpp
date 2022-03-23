#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string number, int k)
{
	int checkIndex = 0;

	bool isErase = false;

	for (int i = 0; i < k; ++i)
	{
		isErase = false;

		while (checkIndex + 1 < number.size())
		{
			if (number[checkIndex] < number[checkIndex + 1])
			{
				number.erase(number.begin() + checkIndex);
				checkIndex--;
				if (checkIndex == -1) checkIndex = 0;
				isErase = true;
				break;
			}
			
			checkIndex++;
		}

		if (isErase == false)
		{
			number.erase(number.begin() + checkIndex);
			checkIndex = 0;
		}
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