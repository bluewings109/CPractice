#include <iostream>
#include <cstdio>

#define MAX(a,b) ((a) > (b) ? (a) : (b) )
#define USE_INPUT_FILE

using namespace std;

int main(void)
{

	printf("***");
#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif
	int N, M;
	printf("***");
	scanf("%d %d", &N, &M);
	printf("***");
	int A[1001][1001] = { 0, };
	int d[1001][1001] = { 0, };

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		printf("***");
		for (int j = 1; j <= M; j++)
		{
			printf("***");
			d[i][j] = MAX(MAX(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + A[i][j];
		}
	}

	printf("***");

	printf("%d\n", d[N][M]);

#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}