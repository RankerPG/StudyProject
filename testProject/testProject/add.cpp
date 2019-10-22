#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 본인
// 홀수 일 때
// 범위 제한 더하기

int addLoop(int start, int end)
{
	return (end - start + 1) * (end + start) / 2;
}

int cnt = 0;

int expressions(int testCase) // 정수론으로 푼 다른 사람 함수
{
	int answer = 0;
	int to = ceil((-1 + sqrt(1 + 8 * testCase)) / 2);
	for (int i = 1; i <= to; i++)
	{
		++cnt;

		if (i % 2 == 1 && testCase % i == 0)
		{
			answer++;
		}
		else if (i % 2 == 0 && (testCase % i) == (i / 2))
		{
			answer++;
		}
	}

	return answer;
}

int solution(int n)
{
	int answer = 1;
	int half = n / 2 + 1;
	int quad = 0;
	int start = 0;
	int end = 0;
	int mid = 0;

	for (int i = 1; i < half; ++i)
	{
		quad = (half + i) / 2;
		mid = addLoop(i, quad);

		if (mid >= n)
			end = quad;
		else
			end = half;
		
		for (int j = i+1; j <= end; ++j)
		{
			int add = addLoop(i, j);

			if (n < add)
				break;

			if (n == add)
			{
				++answer;
				break;
			}
		}
	}

	return answer;
}

//int main()
//{
//	cout << expressions(10000) << endl;
//	cout << cnt << endl;
//}