#include <cstdio>
using namespace std;

int arr[9] = { 0, };
bool visited[9] = { 0, };
int N, M;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 1; i <= M; ++i) {
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (visited[i] == false) {
			arr[cnt + 1] = i;
			visited[i] = true;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}

}
int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		arr[1] = i;
		visited[i] = true;
		dfs(1);
		visited[i] = false;
	}

	fclose(fp);

	return 0;
}