#include <string>
#include <vector>

using namespace std;

class CHeap
{
public:
	CHeap(int p_size)
		: m_size(p_size)
		, m_cnt(0)
	{
		m_arrHeap = new int[m_size + 1];
	}

	~CHeap()
	{
		delete[] m_arrHeap;
	}

public:
	void WalkUp()
	{
		int index = m_cnt;
		int parent = 0;

		while (1 != index)
		{
			parent = index / 2;

			if (m_arrHeap[index] > m_arrHeap[parent])
			{
				int temp = m_arrHeap[index];
				m_arrHeap[index] = m_arrHeap[parent];
				m_arrHeap[parent] = temp;
				index = parent;
			}
			else
				break;
		}
	}

	void WalkDown()
	{
		int index = 1;
		int child = 2;

		while (child < m_cnt)
		{
			if (m_arrHeap[child] > m_arrHeap[child + 1])
			{
				if (m_arrHeap[index] < m_arrHeap[child])
				{
					int temp = m_arrHeap[index];
					m_arrHeap[index] = m_arrHeap[child];
					m_arrHeap[child] = temp;
					index = child;
				}
				else
					break;
			}
			else
			{
				if (m_arrHeap[index] < m_arrHeap[child + 1])
				{
					int temp = m_arrHeap[index];
					m_arrHeap[index] = m_arrHeap[child + 1];
					m_arrHeap[child + 1] = temp;
					index = child + 1;
				}
				else
					break;
			}

			child = index * 2;
		}
	}

	void Enqueue(int p_data)
	{
		m_arrHeap[++m_cnt] = p_data;

		WalkUp();
	}

	void Dequeue()
	{
		m_arrHeap[1] = m_arrHeap[m_cnt--];

		WalkDown();
	}

	int Top()
	{
		return m_arrHeap[1];
	}

public:
	int*	m_arrHeap;
	int		m_size;
	int		m_cnt;
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int answer = 0;
	int size = dates.size();
	int index = 0;

	CHeap heap(size);

	while (true)
	{
		if (stock >= k - 1)
			break;

		for (; index < size; ++index)
		{
			if (stock >= dates[index] - 1)
				heap.Enqueue(supplies[index]);
			else
				break;
		}

		if (0 != heap.m_cnt)
		{
			stock += heap.Top();
			heap.Dequeue();
			++answer;
		}
	}



	return answer;
}

//int main()
//{
//	return 0;
//}