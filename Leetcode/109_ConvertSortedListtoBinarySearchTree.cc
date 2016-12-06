#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//将排好序的链表转换为平衡搜索树
//难点在于链表的中点找起来比较麻烦

//方法1，用哈希将链表映射起来，转换成类似于108题
class Solution1 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int, int>m;
        if(head==NULL)
            return NULL;
        auto temp=head;
        int i=0;
        while(temp){
            m[i]=temp->val;
            temp=temp->next;
            i++;
        }
        return buildBST(m, 0, i);
    }
private:
    TreeNode* buildBST(unordered_map<int, int> &m, int start, int end){
        if(start>=end)
            return NULL;
        int mid=start+(end-start)/2;        
        TreeNode* root=new TreeNode(m[mid]);
        root->left=buildBST(m,start,mid);
        root->right=buildBST(m,mid+1,end);
        return root;
    }
};

//方法2，每次递归找链表中点，虽然找中点可以用双节点法找，但还是要O(NlgN)

//方法3，要达到O(N)复杂度的算法，就不能反复遍历来查找中间节点，而只能顺序边访问linked list边构建树。
//这里的关键是利用构建left subtree的递归，来找寻middle节点。即构建left subtree的时候需要返回两个值：left subtree的root节点，以及整个left subtree在linked list中的下一个节点
//即middle节点，也是整个left subtree的parent节点。
/*
TreeNode *sortedListToBST(ListNode *&head, int start, int end)

这个函数所做的是将*head为头的linked list构建成一个BST，然后返回BST的root，而同时，也将head移动到linked list中第end+1个节点。
因为*head既是输入参数，也是返回参数，所以这里用到了指针的引用*&head。注意不能错写成了&*head。理解*&的方法是从右向左读：首先是一个引用，然后是一个对指针的引用，最后是一个对ListNode指针的引用。
那么当left subtree构建完成后，head指向了mid，构建mid树节点。然后后移head到right subtree在linked list中的头节点。继续递归构建right subtree.
*/
class Solution3 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int listLen = 0;
        ListNode *cur = head;
        while(cur) {
            listLen++;
            cur = cur->next;
        }
        return sortedListToBST(head, 0, listLen-1);
    }
private:
    TreeNode* sortedListToBST(ListNode *&head, int start, int end) {//head会不断变化，因为传引用
        if(start>end) 
            return NULL;
        int mid = start + (end-start)/2;
        TreeNode *leftChild = sortedListToBST(head, start, mid-1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *rightChild = sortedListToBST(head, mid+1, end);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};