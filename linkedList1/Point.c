#include <stdio.h>
#include "Point.h"

// Point ������ xpos, ypos �� ����
void SetPointPos(Point * ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

// Point ������ xpos, ypos ���� ���
void ShowPositionPos(Point * ppos) {
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}

// �� Point ������ ��
int PointComp(Point * pos1, Point * pos2) {
	if(pos1->xpos != pos2->xpos && pos1->ypos != pos2->ypos) {
		return -1;
	} else if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos) {
		return 0;
	} else if(pos1->xpos == pos2->xpos && pos1->ypos != pos2->ypos) {
		return 1;
	} else {
		return 2;
	}
}