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
	int index = -1;

	bool backLoop = false;

	for (int i = 0; i < len; ++i)
	{
		if ('A' != name[i])
		{
			++index;

			if ('N' >= name[i])
			{
				//answer += name[i] - 'A';
			}
			else
			{
				//answer += 'Z' - name[i] + 1;
			}

			if (i != index)
			{
				if (i - index > index + len - i)
				{
					answer += index + len - i;
					backLoop = true;
				}

				index = i;
			}
		}
	}

	if (false == backLoop)
		answer += index;

	return answer;
}

int main()
{
	solution("JAN");

	return 0;
}