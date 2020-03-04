#include <cstdio>

int main(void) {
	
	FILE *fp = freopen("input.txt", "r", stdin);
	int T;
	int n, k;

	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &n);
		scanf("%d", &k);

		long long arr[15][15] = { 0, };

		for (int j = 0; j <= n; ++j) {
			for (int l = 1; l <= k; ++l) {
				if (j == 0) {
					arr[j][l] = l;
				}
				else {
					arr[j][l] = arr[j - 1][l] + arr[j][l - 1];
				}

			}
		}

		printf("%lld\n", arr[n][k]);
	}
	fclose(fp);

	return 0;
	
}