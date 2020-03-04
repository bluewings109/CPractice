#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>

int main(void)
{
	FILE *fp = freopen("input.txt", "r", stdin);
	
	int r = 0;

	scanf("%d", &r);

	double ans = 0.0;

	printf("%f\n%f", r*r*M_PI, (double)r*r * 2);
	
	

	
	fclose(fp);

	return 0;
}