#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool Descending(int p_src, int p_dst)
{
	return p_src > p_dst;
}

long long solution(int n, vector<int> works)
{
	// 내림차순으로 정렬 후 오른쪽과 같을때까지 줄이고 같다면 같이 줄인다
	long long answer = 0;
	int size = works.size();
	int index = 0;
	int gap = 0;

	sort(works.begin(), works.end(), Descending);

	while (0 != n)
	{
		if (0 == works[index])
			break;

		if (size > index + 1)
			gap = works[index] - works[index + 1];
		else
			gap = 1;

		if (0 < gap)
		{
			--works[index];
			--n;
			if (0 != index)
				--index;
		}
		else if (0 == gap)
		{
			++index;
		}
	}

	for (int i = 0; i < size; ++i)
		answer += pow(works[i], 2);

	return answer;
}

//int main()
//{
//	vector<int> vec;
//	vec.push_back(1);
//	vec.push_back(1);
//
//	cout << solution(3, vec) << endl;
//
//	return 0;
//}