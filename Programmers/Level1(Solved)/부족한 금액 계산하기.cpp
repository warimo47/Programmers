#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int price, int money, int count)
{
	int needMoney = 0;

	for (int i = 1; i < count + 1; ++i)
	{
		needMoney += price * i;
	}

	if (needMoney < money) return 0;
	else return needMoney - money;
}

int main()
{
	cout << solution(3, 20, 4) << "\n\n";

	getchar();

	return 0;
}