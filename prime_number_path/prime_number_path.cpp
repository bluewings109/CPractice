#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

bool isPrime(int n)
{
	int i = 0;
	int last = n / 2;   //약수가 없는 수가 소수이므로 2부터 n/2(자기자신/2)까지만 확인하면 됨
	if (n <= 1)//소수는 1보다 큰 자연수여야 함
	{
		return 0;
	}
	//(자기자신/2)보다 큰수는 약수가 될 수 없음
	for (i = 2; i <= last; i++) //i를 2부터 last까지 1씩 증가시키며 반복 수행
	{
		if ((n%i) == 0) //n을 i로 나누었을때 나머지가 0이면(즉, i는 n의 약수가 아님)
		{
			return false; //소수가 아니므로 0반환(i가 약수이므로 n은 소수가 아님)
		}
	}
	return true; //1~last(자기자신/2)사이에 약수가 없으므로 소수임
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int T;
	int n, m;

	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &n, &m);

		queue<int> q;
		bool check[10000];
		int dist[10000] = { 0, };
		int now;
		int next;
		fill(check, check + 10000, false);

		q.push(n);
		dist[n] = 0;
		check[n] = true;

		while (!q.empty())
		{
			
			now = q.front();
			q.pop();
			for (int j = 0; j < 10; j++)
			{
				next = now - now % 10 + j;
				if (next&1==1 && check[next] == false && isPrime(next) )
				{
					q.push(next);
					check[next] = true;
					dist[next] = dist[now] + 1;
					if (next == m)
						break;
				}
				
				next = now - (now - now % 10) % 100 + j * 10;
				if (check[next] == false &&isPrime(next))
				{
					q.push(next);
					check[next] = true;
					dist[next] = dist[now] + 1;
					if (next == m)
						break;
				}

				next = now - (now - now % 100) % 1000 + j * 100;
				if (check[next] == false && isPrime(next))
				{
					q.push(next);
					check[next] = true;
					dist[next] = dist[now] + 1;
					if (next == m)
						break;

				}
				
				next = now % 1000 + j * 1000;
				if (check[next] == false && next >= 1000 && isPrime(next))
				{
					q.push(next);
					check[next] = true;
					dist[next] = dist[now] + 1;
					if (next == m)
						break;
				}
			}
		}
		printf("%d\n", dist[m]);
	}


	fclose(fp);
	return 0;
}