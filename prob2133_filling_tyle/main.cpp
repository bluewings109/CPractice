#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE
#ifdef USE_INPUT_FILE
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif

	int N;
	scanf("%d", &N);

	if (N % 2 != 0)
	{
		printf("%d\n", 0);
		return 0;
	}

	N /= 2;

	long long d[2][16] = { 0, };

	d[0][1] = 2;
	d[1][1] = 3;
	for (int i = 2; i <= N; i++)
	{
		d[0][i] = d[1][i - 1] * 2;
		d[1][i] = d[0][i - 1] + d[1][i - 1] * 3;
	}

	printf("%lld\n", d[1][N]);
#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}