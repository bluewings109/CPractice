#include <iostream>

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int E, S, M;

	int e, s, m;

	int result;

	scanf("%d %d %d", &E, &S, &M);
	
	result = 1;
	e = s = m = 1;
	while (1)
	{
		if (e == E && s == S && m == M)
			break;

		++result;
		e++;
		s++;
		m++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;

	}

	printf("%d\n", result);
	fclose(fp);

	return 0;

}