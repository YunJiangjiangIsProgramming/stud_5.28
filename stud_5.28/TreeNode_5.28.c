#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};

int* findPeaks(int* mountain, int mountainSize, int* returnSize)//oj第一题
{
    int* prev = mountain;
    int* cur = mountain + 1;
    int* next = mountain + 2;
    int* peaks = (int*)malloc(sizeof(int) * mountainSize); // 假设不会有超过mountainSize个峰值
    int count = 0;

    while (next < mountain + mountainSize)
    {
        if ((*cur) > (*prev) && (*cur) > (*next))
        {
            peaks[count] = cur - mountain; // 存储峰值的索引，而不是地址
            count++;
        }
        prev++;
        cur++;
        next++;
    }

    *returnSize = count; // 更新returnSize的值
    return peaks; // 返回峰值数组的地址
}

double myPow(double x, int n)//oj这个算法的时间复杂度在o（log2 n）
{
    if (n ==0||x==1)
    {
        return 1.0;
    }
    if (n < 0)

    {
        return 1 / (x * myPow(x, -(n + 1)));
    }
    if(n%2==0)
    {
        return myPow(x * x, n / 2);
    }
    else
    {
        return x * myPow(x * x, (n - 1) / 2);
    }
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) //前序遍历判断是不是相同的树 oj3
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p != NULL && q == NULL)
    {
        return false;
    }
    if (q != NULL && p == NULL)
    {
        return false;
    }
    if (q->val != p->val)
    {
        return false;
    }//如果一个条件不能判断他为真的时候，可以写他的反面有一个为假就是假了
    return isSameTree(p->left, q->left)
        && isSameTree(q->right, p->right);
}

int maxDepth(struct TreeNode* root)//oj4求树的最大深度 利用leftDepth保存深度可以减少冗余计算 就是找最深的子树深度+1
{
    if (root == 0)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)//判断是否是镜像树oj5
//{
//    // 首先检查两个节点是否都为NULL
//    if (p == NULL && q == NULL) 
//    {
//        return true;
//    }
//    // 如果一个节点为NULL，另一个不为NULL，返回false
//    if (p == NULL || q == NULL) 
//    {
//        return false;
//    }
//    // 检查两个节点的值是否相等
//    if (p->val != q->val) 
//    {
//        return false;
//    }
//    // 递归检查左子树和右子树是否对称
//    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
//}

bool isSymmetric(struct TreeNode* root) //oj6
{
    // 如果根节点为NULL，返回true
    if (root == NULL) 
    {
        return true;
    }
    // 检查左右子树是否对称
    return isSameTree(root->left, root->right);
}

struct TreeNode* invertTree(struct TreeNode* root)//反转这个树 oj7
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}

//oj7 前序遍历

int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _preorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    arry[(*pi)] = root->val;
    (*pi)++;//拿到外面的i的值 要让i的改变在同一个i上面
    //所以要传i的地址不然每一个局部变量的i出了局部范围就销毁了
    _preorderTraversal(root->left, arry, pi);
    _preorderTraversal(root->right, arry, pi);

}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int Size = TreeSize(root);
    int* arry = (int*)malloc(sizeof(int) * Size);
    int i = 0;
    _preorderTraversal(root, arry, &i);
    *returnSize = Size;
    return arry;
}

//oj8后序遍历
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}

void  _postorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    _postorderTraversal(root->left, arry, pi);
    _postorderTraversal(root->right, arry, pi);
    arry[(*pi)] = root->val;
    (*pi)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int Size = TreeSize(root);
    int* arry = (int*)malloc(sizeof(int) * Size);
    int i = 0;
    _postorderTraversal(root, arry, &i);
    *returnSize = Size;
    return arry;

}

//oj9题的第一种解法用前序遍历写的 有大量冗余的计算
//int TreeDepth(struct TreeNode* root)//求树的深度
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int leftDepth = TreeDepth(root->left);
//    int rightDepth = TreeDepth(root->right);
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//
//bool isBalanced(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//    int gap = TreeDepth(root->left) - TreeDepth(root->right);
//    if (abs(gap) > 1)
//    {
//        return false;
//    }
//    return isBalanced(root->left) && isBalanced(root->right);
//}

//再提供一种时间复杂度更少的解法

bool _isBalanced(struct TreeNode* root, int* pdepth)
{
    if (root == NULL)
    {
        *pdepth = 0;
        return true;//返回两个值一个用指针拿一个用来判断程序是不是还继续的true or false
    }
    else
    {
        int leftDepth = 0;
        if (_isBalanced(root->left, &leftDepth) == false)
        {
            return false;
        }//判断左树满不满足条件
        int rightDepth = 0;
        if (_isBalanced(root->right, &rightDepth) == false)
        {
            return false;
        }//判断右树满不满足条件
        if (abs(leftDepth - rightDepth) > 1)
        {
            return false;
        }
        *pdepth = (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
        return true;
    }

}

bool isBalanced(struct TreeNode* root)
{
    int depth = 0;
    return _isBalanced(root, &depth);
}
int main()
{
    


    return 0;
}
