#include <cstdio>

int main(void)
{
	FILE *fp = freopen("input.txt", "r", stdin);

	int T;
	int H, W, N;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);
		int h, w;

		if (N%H == 0) {
			h = H;
			w = N / H;
		}
		else {
			h = N % H;
			w = N / H + 1;
		}


//		printf("%d %d %d\n", H, W, N);
//		printf("%d %d\n", h, w);
		printf("%d\n", h * 100 + w);
	}

	fclose(fp);
	return 0;
}