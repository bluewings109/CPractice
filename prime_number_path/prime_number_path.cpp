#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

bool isPrime(int n)
{
	int i = 0;
	int last = n / 2;   //����� ���� ���� �Ҽ��̹Ƿ� 2���� n/2(�ڱ��ڽ�/2)������ Ȯ���ϸ� ��
	if (n <= 1)//�Ҽ��� 1���� ū �ڿ������� ��
	{
		return 0;
	}
	//(�ڱ��ڽ�/2)���� ū���� ����� �� �� ����
	for (i = 2; i <= last; i++) //i�� 2���� last���� 1�� ������Ű�� �ݺ� ����
	{
		if ((n%i) == 0) //n�� i�� ���������� �������� 0�̸�(��, i�� n�� ����� �ƴ�)
		{
			return false; //�Ҽ��� �ƴϹǷ� 0��ȯ(i�� ����̹Ƿ� n�� �Ҽ��� �ƴ�)
		}
	}
	return true; //1~last(�ڱ��ڽ�/2)���̿� ����� �����Ƿ� �Ҽ���
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