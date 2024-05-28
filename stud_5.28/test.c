#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
////实现一下层序遍历
//// 定义二叉树节点结构
//typedef struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//// 定义队列节点结构
//typedef struct QueueNode {
//    TreeNode* treeNode;
//    struct QueueNode* next;
//} QueueNode;
//
//// 定义队列结构
//typedef struct Queue {
//    QueueNode* front;
//    QueueNode* rear;
//} Queue;
//
//// 创建一个新的队列节点
//QueueNode* newQueueNode(TreeNode* treeNode) {
//    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
//    temp->treeNode = treeNode;
//    temp->next = NULL;
//    return temp;
//}
//
//// 创建一个新的队列
//Queue* createQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue));
//    q->front = q->rear = NULL;
//    return q;
//}
//
//// 将元素入队
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
//// 将元素出队
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
//// 层序遍历二叉树的函数
//void levelOrderTraversal(TreeNode* root) {
//    if (root == NULL)
//        return;
//    Queue* q = createQueue();
//    enQueue(q, root);
//    while (q->front != NULL) {
//        TreeNode* current = deQueue(q);
//        printf("%d ", current->val); // 访问当前节点
//        if (current->left != NULL)
//            enQueue(q, current->left); // 左子节点入队
//        if (current->right != NULL)
//            enQueue(q, current->right); // 右子节点入队
//    }
//    free(q);
//}
//
//// 辅助函数，创建一个新的二叉树节点
//TreeNode* newTreeNode(int val) {
//    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//    node->val = val;
//    node->left = node->right = NULL;
//    return node;
//}
//
//int main() {
//    // 构建一棵简单的二叉树
//    TreeNode* root = newTreeNode(1);
//    root->left = newTreeNode(2);
//    root->right = newTreeNode(3);
//    root->left->left = newTreeNode(4);
//    root->left->right = newTreeNode(5);
//
//    // 执行层序遍历
//    printf("Level Order Traversal of Binary Tree: ");
//    levelOrderTraversal(root);
//    printf("\n");
//
//    // 清理资源
//    free(root->left->left);
//    free(root->left->right);
//    free(root->left);
//    free(root->right);
//    free(root);
//    return 0;
//}