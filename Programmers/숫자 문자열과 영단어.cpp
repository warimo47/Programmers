#include <iostream>
#include <string>
#include <vector>

using namespace std;

string checkOneNum(string s)
{
	string returnValue = "";

	switch (s[0])
	{
	case 'z':
		if (s.size() == 4) return "0";
		else return returnValue = "0" + checkOneNum(s.substr(4, s.size() - 4));
	case 'o':
		if (s.size() == 3) return "1";
		else return returnValue = "1" + checkOneNum(s.substr(3, s.size() - 3));
	case 't':
		if (s[1] == 'w')
		{
			if (s.size() == 3) return "2";
			else return returnValue = "2" + checkOneNum(s.substr(3, s.size() - 3));
		}
		else
		{
			if (s.size() == 5) return "3";
			else return returnValue = "3" + checkOneNum(s.substr(5, s.size() - 5));
		}
	case 'f':
		if (s[1] == 'o')
		{
			if (s.size() == 4) return "4";
			return returnValue = "4" + checkOneNum(s.substr(4, s.size() - 4));
		}
		else
		{
			if (s.size() == 4) return "5";
			return returnValue = "5" + checkOneNum(s.substr(4, s.size() - 4));
		}
	case 's':
		if (s[1] == 'i')
		{
			if (s.size() == 3) return "6";
			else return returnValue = "6" + checkOneNum(s.substr(3, s.size() - 3));
		}
		else
		{
			if (s.size() == 5) return "7";
			else return returnValue = "7" + checkOneNum(s.substr(5, s.size() - 5));
		}
	case 'e':
		if (s.size() == 5) return "8";
		else return returnValue = "8" + checkOneNum(s.substr(5, s.size() - 5));
	case 'n':
		if (s.size() == 4) return "9";
		else return returnValue = "9" + checkOneNum(s.substr(4, s.size() - 4));
	default:
		if (s.size() == 1) return s;
		else return s[0] + checkOneNum(s.substr(1, s.size() - 1));
	}
}

int solution(string s)
{
	return stoi(checkOneNum(s));
}

int main()
{
	cout << solution("one4seveneight") << "\n\n";

	cout << solution("23four5six7") << "\n\n";

	cout << solution("2three45sixseven") << "\n\n";

	cout << solution("123") << "\n\n";

	getchar();

	return 0;
}