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

int* findPeaks(int* mountain, int mountainSize, int* returnSize)//oj��һ��
{
    int* prev = mountain;
    int* cur = mountain + 1;
    int* next = mountain + 2;
    int* peaks = (int*)malloc(sizeof(int) * mountainSize); // ���費���г���mountainSize����ֵ
    int count = 0;

    while (next < mountain + mountainSize)
    {
        if ((*cur) > (*prev) && (*cur) > (*next))
        {
            peaks[count] = cur - mountain; // �洢��ֵ�������������ǵ�ַ
            count++;
        }
        prev++;
        cur++;
        next++;
    }

    *returnSize = count; // ����returnSize��ֵ
    return peaks; // ���ط�ֵ����ĵ�ַ
}

double myPow(double x, int n)//oj����㷨��ʱ�临�Ӷ���o��log2 n��
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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) //ǰ������ж��ǲ�����ͬ���� oj3
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
    }//���һ�����������ж���Ϊ���ʱ�򣬿���д���ķ�����һ��Ϊ�پ��Ǽ���
    return isSameTree(p->left, q->left)
        && isSameTree(q->right, p->right);
}

int maxDepth(struct TreeNode* root)//oj4������������ ����leftDepth������ȿ��Լ���������� ������������������+1
{
    if (root == 0)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)//�ж��Ƿ��Ǿ�����oj5
//{
//    // ���ȼ�������ڵ��Ƿ�ΪNULL
//    if (p == NULL && q == NULL) 
//    {
//        return true;
//    }
//    // ���һ���ڵ�ΪNULL����һ����ΪNULL������false
//    if (p == NULL || q == NULL) 
//    {
//        return false;
//    }
//    // ��������ڵ��ֵ�Ƿ����
//    if (p->val != q->val) 
//    {
//        return false;
//    }
//    // �ݹ������������������Ƿ�Գ�
//    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
//}

bool isSymmetric(struct TreeNode* root) //oj6
{
    // ������ڵ�ΪNULL������true
    if (root == NULL) 
    {
        return true;
    }
    // ������������Ƿ�Գ�
    return isSameTree(root->left, root->right);
}

struct TreeNode* invertTree(struct TreeNode* root)//��ת����� oj7
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

//oj7 ǰ�����

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
    (*pi)++;//�õ������i��ֵ Ҫ��i�ĸı���ͬһ��i����
    //����Ҫ��i�ĵ�ַ��Ȼÿһ���ֲ�������i���˾ֲ���Χ��������
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

//oj8�������
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

//oj9��ĵ�һ�ֽⷨ��ǰ�����д�� �д�������ļ���
//int TreeDepth(struct TreeNode* root)//���������
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

//���ṩһ��ʱ�临�Ӷȸ��ٵĽⷨ

bool _isBalanced(struct TreeNode* root, int* pdepth)
{
    if (root == NULL)
    {
        *pdepth = 0;
        return true;//��������ֵһ����ָ����һ�������жϳ����ǲ��ǻ�������true or false
    }
    else
    {
        int leftDepth = 0;
        if (_isBalanced(root->left, &leftDepth) == false)
        {
            return false;
        }//�ж�����������������
        int rightDepth = 0;
        if (_isBalanced(root->right, &rightDepth) == false)
        {
            return false;
        }//�ж�����������������
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
