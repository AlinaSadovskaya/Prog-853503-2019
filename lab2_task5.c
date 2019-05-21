#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int kolvo(long int x, long int z1, long int z2, long int x1, long int y1,
	long int x2, long int y2)
{ // ������� ����� ����������� (��������� �� ������������� ��������� - max/min)������ ������
	long int min, max, point_number;
	// � ����������� �������� r � ������� � ����� (x3,y3)
	if ((x < x1) || (x > x2) || (z1 > y2) || (z2 < y1))
		point_number = 0;
	else {
		min = y1;
		if (z1 > y1) {
			min = z1;
		}
		max = y2;
		if (z2 < y2) {
			max = z2;
		}
		point_number = max - min + 1;
	}
	return point_number;
}

int main() {
	long int x1, y1, x2, y2, x3, y3, r; // ���� ������
	printf("x1 = ");
	scanf("%ld", &x1);
	printf("\ny1 = ");
	scanf("%ld", &y1);
	printf("\nx2 = ");
	scanf("%ld", &x2);
	printf("\ny2 = ");
	scanf("%ld", &y2);
	printf("\nx3 = ");
	scanf("%ld", &x3);
	printf("\ny3 = ");
	scanf("%ld", &y3);
	printf("\nr = ");
	scanf("%ld", &r);
	long int kolvo_tree = (x2 - x1 + 1) * (y2 - y1 + 1);
	// ���������� ����� ���������� �������� � ���� � ��������� ������������
	long int watered_trees = kolvo(x3, y3 - r, y3 + r, x1, y1, x2, y2);
	// ������� ����������� ���������� ����� �� ����������� ������ (���� ������������� �������)
	long int y = r;
	for (int x = 1; x != r;
	x++) // ������� ����� ���������� ����� �� ���� �������, ���� � ��� �� ��������� ���� �������� r
	{
		while (sqrt(x) + sqrt(y) > sqrt(r)) {
			y--;
			watered_trees += kolvo(x3 + x, y3 - y, y3 + y, x1, y1, x2, y2) +
				kolvo(x3 - x, y3 - y, y3 + y, x1, y1, x2, y2);
		}
	}
	long int not_watered_trees =
		kolvo_tree - (watered_trees + kolvo(x3 + r, y3, y3, x1, y1, x2, y2) +
		kolvo(x3 - r, y3, y3, x1, y1, x2, y2));
	// ������� ���������� ��������� ��������, ������� �� ����� ���������� �������� ���������� �������
	printf("\nResult = %ld", not_watered_trees);
	return 0;
}