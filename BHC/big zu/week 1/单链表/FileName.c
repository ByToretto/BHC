
#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义单链表ADT
typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

// 初始化单链表
LinkedList* initLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// 在链表尾部插入节点
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

// 打印链表内容
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数，创建启动界面并运行程序
int main() {
    LinkedList* list = initLinkedList(); // 初始化单链表
    printf("请输入要插入的节点数据（输入0结束）：\n");
    int data;
    while (scanf_s("%d", &data) != 0) { // 循环接收用户输入的数据，直到输入0为止
        if (data != 0) { // 如果输入的数据不为0，则在链表尾部插入节点并打印链表内容
            insertNode(list, data);
            printList(list);
        }
        else { // 如果输入了0，则退出循环并结束程序
            break;
        }
    }
    return 0;
}

