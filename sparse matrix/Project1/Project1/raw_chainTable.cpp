#include<iostream>
#include<stdio.h>
#include<iomanip>
#define DataType int
#define MAXSIZE 100


typedef struct Node{
	int i,j;
	DataType value;
	struct Node *next;
}tripleNode; 

typedef struct{
	tripleNode *node [MAXSIZE+1];
	//m is raws, n is columns  
	int sum, m,n;
}Matrix;

Matrix *createMatrix(){
	Matrix* chain = (Matrix*)malloc(sizeof(Matrix));
	tripleNode* node = new tripleNode;
	printf("请输入矩阵的行数、列数:\n");
	//scanf_s("%d%d", &(chain->m), &(chain->n));
	std::cin >> chain->m >> chain->n;
	for (int i = 1; i <= chain->m; i++) { 
		chain->node[i] = NULL;
	} 

	tripleNode* pin[MAXSIZE+1];
	for (int i = 1; i <= chain->m; i++)
		pin[i] = NULL;
	
	 /*printf("请输入矩阵元素的个数:\n");
	 scanf("%d", &(head->sum));*/
	
	 printf("请输入元素所在行、列以及值(输入0结束):\n");
	 std::cin >> node->i >> node->j >> node->value;
	 while (node->i != 0) {
		 
		 if (node->i > chain->m || node->j > chain->n) {
			 printf("矩阵元素输入错误！\n");
			 return NULL;
		 }
			 
		 if (chain->node[node->i] == NULL) {
			 chain->node[node->i] = node;
			 //chain->node[node.i]->next = NULL;
		 }
		 else {
			 pin[node->i]->next = node;
			 //pin[node.i]->next->next = NULL;
		 }
		 pin[node->i] = node;
		 printf("请输入元素所在行、列以及值(输入0结束):\n");
		 node = new tripleNode;
		 std::cin >> node->i >> node->j >> node->value;
	 }
	 for (int i = 1; i <= chain->m; i++) {
		 if(pin[i] != NULL)
			pin[i]->next = NULL;
	 }
	return chain;
}

void print(Matrix *head){
	tripleNode* node[MAXSIZE + 1];

	for (int i = 1; i <= head->m; i++) {
		node[i] = new tripleNode;
		node[i]->j = 0;
		node[i]->next = head->node[i];
	}
	for (int raw = 1; raw <= head->m; raw++) {
		//for (int col = 1; col <= head->n; col++) {
		//	if()
		//}
		while (node[raw]) {
			if (!node[raw]->next) {
				for (int i = node[raw]->j; i < head->n; i++)
					std::cout << std::left << std::setw(3) << 0;
				break;
			}
			else {
				for (int i = node[raw]->j; i < node[raw]->next->j - 1; i++)
					std::cout << std::left << std::setw(3) << 0;
				std::cout << std::left << std::setw(3) << node[raw]->next->value;
			}
					
			node[raw] = node[raw]->next;
		}	
		std::cout << std::endl;
	}
}

int main(){
	Matrix *head;
	head = createMatrix();
	print(head);
	return 0;
}
