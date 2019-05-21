#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* create(char*); // ������� ��� ����� ������������ ������
char* encode(char* mass, char * out); // ������� �������� RLE

int main() {
	char *string = NULL; // ��������� ������ ��� �������� ������
	string = (char*)malloc(sizeof(char) * 1);
	printf("Enter string...\n");
	create(string); // ���� ������
	char * encode_out = NULL; // ��������� ������ ��� �������� ������
	encode_out = (char*)malloc(sizeof(char) * strlen(string));
	encode(string, encode_out); // ������� RLE
	printf("%s  \n", encode_out); // ����� ������
	free(encode_out); // ������������� ������
	free(string);
	system("PAUSE");
	return 0;
}

char* create(char* string) {
	int size = 1;
	int i = 0;
	while (1) {
		*(string + i) = getchar();
		if (*(string + i) == '\n' || *(string + i) == ' ') {
			*(string + i) = '\0';
			break;
		}
		size++;
		string = (char*)realloc(string, sizeof(char) * size);
		// �������� ���������� ������ ��� �������
		i++;
	}
	return string;
}

char* encode(char* mass, char * out) // �������� RLE
{
	int kolvo = 1;
	int sizeout = 0;
	for (int i = 0; i < strlen(mass); i++) {
		if (i != strlen(mass) - 1) {
			if (mass[i] != mass[i + 1]) {
				if (kolvo <= 2) {
					while (kolvo) {
						out[sizeout] = mass[i];
						sizeout++;
						kolvo--;
					}
				}
				else {
					out[sizeout] = kolvo + '0';
					sizeout++;
					out[sizeout] = mass[i];
					sizeout++;
				}
				kolvo = 1;

			}
			else {
				kolvo++;
			}
		}
		else {
			if (kolvo <= 2) {
				while (kolvo) {
					out[sizeout] = mass[i];
					sizeout++;
					kolvo--;
				}
			}
			else {
				if (kolvo < 10) {
					out[sizeout] = kolvo + '0';
					sizeout++;
				}
				else {
					int size_kolva = 0;
					int temp = kolvo;
					while (size_kolva) {
						temp /= 10;
						size_kolva++;
					}
					char* argv = (char*)malloc(sizeof(char) * (size_kolva + 1));
					itoa(kolvo, argv, 10);
					for (int i = 0; i < strlen(argv); i++) {
						out[sizeout] = argv[i];
						sizeout++;
						out[sizeout] = mass[i];
						sizeout++;
					}
				}
				out[sizeout] = mass[i];
				sizeout++;
			}
			out[sizeout] = '\0';
		}
	}
	return out;
}