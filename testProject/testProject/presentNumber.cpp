#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace presentNumber
{
	int NumberDFS(int p_n, int p_number, int p_addN, int p_cnt)
	{
		int checkCnt = 9;
		int tempCnt = 0;

		if (p_addN == p_number)
			return p_cnt;
		if (8 < p_cnt)
			return 9;

		tempCnt = NumberDFS(p_n, p_number, p_addN * 10 + p_n, p_cnt + 1);
		if (tempCnt < checkCnt)
			checkCnt = tempCnt;

		tempCnt = NumberDFS(p_n, p_number, p_addN + 10 * p_n, p_cnt + 1);
		if (tempCnt < checkCnt)
			checkCnt = tempCnt;

		tempCnt = NumberDFS(p_n, p_number, p_addN * p_n, p_cnt + 1);
		if (tempCnt < checkCnt)
			checkCnt = tempCnt;

		tempCnt = NumberDFS(p_n, p_number, p_addN / p_n, p_cnt + 1);
		if (tempCnt < checkCnt)
			checkCnt = tempCnt;

		tempCnt = NumberDFS(p_n, p_number, p_addN + p_n, p_cnt + 1);
		if (tempCnt < checkCnt)
			checkCnt = tempCnt;

		tempCnt = NumberDFS(p_n, p_number, p_addN - p_n, p_cnt + 1);
		if (tempCnt < checkCnt)
			checkCnt = tempCnt;

		if (1 != p_n)
		{
			tempCnt = NumberDFS(p_n, p_number, p_addN + 1, p_cnt + 2);
			if (tempCnt < checkCnt)
				checkCnt = tempCnt;

			tempCnt = NumberDFS(p_n, p_number, p_addN - 1, p_cnt + 2);
			if (tempCnt < checkCnt)
				checkCnt = tempCnt;
		}

		return checkCnt;
	}

	int solution(int N, int number)
	{
		int answer = 0;

		answer = NumberDFS(N, number, N, 1);
		// DFS or BFS로 생각해보는 습관을 가져야 될 듯..


		if (8 < answer)
			return -1;

		return answer;
	}
}

//int main()
//{
//	cout << solution(5, 55) << endl;
//
//	return 0;
//}

/*
struct compareNum
{
	compareNum(int p_n, int p_cnt)
		: n(p_n)
		, cnt(p_cnt) {}

	int	n;
	int cnt;
};

bool Compare(compareNum p_src, compareNum p_dst)
{
	return p_src.n > p_dst.n;
}

int solution(int N, int number)
{
	int answer = 0;
	int check = 0;
	int cnt = 0;
	int size = 0;

	int addN = N;
	int mulN = N;

	vector<compareNum> compare;

	if (1 == N)
	{
		compare.push_back(compareNum(1, 1));
		compare.push_back(compareNum(11, 2));
		compare.push_back(compareNum(111, 3));
		compare.push_back(compareNum(1111, 4));
		compare.push_back(compareNum(11111, 5));
	}
	else
	{
		for (int i = 0; i < 16; ++i)
		{
			if (mulN > 32000)
				break;

			compare.push_back(compareNum(mulN, i+1));
			mulN *= N;
		}

		//
		for (int i = 0; i < 4; ++i)
		{
			addN *= 10;
			addN += N;
			compare.push_back(compareNum(addN, i + 2));
		}

		compare.push_back(compareNum(1, 2));
		compare.push_back(compareNum(11, 3));
		compare.push_back(compareNum(111, 4));
		compare.push_back(compareNum(1111, 5));
		compare.push_back(compareNum(11111, 6));
	}

	compare.push_back(compareNum(12, 4));
	compare.push_back(compareNum(122, 6));
	compare.push_back(compareNum(1222, 8));
	compare.push_back(compareNum(12222, 10));

	sort(compare.begin(), compare.end(), Compare);

	size = compare.size();

	while (0 != number)
	{
		for (int i = 0; i < size; ++i)
		{
			if (number >= compare[i].n)
			{
				number -= compare[i].n;
				cnt += compare[i].cnt;
				break;
			}
		}
	}

	if (8 < cnt)
		answer = -1;
	else
		answer = cnt;

	return answer;
}
*/