#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

void makeSearchList(set<string> *searchList, string gg)
{
	for (int length = 1; length < gg.size() + 1; ++length)
	{
		for (int i = 0; i < gg.size() - (length - 1); ++i)
		{
			searchList->insert(gg.substr(i, length));
		}
	}
}

void check(set<string> *searchList, vector<string> *goods, int myIndex)
{
	set<string> temp;

	bool isHave = false;

	for (string sl : *searchList)
	{
		isHave = false;

		for (int i = 0; i < goods->size(); ++i)
		{
			if (i == myIndex) continue;

			if ((*goods)[i].find(sl) != std::string::npos)
			{
				isHave = true;
				continue;
			}
		}

		if (isHave == false)
		{
			temp.insert(sl);
		}
	}

	*searchList = temp;
}

string findMinSearchList(set<string> *searchList)
{
	if (searchList->size() == 0) return "None";

	set<string>::iterator slIter = searchList->begin();

	int minSize = (*slIter).size();

	string temp = "";

	temp += *slIter;

	slIter++;

	while(slIter != searchList->end())
	{
		if (minSize == slIter->size())
		{
			temp += " " + *slIter;
		}
		else if (minSize > slIter->size())
		{
			minSize = slIter->size();
			temp = *slIter;
		}
		slIter++;
	}

	return temp;
}

vector<string> solution(vector<string> goods)
{
	vector<string> answer;

	set<string> searchList;

	for (int i = 0; i < goods.size(); ++i)
	{
		makeSearchList(&searchList, goods[i]);

		check(&searchList, &goods, i);

		answer.push_back(findMinSearchList(&searchList));
	}

	return answer;
}

int main()
{
	vector<string> answer = solution({ "pencil", "cilicon", "contrabase", "picturelist" });
	for (string a : answer)
	{
		cout << a << "\n";
	}
	cout << "\n\n";

	answer = solution({ "abcdeabcd", "cdabe", "abce", "bcdeab" });
	for (string a : answer)
	{
		cout << a << "\n";
	}
	cout << "\n\n";

	getchar();

	return 0;
}