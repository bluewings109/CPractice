#include <iostream>
#include <cstdio>

using namespace std;

int d[1001][10] = { 0, };
const long long mod = 10007;
int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;
	int ans;
	scanf("%d", &n);

	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
		}
	}

	ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += d[n][i];
		ans %= mod;
	}
	printf("%d\n", ans);


	fclose(fp);
	return 0;
}