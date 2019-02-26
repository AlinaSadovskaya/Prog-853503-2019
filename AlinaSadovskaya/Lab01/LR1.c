#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

long fact(int, int);

int main(void)
{
	SetConsoleCP(1251);                           //����������� ����� ��� ������������� �������� ������
	SetConsoleOutputCP(1251);
	long double sum = 0, comp;                    //���������� ���������� ����� � ������������ (long double, ��� ��� ���������� ������� ������������ ��������)
	int n;
	printf_s("������� ���������� ���������: ");   //����� ������ ���� ������ 30, ����� ���������� ����� �� ������� ���������� ��������
	scanf_s("%d", &n);                            //���� ������������ �����
	for (int k = 1; k <= n; k++) {
		comp = 1;                                 //��������� ������������ �� ������ �������� 
		for (int t = 1; t <= k; t++) {
			comp *= fact(k, t);
		}
		sum += comp;                              //��������� ����� ������������ 
	}
	printf_s("sum = %1.0lf\n", sum);              //����� ����������
	system("pause");
	return 0;
}

long fact(int i, int j) {                            //������� ��� ���������� ���������, ������� � ������ ���.��������������
	int temp = i + 1; long factorial = i + 1;    //�������� � ���� (i+1)*(i+2)*...*(i+j)
	while (temp < i + j) {
		temp++;
		factorial *= temp;
	}
	return factorial;
}