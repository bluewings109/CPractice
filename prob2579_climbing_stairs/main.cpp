#include <cstdio>

using namespace std;

#define MAX(a,b) ( (a) > (b) ? (a) : (b) )

int stairs[301];
int dp[301][2];

int main(void)
{
	freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);


	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &stairs[i]);
	}

	dp[1][0] =dp[1][1] = stairs[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = MAX(dp[i - 2][0], dp[i - 2][1]) + stairs[i];
		dp[i][1] = dp[i - 1][0] + stairs[i];
	}

	printf("%d", MAX(dp[N][0], dp[N][1]));

	return 0;
}

