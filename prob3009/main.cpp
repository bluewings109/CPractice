#include <cstdio>

int main(void)
{
	FILE *fp = freopen("input.txt", "r", stdin);
	char garo[1001] = { 0, };
	char sero[1001] = { 0, };
	
	int a, b;

	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &a, &b);
		garo[a]++;
		sero[b]++;
	}
	for (int i = 1; i <= 1000; ++i) {
		if (garo[i] == 1)
			a = i;

		if (sero[i] == 1)
			b = i;
	}

	printf("%d %d", a, b);
	fclose(fp);
	return 0;
}