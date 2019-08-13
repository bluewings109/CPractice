#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE

using namespace std;

long long d[201][201] = { 0, };

int main(void)
{
#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif

	int N, K;
	scanf("%d %d", &N, &K);
	

	for (int i = 0; i <= N; i++)
	{
		d[i][1] = 1;
		d[i][2] = i + 1;
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 3; j <= K; j++)
		{
			for (int h = 0; h <= i; h++)
			{
				d[i][j] += d[h][j - 1]%1000000000;
			}
		}
	}

	printf("%lld\n", d[N][K]%1000000000);

#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}