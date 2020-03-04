#include <cstdio>
#include <cmath>
using namespace std;

int digitSum(int n) {
	int digit=0;
	int ret = 0;
	int tmp = 0;
	int div = 0;
	// 1. 자리수 찾기
	for (int i = 6; i >= 0; --i) {
		if (n / (int)(pow(10, i) > 0)) {
			digit = i;
			break;
		}
	}

	div = (int)(pow(10, digit));
	for (int i = digit; i >= 0; --i) {
		tmp = n / div;
		ret += tmp;
		n = n - tmp * div;
		div = div / 10;
	}
	
	return ret;
}
int main(void) {
	FILE * fp = freopen("input.txt", "r", stdin);

	int N;
	int ans = 0;
	scanf("%d", &N);


	//printf("*************\n");
	for (int i = N - 1; i >= 0; --i) {
		if (N == i + digitSum(i)) {
		//	printf("*************\n");
			ans = i;
		}
	}
	printf("%d", ans);
	fclose(fp);
	return 0;
}