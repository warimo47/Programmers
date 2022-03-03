#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOneCharDiff(string a, string b)
{
	int diffCount = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			diffCount++;

			if (diffCount > 1) return false;
		}
	}

	if (diffCount == 1) return true;
	else return false;
}

int searchNextWord(string now, string target, vector<string> leftWords, vector<int>* steps, int step)
{
	vector<string> words;
	vector<int> wordsIndex;

	step++;

	for (int i = 0; i < leftWords.size(); ++i)
	{
		if (isOneCharDiff(now, leftWords[i]))
		{
			words.push_back(leftWords[i]);
			wordsIndex.push_back(i);
		}
	}

	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i].compare(target) == 0)
		{
			steps->push_back(step);
			return step;
		}

		leftWords.erase(leftWords.begin() + wordsIndex[i]);

		searchNextWord(words[i], target, leftWords, steps, step);
	}
}

int solution(string begin, string target, vector<string> words)
{
	bool isTargetExist = false;

	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i].compare(target) == 0)
		{
			isTargetExist = true;
			break;
		}
	}

	if (isTargetExist == false) return 0;
	
	vector<int> steps;

	searchNextWord(begin, target, words, &steps, 0);

	if (steps.size() == 0) return 0;

	int min = steps[0];

	for (int i = 1; i < steps.size(); ++i)
	{
		if (min > steps[i])
		{
			min = steps[i];
		}
	}

	return min;
}

int main()
{
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << "\n\n";

	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << "\n\n";

	getchar();

	return 0;
}