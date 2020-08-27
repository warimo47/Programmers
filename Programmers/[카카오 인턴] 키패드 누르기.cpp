#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> _numbers, string _hand)
{
	string answer = "";
	int leftHand = 10;
	int rightHand = 11;
	bool isRightHand = (_hand == "right");

	for (auto n : _numbers)
	{
		switch (n)
		{
		case 2:
			switch (leftHand)
			{
			case 2:
				answer += "L";
				leftHand = n;
				break;
			case 1:
			case 5:
				switch (rightHand)
				{
				case 2:
					answer += "R";
					rightHand = n;
					break;
				case 3:
				case 5:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 6:
				case 8:
				case 9:
				case 0:
				case 11:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 4:
			case 8:
				switch (rightHand)
				{
				case 2:
				case 3:
				case 5:
					answer += "R";
					rightHand = n;
					break;
				case 6:
				case 8:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 9:
				case 0:
				case 11:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 7:
			case 0:
				switch (rightHand)
				{
				case 2:
				case 3:
				case 5:
				case 6:
				case 8:
					answer += "R";
					rightHand = n;
					break;
				case 9:
				case 0:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 11:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 10:
				switch (rightHand)
				{
				case 2:
				case 3:
				case 5:
				case 6:
				case 8:
				case 9:
				case 0:
					answer += "R";
					rightHand = n;
					break;
				case 11:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				}
				break;
			}
			break;
		case 5:
			switch (leftHand)
			{
			case 5:
				answer += "L";
				leftHand = n;
				break;
			case 2:
			case 4:
			case 8:
				switch (rightHand)
				{
				case 5:
					answer += "R";
					rightHand = n;
					break;
				case 2:
				case 6:
				case 8:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 3:
				case 9:
				case 0:
				case 11:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 1:
			case 7:
			case 0:
				switch (rightHand)
				{
				case 5:
				case 2:
				case 6:
				case 8:
					answer += "R";
					rightHand = n;
					break;
				case 3:
				case 9:
				case 0:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 11:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 10:
				switch (rightHand)
				{
				case 5:
				case 2:
				case 6:
				case 8:
				case 3:
				case 9:
				case 0:
					answer += "R";
					rightHand = n;
					break;
				case 11:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				}
				break;
			}
			break;
		case 8:
			switch (leftHand)
			{
			case 8:
				answer += "L";
				leftHand = n;
				break;
			case 5:
			case 7:
			case 0:
				switch (rightHand)
				{
				case 8:
					answer += "R";
					rightHand = n;
					break;
				case 5:
				case 9:
				case 0:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 2:
				case 6:
				case 11:
				case 3:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 2:
			case 4:
			case 10:
				switch (rightHand)
				{
				case 8:
				case 5:
				case 9:
				case 0:
					answer += "R";
					rightHand = n;
					break;
				case 2:
				case 6:
				case 11:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 3:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 1:
				switch (rightHand)
				{
				case 8:
				case 5:
				case 9:
				case 0:
				case 2:
				case 6:
				case 11:
					answer += "R";
					rightHand = n;
					break;
				case 3:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				}
				break;
			}
			break;
		case 0:
			switch (leftHand)
			{
			case 0:
				answer += "L";
				leftHand = n;
				break;
			case 8:
			case 10:
				switch (rightHand)
				{
				case 0:
					answer += "R";
					rightHand = n;
					break;
				case 8:
				case 11:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 5:
				case 9:
				case 2:
				case 6:
				case 3:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 5:
			case 7:
				switch (rightHand)
				{
				case 0:
				case 8:
				case 11:
					answer += "R";
					rightHand = n;
					break;
				case 5:
				case 9:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 2:
				case 6:
				case 3:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 2:
			case 4:
				switch (rightHand)
				{
				case 0:
				case 8:
				case 11:
				case 5:
				case 9:
					answer += "R";
					rightHand = n;
					break;
				case 2:
				case 6:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				case 3:
					answer += "L";
					leftHand = n;
					break;
				}
				break;
			case 1:
				switch (rightHand)
				{
				case 0:
				case 8:
				case 11:
				case 5:
				case 9:
				case 2:
				case 6:
					answer += "R";
					rightHand = n;
					break;
				case 3:
					if (isRightHand == true)
					{
						answer += "R";
						rightHand = n;
					}
					else
					{
						answer += "L";
						leftHand = n;
					}
					break;
				}
				break;
			}
			break;
		case 1:
		case 4:
		case 7:
			answer += "L";
			leftHand = n;
			break;
		case 3:
		case 6:
		case 9:
			answer += "R";
			rightHand = n;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";

	cout << solution(numbers, hand) << "\n";

	numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	hand = "left";

	cout << solution(numbers, hand) << "\n";

	numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	hand = "right";

	cout << solution(numbers, hand) << "\n";


	getchar();

	return 0;
}