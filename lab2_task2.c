#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void quicksort(int *, int); // ���������� �������
int check(int a); // ������� ��� �������� �������� ��������

int main() {
	int proverka = 0;
	int N, *MyMassive;
	while (!proverka) // ���� ���������� ��������� �������
	{
		printf("Enter the number of elements in the array: ");
		scanf("%d", &N);
		proverka = check(N);
	}
	MyMassive = (int*)malloc(N*sizeof(int));
	printf("Enter array elements: \n"); // ���� ��������� �������
	for (int i = 0; i < N; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &MyMassive[i]);
	}
	quicksort(MyMassive, N); // ���������� �������
	int min = MyMassive[0];
	// ����������� ������������� � ������������ �������� ���
	int max = MyMassive[N - 1];
	// �� ����������� ������������� � ���������� ��������
	int sum = 0;
	for (int i = 0; i < N; i++) // ������� ��������� ����� ��������� �������
	{
		sum += MyMassive[i];
	}
	int Repetition;
	printf("Enter the number of repetitions: ");
	scanf_s("%d", &Repetition); // ���� ���������� ��������
	if (Repetition == 0)
		printf("sum = %d", sum);
	else {
		int i = 1;
		do { // ���������� �������� � ���������� ��������
			sum = 5 * min - sum;
			if (i == 1)
				min = min - max;
			i++;
		}
		while (i <= Repetition);

		printf("sum = %d", sum);
	}
	free(MyMassive); // ������������� ������
	return 0;
}

void quicksort(int *arr, int size) // ���������� �������
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int check(int a) // �������� �� ����
{
	if (a < 0)
		return 0;
	else
		return 1;
}