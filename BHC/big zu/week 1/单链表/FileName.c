
#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ��
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ���嵥����ADT
typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

// ��ʼ��������
LinkedList* initLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// ������β������ڵ�
void insertNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// ��ӡ��������
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// �������������������沢���г���
int main() {
    LinkedList* list = initLinkedList(); // ��ʼ��������
    printf("������Ҫ����Ľڵ����ݣ�����0��������\n");
    int data;
    while (scanf_s("%d", &data) != 0) { // ѭ�������û���������ݣ�ֱ������0Ϊֹ
        if (data != 0) { // �����������ݲ�Ϊ0����������β������ڵ㲢��ӡ��������
            insertNode(list, data);
            printList(list);
        }
        else { // ���������0�����˳�ѭ������������
            break;
        }
    }
    return 0;
}

