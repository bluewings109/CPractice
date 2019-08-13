#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{

	int v[10];
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[4] = 1;
	v[5] = 1;
	v[6] = 1;
	v[7] = 1;
	v[8] = 1;
	v[9] = 1;

	printf("%d %d\n", &(v[0]), &(v[4]));
	printf("%d %d\n", equal_range(&v[0], &v[9], 0).first, equal_range(&v[0], &v[9], 0).second);
	printf("%d\n", equal_range(&v[0], &v[0] + 10, 0).second - equal_range(&v[0], &v[0] + 10, 0).first);
	
	return 0;
}