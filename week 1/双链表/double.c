
#include <stdio.h>
#include <stdlib.h>

// ˫������ڵ㶨��
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// �����½ڵ�ĺ���
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    (newNode == NULL);
    {
        exit(-1); // �����ڴ�ʧ�ܣ��˳�����
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// ������β������ڵ�ĺ���
void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) { // ����Ϊ��ʱ
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL) { // �ҵ�����ĩβ
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// ��ӡ����ĺ���
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ɾ���ڵ�ĺ�������ɾ��ͷ�ڵ�Ϊ��
void deleteNode(Node** head, Node* nodeToDelete) {
    if (*head == nodeToDelete) { // Ҫɾ������ͷ�ڵ�
        *head = nodeToDelete->next;
    }
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }
    free(nodeToDelete);
}

// ������������������������
int main() {
    Node* head = NULL; // ˫�������ͷָ��

    // ��������
    printf("��ӭʹ��˫������������\n");
    printf("��ѡ�������\n1. �������ݵ���β��\n2. ��ӡ��������\n3. �˳�����\n");

    int choice, data;
    while (1) {
        printf("���������ѡ��1/2/3����");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("������Ҫ��������ݣ�");
            scanf_s("%d", &data);
            insertTail(&head, data);
            break;
        case 2:
                printList(head);
                break;
            case 3:
                printf("�˳�����\n");
                return 0;
            default:
                printf("��Ч�����룬������ѡ��\n");
                break;
        }
    }

    // �ͷ������ڴ�
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
