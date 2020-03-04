#include <cstdio>
#include <cstdlib>
#include <cstring>
int arr[21] = { 0, };

int fibo(int n) {
	if (arr[n] != -1) {
		return arr[n];
	}

	if (n == 0) {
		arr[n] = 0;
		return arr[n];
	}
	else if (n == 1) {
		arr[n] = 1;
		return arr[n];
	}
	else {
		arr[n] =  fibo(n-2) + fibo(n - 1);
		return arr[n];
	}
}

int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < 21; ++i) {
		arr[i] = -1;
	}

	printf("%d", fibo(N));

	fclose(fp);
	return 0;
}