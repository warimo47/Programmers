#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct best2Song
{
	string str;
	int sum;
	int first;
	int second;
};

bool func(best2Song a, best2Song b)
{
	return a.sum > b.sum;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	vector<best2Song> pickGenres;
	bool isAllReadyHave;

	for (int i = 0; i < genres.size(); ++i)
	{
		isAllReadyHave = false;

		for (int j = 0; j < pickGenres.size(); ++j)
		{
			if (genres[i].compare(pickGenres[j].str) == 0)
			{
				isAllReadyHave = true;

				pickGenres[j].sum += plays[i];

				if (plays[pickGenres[j].first] < plays[i])
				{
					pickGenres[j].second = pickGenres[j].first;
					pickGenres[j].first = i;
				}
				else if (pickGenres[j].second == -1)
				{
					pickGenres[j].second = i;
				}
				else if (plays[pickGenres[j].second] < plays[i])
				{
					pickGenres[j].second = i;
				}

				break;
			}
		}

		if (isAllReadyHave == false)
		{
			pickGenres.push_back( { genres[i], plays[i], i, -1 } );
		}
	}

	std::sort(pickGenres.begin(), pickGenres.end(), func);

	for (best2Song b2s : pickGenres)
	{
		answer.push_back(b2s.first);
		if (b2s.second != -1)
			answer.push_back(b2s.second);
	}
	
	return answer;
}

int main()
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };

	vector<int> answer = solution(genres, plays);

	for (int a : answer)
	{
		cout << a << " ";
	}
	
	cout << "\n\n";

	getchar();

	return 0;
}