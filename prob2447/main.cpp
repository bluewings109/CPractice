#include <cstdio>

char arr[2188][2188] = { 0, };

void draw(int left, int right, int top, int bottom) {
//	printf("%d %d %d %d\n", left, right, top, bottom);
	int size = right-left+ 1;
	if (size == 3) {
		for (int i = top; i <= bottom; ++i) {
			for (int j = left; j <= right; ++j) {
				arr[i][j] = 1;
			}
		}
		arr[(top + bottom) / 2][(left + right) / 2] = 0;
	}
	else {
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				if (i == 2 && j == 2) {
					continue;
				}
				draw(left + (j - 1)*size / 3, left+(j - 1)*size / 3 + (size/3)-1, top+(i - 1)*size / 3, top+(i - 1)*size / 3 + (size / 3) - 1);
			}
		}
	}

	return;
}
int main(void) {
	
	FILE *fp = freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	draw(1, N, 1, N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%c", arr[i][j] == 1 ? '*' : ' ');
		}
		printf("\n");
	}


	fclose(fp);

	return 0;
}