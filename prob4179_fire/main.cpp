/*
https://www.acmicpc.net/problem/4179
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다.
불은 각 지점에서 네 방향으로 확산된다.
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
 각각의 문자들은 다음을 뜻한다.
#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는경우 IMPOSSIBLE 을 출력한다.
지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.
*/


#include <cstdio>
#include <queue>

#define INF 3000

using namespace std;

int main(void){
	FILE * fp = freopen("input.txt", "r", stdin);

	int R, C;
	char map[1001][1001] = { 0, };

	int jihun_row = 0;
	int jihun_col = 0;
	
	int fire_row = 0;
	int fire_col = 0;

	int Dj[1001][1001] = { 0, };
	int Df[1001][1001] = { 0, };

	priority_queue< int, vector<int>, less<int> > pq;

	scanf("%d %d", &R, &C);

	char ch;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			scanf(" %c", &ch);
			map[i][j] = ch;

			Df[i][j] = Dj[i][j] = INF;
			
			if (ch == 'J') {
				jihun_row = i;
				jihun_col = j;
				
			}
			else if (ch == 'F') {
				fire_row = i;
				fire_col = j;
				
			}
		}
	}
	Df[fire_row][fire_col] = 0;
	pq.push(fire);

	while (pq.empty() == false) {
		int 
	}


	Dj[jihun_row][jihun_col] = 0;
	fclose(fp);
}