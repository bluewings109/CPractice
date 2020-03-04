#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	vector<pair<int, int>> v;
	int arr[51] = { 0, };
	for (int i = 0; i < N; ++i) {
		int x,  y;
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
		arr[i] = 1;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j)
				continue;
			if (v.at(i).first < v.at(j).first && v.at(i).second < v.at(j).second) {
				++(arr[i]);
			}
		}
	}

	for (int a : arr) {
		if (a == 0)
			break;
		printf("%d ", a);
	}
	fclose(fp);
	return 0;
}