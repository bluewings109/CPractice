#include <cstdio>

using namespace std;

int dp[31][31];

int combination(int n, int r)
{
	if (dp[n][r] != 0)
		return dp[n][r];

	if (dp[n][n - r] != 0)
		return dp[n][n - r];
	
	if (r == 0 || n==r)
		return dp[n][r]=1;

	if (r == 1)
		return dp[n][r]=n;

	return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
	

}
int main(void)
{
	freopen("input.txt", "r", stdin);

	int TC;
	
	int N, M;
	
	scanf("%d", &TC);

	for (int i = 0; i < TC; i++)
	{
		scanf("%d %d", &N, &M);

		printf("%d\n", combination(M, N));

	}
	return 0;
}