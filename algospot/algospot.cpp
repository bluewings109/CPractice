#include <iostream>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N, M;
	int map[101][101] = { 0, };
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int num;
			scanf("%d", &num);
			map[i][j] = num;
		}
	}

	fclose(fp);
	return 0;
}