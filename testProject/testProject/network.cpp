#include <string>
#include <vector>

using namespace std;

void networkDFS(int p_n, int p_target, bool p_check[], vector<vector<int>> p_computers)
{
	int size = p_computers.size();

	p_check[p_target] = true;

	for (int i = 0; i < size; ++i)
	{
		if (i != p_target && 1 == p_computers[p_target][i] && false == p_check[i])
		{
			networkDFS(p_n, i, p_check, p_computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	bool check[200] = { false, };

	int size = computers.size();

	for (int i = 0; i < size; ++i)
	{
		if (false == check[i])
		{
			networkDFS(n, i, check, computers);
			++answer;
		}
	}

	return answer;
}

/*
int solution(int n, vector<vector<int>> computers) // 왜 안되는지 확인해보기
{
	int answer = 0;
	bool check[200] = { false, };

	int size = computers.size();

	for (int i = 0; i < size; ++i)
	{
		bool newNetwork = true;

		for (int j = 0; j < size; ++j)
		{
			if (1 == computers[i][j])
			{
				if (true == check[j])
					newNetwork = false;
				else
					check[j] = true;
			}
		}

		if (true == newNetwork)
			++answer;
	}

	return answer;
}
*/