#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	FILE *fp = freopen("input.txt", "r", stdin);

	int N, M;
	scanf("%d %d", &N, &M);

	char arr[51][51];
	memset(arr, -1, 51 * 51);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			char temp;
			scanf("%c", &temp);
			if (temp == 'W')
			{
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= M - 7; ++i) {
		for (int j = 1; j <= N - 7; ++j) {
			
		}
	}


	fclose(fp);

	return 0;
}