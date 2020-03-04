#include <cstdio>

long long fact(long long n) {
	if (n <= 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		return n * fact(n - 1);
	}
}
int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int N;

	scanf("%d", &N);

	printf("%lld", fact(N));
	fclose(fp);
	return 0;
}