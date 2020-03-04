#include <cstdio>

using namespace std;

int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int N, M;

	scanf("%d %d", &N, &M);

	int arr[101] = { 0, };

	int ans = 0;
	int tmp = 0;

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &(arr[i]));
	}
	for (int i = 1; i <= N-2; ++i) {
		for (int j = i + 1; j <= N - 1; ++j) {
			for (int k = j + 1; k <= N; ++k) {
				tmp = arr[i] + arr[j] + arr[k];
				if (tmp > ans && M >= tmp) {
					ans = tmp;
				}
			}
		}
	}

	printf("%d", ans);
	fclose(fp);

	return 0;
}