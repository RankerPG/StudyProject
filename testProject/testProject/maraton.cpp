#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	vector<vector<int>> vec(10);
	vector<int>::iterator iter, iter_end;

	int size = completion.size();
	int len = 0;
	int hash = 0;
	int index = 0;

	bool find = false;

	for (int i = 0; i < size; ++i)
	{
		len = completion[i].size();
		hash = 0;

		for (int j = 0; j < len; ++j)
			hash += completion[i][j] * (j + 1) * (j + 1);

		vec[hash % 10].push_back(hash);
	}

	//
	++size;

	for (int i = 0; i < size; ++i)
	{
		len = participant[i].size();
		hash = 0;
		find = false;

		for (int j = 0; j < len; ++j)
			hash += participant[i][j] * (j + 1) * (j + 1);

		index = hash % 10;
		iter = vec[index].begin();
		iter_end = vec[index].end();

		for (; iter != iter_end; ++iter)
		{
			if (*iter == hash)
			{
				find = true;
				vec[index].erase(iter);
				break;
			}
		}

		if (false == find)
		{
			answer += participant[i];
			break;
		}
	}
	return answer;
}

//int main()
//{
//	vector<string> vec({ "leo", "kiki", "eden" });
//	vector<string> vec2({ "kiki", "eden" });
//
//	solution(vec, vec2);
//}