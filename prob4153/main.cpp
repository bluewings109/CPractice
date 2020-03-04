#include <cstdio>

#define MAX(A,B) (((A)>(B)) ? (A) : (B))

int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int a, b, c;
	int max;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		max = MAX(MAX(a, b), c);

		if (max == a) {
			if (max*max == b * b + c * c) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		} else if (max == b) {
			if (max*max == a * a + c * c) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		}
		else if (max == c) {
			if (max*max == a * a + b * b) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		}
	}
	fclose(fp);
	return 0;
}