#include <iostream>
#include <cstdio>
#include <algorithm>

#define USE_INPUT_FILE

#define MAX_INT32 0x7FFFFFFF

using namespace std;

int A[501][2] = { 0 };
int d[501][501] = { 0, };

int dynamic(int i, int j)
{
	if (d[i][j] != -1)
		return d[i][j];

	if (i == j)
	{
		d[i][j] = 0;
		return 0;
	}
	if (j - i == 1)
	{
		d[i][j] = A[i][0] * A[i][1] * A[i + 1][1];
		return d[i][j];
	}

	int temp=-1;
	int ans = MAX_INT32;
	for (int k = i + 1; k <= j - 1; k++)
	{
		temp = dynamic(i, k - 1) + dynamic(k, j);
		ans = ans > temp ? temp : ans;

	}
	d[i][j] = ans;

	return ans;

}

int main(void)
{
#ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
#endif

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &A[i][0], &A[i][1]);
	}

	fill(&d[0][0], &d[500][500] + 1, -1);

	printf("%d\n", dynamic(1, N));
	
	return 0;
}