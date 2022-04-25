#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
	string step1 = "";

	for (auto ch : new_id)
	{
		if ('A' <= ch && ch <= 'Z')
		{
			step1.push_back(ch - 'A' + 'a');
		}
		else
		{
			step1.push_back(ch);
		}
	}

	string step2 = "";

	for (auto ch : step1)
	{
		if (ch == '~' || ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' ||
			ch == '^' || ch == '&' || ch == '*' || ch == '(' || ch == ')' || ch == '=' ||
			ch == '+' || ch == '[' || ch == '{' || ch == ']' || ch == '}' || ch == ':' ||
			ch == '?' || ch == ',' || ch == '<' || ch == '>' || ch == '/')
		{

		}
		else
		{
			step2.push_back(ch);
		}
	}

	string step3 = "";
	char beforeCh = 'a';

	for (auto ch : step2)
	{
		if (beforeCh == '.' && ch == '.')
		{

		}
		else
		{
			step3.push_back(ch);
		}
		beforeCh = ch;
	}
	 
	string step4 = step3;

	if (step4 == ".") step4 = "";
	else
	{
		if (step4[0] == '.') step4 = step4.substr(1, step4.size() - 1);
		if (step4[step4.size() - 1] == '.') step4 = step4.substr(0, step4.size() - 1);
	}

	string step5 = step4;

	if (step5.size() == 0) step5 = "a";

	string step6 = step5.substr(0, 15);

	if (step6[step6.size() - 1] == '.') step6 = step6.substr(0, step6.size() - 1);

	string step7 = step6;

	while (step7.size() < 3)
	{
		step7 += step7[step7.size() - 1];
	}

	return step7;
}

int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << "\n";

	cout << solution("z-+.^.") << "\n";

	cout << solution("=.=") << "\n";

	cout << solution("123_.def") << "\n";

	cout << solution("abcdefghijklmn.p") << "\n";

	getchar();

	return 0;
}