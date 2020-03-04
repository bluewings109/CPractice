#include <cstdio>
#include <vector>
#include <algorithm>

#define PLUS 1
#define MINUS 2
#define MULTI 3
#define DIV 4

#define MAX(A,B) ( ( (A) > (B) ) ? (A) : (B) )
#define MIN(A,B) ( ( (A) > (B) ) ? (B) : (A) )

int num[12] = { 0, };
char oper[11] = { 0, };
int N;
int calc() {
	int ret = 0;
	ret = num[1];
	for (int i = 1; i <= N-1; ++i) {
		if (oper[i] == PLUS) {
			ret += num[i + 1];
		}
		else if (oper[i] == MINUS) {
			ret -= num[i + 1];
		}
		else if (oper[i] == MULTI) {
			ret *= num[i + 1];
		}
		else if (oper[i] == DIV) {
			ret /= num[i + 1];
		}
	}

	return ret;

}
using namespace std;
int main(void) {

	FILE *fp = freopen("input.txt", "r", stdin);




	int plus, minus, multiply, divide;

	int max = 0X80000000;
	int min = 0x7FFFFFFF;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &(num[i]));
	}

	scanf("%d %d %d %d", &plus, &minus, &multiply, &divide);

	int cnt = 1;
	for (int i = 0; i < plus; ++i) {
		oper[cnt++] =  PLUS;
	}

	for (int i = 0; i < minus; ++i) {
		oper[cnt++] =  MINUS;
	}


	for (int i = 0; i < multiply; ++i) {
		oper[cnt++] =  MULTI;
	}


	for (int i = 0; i < divide; ++i) {
		oper[cnt++] =  DIV;
	}
	do {
		int temp = calc();
		//printf("%d", num[1]);
		//for (int i = 1; i <= N - 1; ++i) printf("%c%d", oper[i], num[i + 1]);
		//printf(" = %d\n", temp);
		max = MAX(max, temp);
		min = MIN(min, temp);
	} while (next_permutation(oper+1, oper + N));

	printf("%d\n%d", max, min);

	fclose(fp);
	return 0;

}
