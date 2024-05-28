#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
////ʵ��һ�²������
//// ����������ڵ�ṹ
//typedef struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//// ������нڵ�ṹ
//typedef struct QueueNode {
//    TreeNode* treeNode;
//    struct QueueNode* next;
//} QueueNode;
//
//// ������нṹ
//typedef struct Queue {
//    QueueNode* front;
//    QueueNode* rear;
//} Queue;
//
//// ����һ���µĶ��нڵ�
//QueueNode* newQueueNode(TreeNode* treeNode) {
//    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
//    temp->treeNode = treeNode;
//    temp->next = NULL;
//    return temp;
//}
//
//// ����һ���µĶ���
//Queue* createQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue));
//    q->front = q->rear = NULL;
//    return q;
//}
//
//// ��Ԫ�����
//void enQueue(Queue* q, TreeNode* treeNode) {
//    QueueNode* temp = newQueueNode(treeNode);
//    if (q->rear == NULL) {
//        q->front = q->rear = temp;
//        return;
//    }
//    q->rear->next = temp;
//    q->rear = temp;
//}
//
//// ��Ԫ�س���
//TreeNode* deQueue(Queue* q) {
//    if (q->front == NULL)
//        return NULL;
//    QueueNode* temp = q->front;
//    TreeNode* treeNode = temp->treeNode;
//    q->front = q->front->next;
//    if (q->front == NULL)
//        q->rear = NULL;
//    free(temp);
//    return treeNode;
//}
//
//// ��������������ĺ���
//void levelOrderTraversal(TreeNode* root) {
//    if (root == NULL)
//        return;
//    Queue* q = createQueue();
//    enQueue(q, root);
//    while (q->front != NULL) {
//        TreeNode* current = deQueue(q);
//        printf("%d ", current->val); // ���ʵ�ǰ�ڵ�
//        if (current->left != NULL)
//            enQueue(q, current->left); // ���ӽڵ����
//        if (current->right != NULL)
//            enQueue(q, current->right); // ���ӽڵ����
//    }
//    free(q);
//}
//
//// ��������������һ���µĶ������ڵ�
//TreeNode* newTreeNode(int val) {
//    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//    node->val = val;
//    node->left = node->right = NULL;
//    return node;
//}
//
//int main() {
//    // ����һ�ü򵥵Ķ�����
//    TreeNode* root = newTreeNode(1);
//    root->left = newTreeNode(2);
//    root->right = newTreeNode(3);
//    root->left->left = newTreeNode(4);
//    root->left->right = newTreeNode(5);
//
//    // ִ�в������
//    printf("Level Order Traversal of Binary Tree: ");
//    levelOrderTraversal(root);
//    printf("\n");
//
//    // ������Դ
//    free(root->left->left);
//    free(root->left->right);
//    free(root->left);
//    free(root->right);
//    free(root);
//    return 0;
//}