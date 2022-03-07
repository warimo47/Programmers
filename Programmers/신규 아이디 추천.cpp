#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
	// step 1
	for (int i = 0; i < new_id.size(); ++i)
	{
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
		{
			new_id[i] = new_id[i] + ('a' - 'A');
		}
	}

	// step 2
	string step2 = "";
	for (int i = 0; i < new_id.size(); ++i)
	{
		if ('a' <= new_id[i] && new_id[i] <= 'z')
		{
			step2 += new_id[i];
		}
		else if ('0' <= new_id[i] && new_id[i] <= '9')
		{
			step2 += new_id[i];
		}
		else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			step2 += new_id[i];
		}
	}

	// step 3
	string step3 = "";
	bool isDot = false;

	for (int i = 0; i < step2.size(); ++i)
	{
		if (step2[i] == '.')
		{
			if (isDot == false)
			{
				step3 += step2[i];
				isDot = true;
			}
		}
		else
		{
			isDot = false;
			step3 += step2[i];
		}
	}

	// step 4
	string step4 = "";
	if (step3[0] == '.') step3 = step3.substr(1, step3.size() - 1);
	if (step3.size() != 0)
	{
		if (step3[step3.size() - 1] == '.') step4 = step3.substr(0, step3.size() - 1);
		else step4 = step3;
	}

	// step 5
	string step5 = step4;
	if (step4.size() == 0) step5 = "a";

	// step 6
	string step6 = step5;
	if (step5.size() > 15) step6 = step6.substr(0, 15);
	if (step6[step6.size() - 1] == '.') step6 = step6.substr(0, step6.size() - 1);

	// step 7
	string answer = step6;
	while (answer.size() < 3)
	{
		answer += answer[answer.size() - 1];
	}

	return answer;
}

int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << "\n\n";

	cout << solution("z-+.^.") << "\n\n";

	cout << solution("=.=") << "\n\n";

	cout << solution("123_.def") << "\n\n";

	cout << solution("abcdefghijklmn.p") << "\n\n";

	getchar();

	return 0;
}