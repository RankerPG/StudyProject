#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
	int copyN = n;
	int threeCnt = 0;
	int addCnt = 0;

	while (0 != copyN)
	{
		addCnt += copyN % 3;
		copyN /= 3;
		++threeCnt;
	}

	return 0;
}

int main()
{
	cout << solution(2147483647) << endl;

	return 0;
}