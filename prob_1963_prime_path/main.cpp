#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
	if (n < 1000)
		return false;

	for (int i = 2; i < n / 2; i++)
	{
		if (n%i == 0)
			return false;
	}

	return true;
}


int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int T;
	int from;
	int to;

	scanf("%d", &T);

	for (int TC = 0; TC < T; TC++)
	{
		scanf("%d %d", &from, &to);
		queue<int> q;
		bool check[10000] = { 0, };
		int dist[10000] = { 0, };

		q.push(from);
		check[from] = true;
		dist[from] = 0;

		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					int temp = now;
					switch (i)
					{
					case 0:
						temp = temp - temp % 10 + j;
						break;
					case 1:
						temp = temp - (temp / 10 % 10) * 10 + 10 * j;
						break;
					case 2:
						temp = temp - (temp / 100 % 10) * 100 + 100 * j;
						break;
					case 3:
						temp = temp - temp / 1000*1000 + 1000 * j;
						break;
					}
					//printf("°Ë»ç : %d\n", temp);
					if (isPrime(temp))
					{
						if (check[temp] == false)
						{
							q.push(temp);
							check[temp] = true;
							dist[temp] = dist[now] + 1;
							if (check[to])
								goto RESULT;

						}
					}
					
				}
				//printf("\n");
			}


		}

RESULT:
		if (check[to])
			printf("%d\n", dist[to]);
		else
			printf("Impossible\n");


	}

	fclose(fp);

	return 0;
}