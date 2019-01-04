#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) {
	if(num == 1) {
		printf("Move Disk %d from %c to %c\n", num, from, to);
		return;
	} else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("Move Disk %d from %c to %c\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}
int main(void) {
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}