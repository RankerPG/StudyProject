#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace worry
{
	string solution(string sentence)
	{
		string answer = "";
		string strAdd = "";
		vector<char> vec;

		int len = sentence.size();

		char outToken = '\0', inToken = '\0';

		bool inadd = false;

		for (int i = 0; i < len; ++i)
		{
			if ('a' <= sentence[i] && 'z' >= sentence[i])
			{
				if (true == strAdd.empty())
				{
					if (true == inadd && '\0' != outToken)
					{
						inadd = false;
						outToken = '\0';
						continue;
					}

					if ('\0' != outToken)
						return "invalid";

					outToken = sentence[i];
					int vecSize = vec.size();
					for (int j = 0; j < vecSize; ++j)
					{
						if (outToken == vec[j])
							return "invalid";
					}
					vec.push_back(outToken);
					inadd = false;
				}
				else
				{
					if ('\0' == outToken && '\0' == inToken && i - 2 >= 0 && 'A' <= sentence[i - 2] && 'Z' >= sentence[i - 2])
					{
						answer += strAdd;
						answer += ' ';
						strAdd.clear();
						outToken = sentence[i];
						inadd = false;
					}
					else if (outToken == sentence[i])
					{
						if (false == inadd)
						{
							answer += strAdd;
							outToken = '\0';
							strAdd.clear();
							if (i + 1 < len)
								answer += " ";
						}
					}
					else if ('\0' == inToken)
					{
						if ('a' <= sentence[i + 1] && 'z' >= sentence[i + 1])
							return "invalid";

						inToken = sentence[i];
						int vecSize = vec.size();
						for (int j = 0; j < vecSize; ++j)
						{
							if (inToken == vec[j])
								return "invalid";
						}
						vec.push_back(inToken);
						inadd = false;
					}
					else if ('\0' != inToken)
					{
						if (i + 2 < len && inToken != sentence[i + 2])
						{
							if (i + 4 < len && sentence[i + 2] == sentence[i + 4])
								return "invalid";

							if ('a' <= sentence[i + 1] && 'z' >= sentence[i + 1])
								return "invalid";

							strAdd += sentence[i + 1];
							answer += strAdd;
							inToken = '\0';
							strAdd.clear();
							inadd = true;
							if (i + 2 < len)
								answer += " ";
							++i;
						}
						else if (i + 2 >= len)
						{
							strAdd += sentence[i + 1];
							answer += strAdd;
							strAdd.clear();
						}
					}
				}
			}
			else if (' ' != sentence[i])
			{
				strAdd += sentence[i];
			}
		}

		if (false == strAdd.empty())
			answer += strAdd;

		return answer;
	}
}

//int main()
//{
//	cout << worry::solution("aAbBbCa") << endl;
//	return 0;
//}