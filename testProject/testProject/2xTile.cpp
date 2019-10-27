#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace tile
{
	unsigned long long TileDFS(int p_n)
	{
		if (1 == p_n)
			return 1;
		else if (2 == p_n)
			return 2;

		unsigned long long cnt = 0;
		unsigned long long first = 1, second = 2;
		int times = 3;

		while (p_n >= times)
		{
			cnt = (first + second) % 1000000007; // 나누기를 어디서 하라는지 애매하게 표시되있어서 풀었는데 오래걸림..
			first = second;
			second = cnt;
			++times;
		}

		return cnt;
	}

	int solution(int n)
	{
		int answer = TileDFS(n);

		return answer;
	}
}

//int main()
//{
//	cout << tile::solution(60000) << endl;
//}