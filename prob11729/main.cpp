#include <cstdio>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
void hanoi(int num, int from, int by, int to) {
	if (num == 1) {
//		printf("%d %d\n", from, to);
		v.push_back(make_pair(from, to));
		return;
	}
	hanoi(num - 1, from, to, by);
	hanoi(1, from, by, to);
	hanoi(num - 1, by, from, to);
}
int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int N;



	scanf("%d", &N);
	
	hanoi(N, 1, 2, 3);

	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v.at(i).first, v.at(i).second);
	}



	fclose(fp);
	return 0;

}