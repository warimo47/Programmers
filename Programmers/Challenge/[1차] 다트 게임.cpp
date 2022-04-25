#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string dartResult)
{
	int step = -1;
	int state = 0;

	int point[3] = { 0, 0, 0 };
	char oldChar = '-';

	for (auto dr : dartResult)
	{
		switch (dr)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			step++;
			point[step] = dr - '1' + 1;
			break;
		case '0':
			if (oldChar == '1')
			{
				point[step] = 10;
			}
			else
			{
				step++;
				point[step] = 0;
			}
			break;
		case 'S':
			break;
		case 'D':
			point[step] = point[step] * point[step];
			break;
		case 'T':
			point[step] = point[step] * point[step] * point[step];
			break;
		case '#':
			point[step] *= -1;
			break;
		case '*':
			if (step == 0)
			{
				point[step] *= 2;
			}
			else
			{
				point[step - 1] *= 2;
				point[step] *= 2;
			}
			break;
		}

		oldChar = dr;
	}

	return point[0] + point[1] + point[2];
}

int main()
{
	cout << solution("1S2D*3T") << "\n";
	cout << solution("1D2S#10S") << "\n";
	cout << solution("1D2S0T") << "\n";
	cout << solution("1S*2T*3S") << "\n";
	cout << solution("1D#2S*3S") << "\n";
	cout << solution("1T2D3D#") << "\n";
	cout << solution("1D2S3T*") << "\n";

	getchar();

	return 0;
}