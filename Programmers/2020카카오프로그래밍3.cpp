#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct myStruct
{
	char language;
	char backend;
	char junior;
	char pizza;
	int num;
	int temp = 0;

	void dataInput1(string str)
	{
		string step1, step2, step3, step4;

		temp = ((str[0] - 'a') / 5) + 4;
		step1 = str.substr(temp, str.size() - temp);
		language = str[0];

		temp = ((step1[0] - 'a') / 5) + 8;
		step2 = step1.substr(temp, step1.size() - temp);
		backend = step1[0];

		temp = 0;
		step3 = step2.substr(7, step2.size() - 7);
		junior = step2[0];

		temp = (2 - ((step3[0] - 'a') / 7)) + 6;
		step4 = step3.substr(temp, step3.size() - temp);
		pizza = step3[0];

		num = atoi(step4.c_str());
	}

	void dataInput2(string str)
	{
		string step1, step2, step3, step4;

		if (str[0] == 'c')
		{
			step1 = str.substr(8, str.size() - 8);
		}
		else if (str[0] == 'j')
		{
			step1 = str.substr(9, str.size() - 9);
		}
		else if (str[0] == 'p')
		{
			step1 = str.substr(11, str.size() - 11);
		}
		else
		{
			step1 = str.substr(6, str.size() - 6);
		}

		language = str[0];

		if (step1[0] == 'b')
		{
			step2 = step1.substr(12, step1.size() - 12);
		}
		else if (step1[0] == 'f')
		{
			step2 = step1.substr(13, step1.size() - 13);
		}
		else
		{
			step2 = step1.substr(6, step1.size() - 6);
		}
		backend = step1[0];

		if (step2[0] == 'j')
		{
			step3 = step2.substr(11, step2.size() - 11);
		}
		else if (step2[0] == 's')
		{
			step3 = step2.substr(11, step2.size() - 11);
		}
		else
		{
			step3 = step2.substr(6, step2.size() - 6);
		}
		junior = step2[0];

		if (step3[0] == 'p')
		{
			step4 = step3.substr(6, step3.size() - 6);
		}
		else if (step3[0] == 'c')
		{
			step4 = step3.substr(8, step3.size() - 8);
		}
		else
		{
			step4 = step3.substr(2, step3.size() - 2);
		}
		pizza = step3[0];

		num = atoi(step4.c_str());
	}
};

bool operator ==(const myStruct& a, const myStruct& b) {
	bool co1 = false;
	bool co2 = false;
	bool co3 = false;
	bool co4 = false;
	bool co5 = false;

	if (b.language == '-') co1 = true;
	else co1 = (a.language == b.language);

	if (b.backend == '-') co2 = true;
	else co2 = (a.backend == b.backend);

	if (b.junior == '-') co3 = true;
	else co3 = (a.junior == b.junior);

	if (b.pizza == '-') co4 = true;
	else co4 = (a.pizza == b.pizza);

	co5 = (a.num >= b.num);

	return co1 && co2 && co3 && co4 && co5;
}

vector<int> solution(vector<string> info, vector<string> query)
{
	vector<int> answer;

	myStruct semple;
	vector<myStruct> totalData;

	for (string str : info)
	{
		semple.dataInput1(str);
		totalData.push_back(semple);
	}

	int count = 0;

	for (auto str : query)
	{
		semple.dataInput2(str);

		count = count_if(totalData.begin(), totalData.end(), [semple](myStruct a) { return a == semple; });

		answer.push_back(count);
	}

	return answer;
}

int main()
{
	vector<string> info = {
		"java backend junior pizza 150",
		"python frontend senior chicken 210",
		"python frontend senior chicken 150",
		"cpp backend senior pizza 260",
		"java backend junior chicken 80",
		"python backend senior chicken 50" };

	vector<string> query = {
		"java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200",
		"cpp and - and senior and pizza 250",
		"- and backend and senior and - 150",
		"- and - and - and chicken 100",
		"- and - and - and - 150" };

	vector<int> ans = solution(info, query);

	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << "\n";

	getchar();

	return 0;
}