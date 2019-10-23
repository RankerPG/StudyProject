#include <string>
#include <vector>

using namespace std;
// 삼각형 밑부터 최대값을 가지도록 만들어 꼭대기값을 리턴

int solution(vector<vector<int>> triangle)
{
	int answer = 0;
	int size = triangle.size();
	int layerLen = 0;

	for (int i = size - 2; i >= 0; --i)
	{
		layerLen = triangle[i].size();

		for (int j = 0; j < layerLen; ++j)
		{
			triangle[i][j] += triangle[i + 1][j] > triangle[i + 1][j + 1] ?
				triangle[i + 1][j] : triangle[i + 1][j + 1];
		}
	}

	answer = triangle[0][0];

	return answer;
}