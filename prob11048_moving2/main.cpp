#include <iostream>
#include <cstdio>
#include <vector>

#define MAX(a,b) ((a) > (b) ? (a) : (b) )
#define USE_INPUT_FILE

using namespace std;

int main(void)
{

#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif
	int N, M;

	scanf("%d %d", &N, &M);

	vector<vector<int>> A(1001);
	vector<vector<int>> d(1001);

	for (int i = 0; i < 1001; i++)
	{
		A[i].resize(1001);
		d[i].resize(1001);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{

		for (int j = 1; j <= M; j++)
		{

			d[i][j] = MAX(MAX(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + A[i][j];
		}
	}


	printf("%d\n", d[N][M]);

#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}