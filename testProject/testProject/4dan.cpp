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
	// �� n�� x�� �� �������� �˰��� �Ҷ� log(n) / log(x)�� �� �� �ִ�.
	// �������� ������ ó������ ���ؼ� ����
	// n�� ���ڸ� �������� �� �� ���� ������?
	// log10(n) + 1�� ���� �� �ִ�.

	return answer;
}

//int main()
//{
//
//	cout << solution(2147483647) << endl;
//
//	return 0;
//}