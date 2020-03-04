#include<cstdio>

int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int a, b;

	a = (x > w / 2) ? w - x : x;
	b = (y > h / 2) ? h - y : y;

	printf("%d", (a > b) ? b : a);
	fclose(fp);
	return 0;
}