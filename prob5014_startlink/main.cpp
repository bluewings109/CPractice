#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int height, start, goal, up, down;
	queue<int> q;

	scanf("%d %d %d %d %d", &height, &start, &goal, &up, &down);

	bool *check = new bool[height+1];
	int *dist = new int[height + 1];


	fill(check, check + height+1, false);
	fill(dist, dist + height+1, 0);

	check[start] = true;
	dist[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		int next = now + up;
		if (1 <= next && next <= height)
		{
			if (check[next] == false)
			{
				q.push(next);
				dist[next] = dist[now] + 1;
				check[next] = true;
				if (next == goal)
					goto RESULT;
				
			}
		}

		next = now - down;
		if (1 <= next && next <= height)
		{
			if (check[next] == false)
			{
				q.push(next);
				dist[next] = dist[now] + 1;
				check[next] = true;
				if (next == goal)
					goto RESULT;
			}
		}
	}

RESULT:
	if (check[goal] == true)
		printf("%d\n", dist[goal]);
	else
		printf("use the stairs\n");

	delete[] check;
	delete[] dist;
	fclose(fp);
	return 0;
}