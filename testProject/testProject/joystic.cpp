#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ּ� �ε��� �Ÿ��� �ּ� ���ĺ� �Ÿ� ���ϱ�
// ���̸� ������ ������ ���Ѵ�
// 'N'�� �������� ������ ���Ѵ�

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