#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int arr[555][555];
int dist[555][555];
int N, M;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
			dist[i][j] = -1;
		}
	}
	

	deque<pair<int, int>> deq;
	deq.push_back(make_pair(0, 0));
	dist[0][0] = 0;

	while (!deq.empty())
	{
		int x = deq.front().first;
		int y = deq.front().second;
		deq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0<=ny && ny<M )
			{
				if (dist[nx][ny] == -1)
				{
					if (arr[nx][ny] == 0)
					{
						dist[nx][ny] = dist[x][y];
						deq.push_front(make_pair(nx, ny));
					}
					else
					{
						dist[nx][ny] = dist[x][y] + 1;
						deq.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
	printf("%d\n", dist[N-1][M-1]);

	
	fclose(fp);

	return 0;
}