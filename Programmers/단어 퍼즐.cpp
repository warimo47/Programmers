#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(vector<string> strs, string t)
{
	int answer = 0;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}
int main()
{
	vector<string> strs = { "ba","na","n","a" };
	string t = "banana";

	cout << solution(strs, t) << "\n\n";

	strs = { "app","ap","p","l", "e", "ple", "pp" };
	t = "apple";

	cout << solution(strs, t) << "\n\n";

	strs = { "ba","an","nan","ban", "n" };
	t = "banana";

	cout << solution(strs, t) << "\n\n";

	getchar();

	return 0;
}