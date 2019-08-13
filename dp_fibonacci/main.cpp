#include <iostream>
#include <cstdio>

#define MAX 50

using namespace std;

long long d[MAX] = { 1,1,0, };

long long fibonacci(int n)
{
	if (n < 2)
		return 1;

	if (d[n] > 0)
		return d[n];

	d[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return d[n];
}

int main(void)
{
	for (int i = 0; i < MAX; i++)
		printf("fibo[%2d] = %10lld\n", i, fibonacci(i));

	return 0;
}