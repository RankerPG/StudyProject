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