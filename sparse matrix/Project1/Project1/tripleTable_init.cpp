#include<iostream>
#include<stdio.h>
#include<iomanip>
#define DataType int
int main() {
	typedef struct{
		int x, y;
		DataType value;
	}triple;

	typedef struct{
		triple data[100];
		int num;
		int x, y;
	}Matrix;

	int x, y;
	Matrix matrix;
	DataType value;
	printf("���������ĳ��ȼ���ȣ�\n");
	std::cin >> x >> y;
	matrix.x = x;
	matrix.y = y;
	printf("������Ԫ��������, ������, ֵ(����0 0 0����):\n");
	std::cin >> y >> x >> value;
	matrix.num = 0;
	int* p = &matrix.num;
	while (y != 0) {
		if (x > matrix.x || y > matrix.y) {
			printf("������������\n");
			return 0;
		}
		matrix.data[*p].y = y;
		matrix.data[*p].x = x;
		matrix.data[*p].value = value;
		matrix.num++;
		printf("������Ԫ��������, ������, ֵ(����0 0 0����):\n");
		std::cin >> y >> x >> value;
	}

	//for (int a = 0; a < matrix.num; a++) 
	//	printf("%d\n", matrix.data[a].value);

	printf("��ʼ���������\n");
	
	int found = 0;
	for (int i = 1; i <= matrix.y; i++) {
		for (int j = 1; j <= matrix.x; j++) {
			for (int a = 0; a < matrix.num && found == 0; a++) {
				if (i == matrix.data[a].y && j == matrix.data[a].x) {
					//printf("%d", matrix.data[a].value);
					std::cout << std::setw(3) << std::left << matrix.data[a].value;
					found = 1;
					break;
				}	
			}
			if (found == 0)
				std::cout << std::setw(3) << std::left << 0;
				//printf("0");
			else found = 0;
		}
		printf("\n");
	}
	return 0;
}