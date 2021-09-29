/*
����������
�����1��Ϊ��������m������n������Ԫ�ظ���t�� ��������˳����������t�У�ÿ��3�������ֱ��ʾ����Ԫ�ص��бꡢ�б��ֵ��

3 4 3
0 1 -5
1 0 1
2 2 2
��β�޿���
���������
���ת�ú����Ԫ��˳�������ÿ���������Ԫ�ص��бꡢ�б��ֵ���бꡢ�б��ֵ֮���ÿո�ָ�����t�С�

0 1 1
1 0 -5
2 2 2
*/

#include <stdio.h>
#include <stdlib.h>
#define M 100

struct node {
    int i, j, v;
};

struct tripletable
{
    struct node S[M];
    int m, n, t;
};

struct tripletable* create()
{
    int i;
    struct tripletable* head = (struct tripletable*)malloc(sizeof(struct tripletable));
    scanf("%d%d%d", &(head->m), &(head->n), &(head->t));
    for (i = 0; i < head->t; i++)
        scanf("%d%d%d", &(head->S[i].i), &(head->S[i].j), &(head->S[i].v));
    return head;
}

void print(struct tripletable* head)
{
    int i;
    for (i = 0; i < head->t; i++)
        printf("%d %d %d\n", (head->S[i].i), (head->S[i].j), (head->S[i].v));
}

struct tripletable* trans(struct tripletable* t1);
int main()
{
    struct tripletable* head, * t2;
    head = create();
    t2 = trans(head);
    print(t2);
    return 0;
}


/*

*/
/* ����������д�� */
struct tripletable* trans(struct tripletable* t1) {
    struct tripletable* transMatrix = (struct tripletable*)malloc(sizeof(struct tripletable));
    transMatrix->t = t1->t;
    transMatrix->m = t1->n;
    transMatrix->n = t1->m;

    int num[100], copt[100];
    int col, p;
    copt[0] = 0;
    for (int i = 0; i < t1->n; i++)num[i] = 0;
    for (int i = 0; i < t1->t; i++) {
        num[t1->S[i].j]++;
    }
    for (int i = 1; i < t1->n; i++) {
        copt[i] = copt[i - 1] + num[i - 1];
    }
    for (int i = 0; i < t1->t; i++) {
        col = t1->S[i].j;
        p = copt[col];
        transMatrix->S[p].i = t1->S[i].j;
        transMatrix->S[p].j = t1->S[i].i;
        transMatrix->S[p].v = t1->S[i].v;
        copt[col]++;
    }
    return transMatrix;
}