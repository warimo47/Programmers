#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

bool checkPrimenum(int num)
{
	if (num < 2) return false;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

void makeNumbers(string nowString, vector<string> leftCards, vector<string>* pSearchNumbers)
{
	string saveNowString;

	for (int i = 0; i < leftCards.size(); ++i)
	{
		vector<string> copyLeftCards = leftCards;

		saveNowString = nowString + leftCards[i];
		
		pSearchNumbers->push_back(saveNowString);
		copyLeftCards.erase(copyLeftCards.begin() + i);

		makeNumbers(saveNowString, copyLeftCards, pSearchNumbers);
	}
}

int solution(string numbers)
{
	vector<string> cards;
	vector<string> searchNumbers;

	for (int i = 0; i < numbers.length(); ++i)
	{
		cards.push_back(numbers.substr(i, 1));
	}

	makeNumbers("", cards, &searchNumbers);

	set<int> primeNumbers;

	for (int i = 0; i < searchNumbers.size(); ++i)
	{
		if (checkPrimenum(stoi(searchNumbers[i])))
		{
			primeNumbers.insert(stoi(searchNumbers[i]));
		}
	}

	return primeNumbers.size();
}

int main()
{
	cout << solution("0123456") << "\n\n";

	cout << solution("17") << "\n\n";
	
	cout << solution("011") << "\n\n";
	
	getchar();

	return 0;
}