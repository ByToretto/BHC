
#include <stdio.h>
#include <stdlib.h>

// 双向链表节点定义
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    (newNode == NULL);
    {
        exit(-1); // 分配内存失败，退出程序
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 在链表尾部插入节点的函数
void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) { // 链表为空时
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL) { // 找到链表末尾
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// 打印链表的函数
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 删除节点的函数，以删除头节点为例
void deleteNode(Node** head, Node* nodeToDelete) {
    if (*head == nodeToDelete) { // 要删除的是头节点
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

// 主函数，启动界面和链表操作
int main() {
    Node* head = NULL; // 双向链表的头指针

    // 启动界面
    printf("欢迎使用双向链表管理程序！\n");
    printf("请选择操作：\n1. 插入数据到链尾部\n2. 打印链表数据\n3. 退出程序\n");

    int choice, data;
    while (1) {
        printf("请输入你的选择（1/2/3）：");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("请输入要插入的数据：");
            scanf_s("%d", &data);
            insertTail(&head, data);
            break;
        case 2:
                printList(head);
                break;
            case 3:
                printf("退出程序。\n");
                return 0;
            default:
                printf("无效的输入，请重新选择。\n");
                break;
        }
    }

    // 释放链表内存
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
