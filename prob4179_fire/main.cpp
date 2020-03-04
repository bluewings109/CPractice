/*
https://www.acmicpc.net/problem/4179
�����̴� �̷ο��� ���� �Ѵ�. �����̸� �̷ο��� Ż���ϵ��� ��������!
�̷ο����� �������� ��ġ�� ���� ���� ��ġ�� �����ؼ� �����̰� �ҿ� Ÿ������ Ż���� �� �ִ����� ����, �׸��� �󸶳� ���� Ż���� �� �ִ����� �����ؾ��Ѵ�.
�����̿� ���� �� �и��� ��ĭ�� ����Ǵ� ��������(�񽺵��ϰ� �̵����� �ʴ´�)  �̵��Ѵ�.
���� �� �������� �� �������� Ȯ��ȴ�.
�����̴� �̷��� �����ڸ��� ���� �������� Ż���� �� �ִ�.
�����̿� ���� ���� �ִ� ������ ������� ���Ѵ�.

�Է�
�Է��� ù° �ٿ��� �������� ���е� �� ���� R�� C�� �־�����. ��, 1 �� R, C �� 1000 �̴�. R�� �̷� ���� ����, C�� ���� �����̴�.
���� �Է����� R�ٵ��� ������ �̷� ���� �־�����.
 ������ ���ڵ��� ������ ���Ѵ�.
#: ��
.: ������ �� �ִ� ����
J: �������� �̷ο����� �ʱ���ġ (������ �� �ִ� ����)
F: ���̳� ����
J�� �Է¿��� �ϳ��� �־�����.

���
�����̰� ���� �����ϱ� ���� �̷θ� Ż�� �� �� ���°�� IMPOSSIBLE �� ����Ѵ�.
�����̰� �̷θ� Ż���� �� �ִ� ��쿡�� ���� ���� Ż��ð��� ����Ѵ�.
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