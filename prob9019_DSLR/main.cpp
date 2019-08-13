#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

enum {D, S, L, R};

int next(int n, int command)
{
	int ret;

	switch (command)
	{
	case D: 
		ret = (2*n)%10000;
		break;
	case S: 
		ret = n == 0 ? 9999 : n-1;
		break;
	case L :
		ret = (n % 1000 * 10) + n / 1000;
		break;
	case R :
		ret = n / 10 + n % 10 * 1000;
		break;
	}
	return ret;
}
int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int T;
	int from;
	int to;

	string ch[4] = { "D","S","L","R" };

	scanf("%d", &T);

	for (int TC = 0; TC < T; TC++)
	{
		bool check[10000] = { 0, };
		queue<int> q;
		string s[10000];
		
		scanf("%d %d", &from, &to);

		check[from] = true;
		q.push(from);
		s[from] = "";
		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (int i = D; i <= R; i++)
			{
				int temp;
				temp = next(now, i);
				if (check[temp] == false)
				{
					q.push(temp);
					check[temp] = true;
					s[temp] = s[now] + ch[i];
					if (check[to] == true)
						goto RESULT;
				}
			}
		}

RESULT:
		printf("%s\n", s[to].c_str());

	}
	fclose(fp);
	return 0;
}