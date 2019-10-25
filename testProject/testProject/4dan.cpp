#include <iostream>
#include <cmath>

using namespace std;

int DFS(int n, int addCnt, int mulCnt, int maxCnt)
{
	int cnt = 0;

	if (1 == n)
	{
		if (addCnt == maxCnt * 2 && mulCnt == maxCnt)
			return 1;
		else
			return 0;
	}
	if (0 == n)
		return 0;

	if (0 == n % 3 && mulCnt < maxCnt && (mulCnt + 1) * 2 <= addCnt)
		cnt += DFS(n / 3, addCnt, mulCnt + 1, maxCnt);
	
	if (n > 0 && addCnt < maxCnt * 2)
		cnt += DFS(n - 1, addCnt + 1, mulCnt, maxCnt);

	return cnt;
}

int solution(int n)
{
	long long check = 1;
	int maxCnt = 0;

	while (true)
	{
		if (n <= check)
			break;

		check *= 3;
		check += 2;

		++maxCnt;
	}

	int answer = DFS(n, 0, 0, (int)log(n) / log(3));
	// ★ n이 x의 몇 제곱인지 알고자 할때 log(n) / log(x)로 알 수 있다.
	// 기존에는 제곱을 처음부터 곱해서 비교함
	// n이 몇자리 수인지도 알 수 있지 않을까?
	// log10(n) + 1로 구할 수 있다.

	return answer;
}

//int main()
//{
//
//	cout << solution(2147483647) << endl;
//
//	return 0;
//}