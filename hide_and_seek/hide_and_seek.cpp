#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N, K;
	int cnt;
	int pos;
	int ans;
	bool invit[100000];

	fill(invit, invit + 100000, false);

	queue<pair<int, int>> data;

	scanf("%d %d", &N, &K);

	data.emplace(N, 0);
	invit[N] = true;
	while (1)
	{
		pos = data.front().first;
		cnt = data.front().second;

		if (pos - 1 >= 0 && invit[pos - 1] != true)
		{
			if (pos - 1 == K)
			{
				ans = cnt+1;
				break;
			}
			data.emplace(pos - 1, cnt + 1);
	//		printf("%d line front : %d %d\n", __LINE__,data.front().second, data.front().first);
	//		printf("%d : %d\n", cnt + 1, pos - 1);
			invit[pos - 1] = true;
		}

		if (pos + 1 <100000 && invit[pos + 1] != true )
		{
			if (pos + 1 == K)
			{
				ans = cnt + 1;
				break;
			}
			data.emplace(pos + 1, cnt + 1);
		//	printf("%d line front : %d %d\n", __LINE__, data.front().second, data.front().first);
			//printf("%d : %d\n", cnt + 1, pos + 1);
			invit[pos + 1] = true;
		}

		if (2 * pos <100000 && invit[pos * 2] != true)
		{
			if (pos * 2 == K)
			{
				ans = cnt + 1;
				break;
			}
			data.emplace(pos * 2, cnt + 1);
	//		printf("%d line front : %d %d\n", __LINE__, data.front().second, data.front().first);
	//		printf("%d : %d\n", cnt + 1, pos *2);
			invit[pos *2] = true;
		}
		data.pop();

	}

	printf("%d\n", ans);

	fclose(fp);

	return 0;
}