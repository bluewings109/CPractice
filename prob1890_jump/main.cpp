#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE

using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);

	int A[101][101] = { 0, };
	long long d[101][101] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	d[1][1] = 1;
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; i - k >= 1; k++)
			{
				if (A[i - k][j] == k)
					d[i][j]+=d[i-k][j];
			}
			for (int k = 1; j - k >= 0; k++)
			{
				if (A[i][j-k] == k)
					d[i][j]+=d[i][j-k];
			}
		}
	}

	printf("%lld\n", d[n][n]);
	return 0;
}