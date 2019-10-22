#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 최소 인덱스 거리와 최소 알파벳 거리 구하기
// 길이를 반으로 나눠서 더한다
// 'N'을 기준으로 나눠서 더한다

int solution(string name)
{
	int answer = 0;
	int len = name.size();
	int path = len - 1;
	int index = 0;

	for (int i = 0; i < len; ++i)
	{
		if ('N' >= name[i])
			answer += name[i] - 'A';
		else
			answer += 'Z' - name[i] + 1;

		if ('A' != name[i] && 0 != i)
		{
			int backPath = (index * 2) + path - i + 1;
			if (path > backPath)
				path = backPath;
			index = i;
		}
	}

	answer += path;

	return answer;
}

//int main()
//{
//	cout << solution("CANAAAAANAN") << endl;
//
//	return 0;
//}