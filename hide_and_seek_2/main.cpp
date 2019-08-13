#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX 200001

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r",stdin);

	int N, K;
	bool check[MAX] = { 0, };
	int dist[MAX] = { 0, };

	queue<int> q;

	scanf("%d %d", &N, &K);

	q.push(N);
	check[N] = true;
	dist[N] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now - 1 >= 0)
		{
			if (check[now - 1] == false)
			{
				q.push(now - 1);
				dist[now - 1] = dist[now] + 1;
				check[now - 1] = true;
			}
		}

		if (now + 1 < MAX)
		{
			if (check[now + 1] == false)
			{
				q.push(now + 1);
				dist[now + 1] = dist[now]+1;
				check[now + 1] = true;
			}
		}

		if (now * 2 < MAX)
		{
			if (check[now * 2] == false)
			{
				q.push(now *2);
				dist[now *2] = dist[now]+1;
				check[now *2] = true;
			}
		}

	}
	
	printf("%d\n", dist[K]);

	fclose(fp);
	return 0;
}