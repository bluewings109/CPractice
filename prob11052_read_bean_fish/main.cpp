#include <iostream>
#include <cstdio>

using namespace std;

int d[1001] = { 0, };
int ans[1001] = { 0,};



int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}

	ans[1] = d[1];

	for (int i = 2; i <= n; i++)
	{

	}


	fclose(fp);
	return 0;
}