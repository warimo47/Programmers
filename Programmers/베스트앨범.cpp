#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;

	vector<string> genresVector;
	genresVector.push_back(genres[0]);

	vector<vector<pair<int, int>>> genrePlays;
	vector<pair<int, int>> tempVector;
	tempVector.push_back(pair<int, int>(plays[0], 0));
	genrePlays.push_back(tempVector);

	bool alreadyHave;

	for (int gCount = 1; gCount < genres.size(); ++gCount)
	{
		alreadyHave = false;
		for (int gVCount = 0; gVCount < genresVector.size(); ++gVCount)
		{
			if (genresVector[gVCount] == genres[gCount])
			{
				alreadyHave = true;
				genrePlays[gVCount].push_back(pair<int, int>(plays[gCount], gCount));
				break;
			}
		}

		if (alreadyHave == false)
		{
			genresVector.push_back(genres[gCount]);
			tempVector[0] = pair<int, int>(plays[gCount], gCount);
			genrePlays.push_back(tempVector);
		}
	}

	for (vector<pair<int, int>> gPs : genrePlays)
	{
		sort(gPs.begin(), gPs.end(), [](pair<int, int> a, pair<int, int> b) {return a.first > b.first; });
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