#include <iostream>
#include <conio.h>
#include <limits.h>
using namespace std;

typedef struct {
	int x;
	int y;
	int number;
	double angle;
} point;

void merge(point *, int, int);

void mergeSort(point *points, int l, int r) {
	if (l >= r) {
		return;
	}
	mergeSort(points, l, (l + r) / 2);
	mergeSort(points, (l + r) / 2 + 1, r);
	merge(points, l, r);
}

void merge(point *points, int l, int r) {
	point *tmp = new point[r - l + 1];
	point *curA = points + l;
	int mid = (l + r) / 2 + 1;
	point *curB = points + mid;
	point *curTmp = tmp;
	while (curA < points + mid && curB < points + r + 1) {
		if (curA->angle <= curB->angle) {
			*curTmp = *curA;
			curTmp++;
			curA++;
		}
		else {
			*curTmp = *curB;
			curTmp++;
			curB++;
		}
	}
	if (curA == points + mid) {
		while (curB < points + r + 1) {
			*curTmp = *curB;
			curTmp++;
			curB++;
		}
	}
	else {
		while (curA < points + mid) {
			*curTmp = *curA;
			curTmp++;
			curA++;
		}
	}

	for (int i = l; i <= r; i++) {
		points[i] = tmp[i - l];
	}
}

void pointSwap(point *a, point *b) {
	point cur;
	cur.x = a->x;
	cur.y = a->y;
	cur.number = a->number;
	cur.angle = a->angle;

	a->x = b->x;
	a->y = b->y;
	a->number = b->number;
	a->angle = b->angle;

	b->x = cur.x;
	b->y = cur.y;
	b->number = cur.number;
	b->angle = cur.angle;
}


int main() {
	point *points = new point[10000];
	int N;
	int minX = INT_MAX, minY = INT_MAX, minI;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
		points[i].number = i;
		if (points[i].x == minX && minY > points[i].y || points[i].x < minX) {
			minX = points[i].x;
			minY = points[i].y;
			minI = i;
		}
	}
		for (int i = 0; i < N; i++) {
		if (i == minI) {
			points[i].angle = INT_MIN;
			continue;
		}
		if (minX == points[i].x) {
			points[i].angle = INT_MAX;
			continue;
		}
		points[i].angle = (points[i].y - minY) / (double)(points[i].x - minX);
	}
	mergeSort(points, 0, N - 1);
	cout << points[0].number + 1 << " " << points[N / 2].number + 1 << endl;
	// system("pause");
	return 0;
}
