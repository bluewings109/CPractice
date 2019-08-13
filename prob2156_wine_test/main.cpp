#include <iostream>
#include <cstdio>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;
	int wine[10002] = { 0, };
	int d[2][10002] = { 0, };
	int ans;

	/*
	 * d[0][i] : i��° ������ ������ ������ �ִ밪 --> �ٷ� �հ� ���̴� �ȸ��̴� �̹��� �ȸ��ô°� ������ �����ϹǷ�, �ٷ� �� ���̰ų� �ȸ��̰ų� �� ū���� �������� ��.
	 * d[1][i] : i��° ������ ������ �� �ִ� �� --> �ΰ� ���� �ȸ��ð� �ٷ� �տ��� ���ð� �̹��� ���ðų� //  �ΰ����� ���ð�, �ٷξտ��� �ȸ��ð� �̹��� ����
	*/
	scanf("%d", &n);

	for (int i = 2; i < n+2; i++)
	{
		scanf("%d", &wine[i]);
	}

	for (int i = 2; i < n + 2; i++)
	{
		d[0][i] = MAX(d[0][i - 1] , d[1][i - 1]);
		d[1][i] = MAX(d[0][i - 2] + wine[i-1], d[1][i - 2]) + wine[i];
	}

	ans = MAX(d[0][n + 1], d[1][n + 1]);

	printf("%d\n", ans);
	

	fclose(fp);
	return 0;
}