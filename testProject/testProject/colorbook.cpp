#include <vector>
#include <queue>

using namespace std;

int direction[4][2];

struct CELL
{
	int x;
	int y;
	int color;
};

int bfs(vector<vector<int>> p_mat, CELL p_cell, bool p_visit[][100], int m, int n)
{
	
	queue<CELL> q;
	q.push(p_cell);
	int color = p_cell.color;
	CELL cell;
	int cnt = 1;
	int x, y;

	while (!q.empty())
	{
		cell = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			x = cell.x + direction[i][0];
			y = cell.y + direction[i][1];

			if (0 <= x && n > x && 0 <= y && m > y && color == p_mat[y][x] && false == p_visit[y][x])
			{
				p_visit[y][x] = true;
				++cnt;
				CELL addCell;
				addCell.x = x;
				addCell.y = y;
				addCell.color = color;
				q.push(addCell);
			}
		}
	}

	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	bool visit[100][100] = { 0, };

	vector<int> answer(2);
	
	direction[0][0] = 0;
	direction[0][1] = -1;
	
	direction[1][0] = 1;
	direction[1][1] = 0;

	direction[2][0] = 0;
	direction[2][1] = 1;

	direction[3][0] = -1;
	direction[3][1] = 0;

	int cnt = 0;
	int maxSize = 0;
	int size = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (true == visit[i][j] || 0 == picture[i][j])
				continue;

			visit[i][j] = true;

			CELL cell;
			cell.x = j;
			cell.y = i;
			cell.color = picture[i][j];

			size = bfs(picture, cell, visit, m, n);

			if (maxSize < size)
				maxSize = size;

			++cnt;
		}
	}
	
	answer[0] = cnt;
	answer[1] = maxSize;

	return answer;
}

//int main()
//{
//	vector<vector<int>> vec;
//	vector<int> vec2;
//
//	vec.push_back(vector<int>({ 1, 1, 1, 0 }));
//	vec.push_back(vector<int>({ 1, 2, 2, 0 }));
//	vec.push_back(vector<int>({ 1, 0, 0, 1 }));
//	vec.push_back(vector<int>({ 0, 0, 0, 1 }));
//	vec.push_back(vector<int>({ 0, 0, 0, 3 }));
//	vec.push_back(vector<int>({ 0, 0, 0, 3 }));
//
//	solution(6, 4, vec);
//
//	return 0;
//}

/*
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	// 행마다 구역을 만들어서 저장
	// 행은 다른데 열이 같은 값이 있다면 같은 구역으로 판정
	vector<vector<COLORPOINT>> vecSection;
	vector<COLORPOINT> vecPoint;
	vector<int> answer;
	int cnt = 0;
	int maxSize = 0;
	int curColor = 0;
	int size = 0, size2 = 0;
	COLORPOINT pt, pt2;

	bool sameSection = false;

	for (int i = 0; i < m; ++i)
	{
		if (false == vecPoint.empty())
			vecSection.push_back(vecPoint);

		vecPoint.clear();

		for (int j = 0; j < n; ++j)
		{
			int indexColor = picture[i][j];

			if (0 != indexColor)
			{
				if (curColor != indexColor && 0 != vecPoint.size())
				{
					vecSection.push_back(vecPoint);
					vecPoint.clear();
				}

				COLORPOINT addpt = COLORPOINT();
				addpt.x = j;
				addpt.y = i;
				addpt.color = indexColor;
				vecPoint.push_back(addpt);
			}
			else if (false == vecPoint.empty())
			{
				vecSection.push_back(vecPoint);
				vecPoint.clear();
			}

			curColor = indexColor;
		}
	}

	if (false == vecPoint.empty())
	{
		vecSection.push_back(vecPoint);
		vecPoint.clear();
	}

	//정렬
	sort(vecSection.begin(), vecSection.end(), Ascending);

	//
	vector<vector<COLORPOINT>>::iterator iter = vecSection.begin();
	vector<vector<COLORPOINT>>::iterator iter_end = --vecSection.end();

	for (; iter != iter_end;)
	{
		if ((*iter)[0].color != (*(iter + 1))[0].color)
		{
			++iter;
			continue;
		}

		sameSection = false;

		size = iter->size();
		size2 = (iter + 1)->size();


		for (int i = 0; i < size; ++i)
		{
			if (true == sameSection)
				break;

			for (int j = 0; j < size2; ++j)
			{
				pt = (*iter)[i];
				pt2 = (*(iter + 1))[j];

				if (pt.x == pt2.x && 2 > abs(pt.y - pt2.y))
				{
					sameSection = true;
					break;
				}
			}
		}

		if (true == sameSection)
		{
			for (int j = 0; j < size2; ++j)
			{
				iter->push_back((*(iter + 1))[j]);
			}

			iter = vecSection.erase(iter + 1);
			--iter;
			iter_end = --vecSection.end();
		}
		else
			++iter;
	}

	//가장 큰 영역 찾기
	for (int i = 0; i < vecSection.size(); ++i)
	{
		int sectionSize = vecSection[i].size();

		if (maxSize < sectionSize)
			maxSize = sectionSize;
	}

	cnt = vecSection.size();

	answer.push_back(cnt);
	answer.push_back(maxSize);

	return answer;
}
*/