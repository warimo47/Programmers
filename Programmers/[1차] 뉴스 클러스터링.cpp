#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void makeZiphap(map<string, int> *ziphap, string str)
{
	string word;

	for (int i = 0; i < str.size() - 1; ++i)
	{
		word = "";

		if ('A' <= str[i] && str[i] <= 'Z')
		{
			word += str[i] - 'A' + 'a';
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			word += str[i];
		}
		else continue;

		if ('A' <= str[i + 1] && str[i + 1] <= 'Z')
		{
			word += str[i + 1] - 'A' + 'a';
		}
		else if ('a' <= str[i + 1] && str[i + 1] <= 'z')
		{
			word += str[i + 1];
		}
		else continue;

		if (ziphap->find(word) == ziphap->end())
		{
			ziphap->insert(pair<string, int>(word, 1));
		}
		else
		{
			ziphap->find(word)->second++;
		}
	}
}

int solution(string str1, string str2)
{
	map<string, int> ziphap1, ziphap2;
	
	makeZiphap(&ziphap1, str1);
	makeZiphap(&ziphap2, str2);

	int overlapping = 0;
	int combined = 0;

	for (pair<string, int> z : ziphap1)
	{
		if (ziphap2.find(z.first) == ziphap2.end())
		{
			combined += z.second;
		}
		else
		{
			if (z.second < ziphap2.find(z.first)->second)
			{
				overlapping += z.second;
				combined += ziphap2.find(z.first)->second;
			}
			else
			{
				overlapping += ziphap2.find(z.first)->second;
				combined += z.second;
			}
		}
	}

	for (pair<string, int> z : ziphap2)
	{
		if (ziphap1.find(z.first) == ziphap1.end())
		{
			combined += z.second;
		}
	}

	if (combined == 0) return 65536;
	return overlapping * 65536 / combined;
}

int main()
{
	cout << solution("FRANCE", "french") << "\n\n";

	cout << solution("handshake", "shake hands") << "\n\n";

	cout << solution("aa1+aa2", "AAAA12") << "\n\n";

	cout << solution("E=M*C^2", "e=m*c^2") << "\n\n";

	getchar();

	return 0;
}