//如果可以使用额外的空间，那么层次遍历就可以解决
//可以根据完全二叉树来入手
#include<cstdlib>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//方法1，双指针，记录两层依次改变。
class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        TreeLinkNode *p=root, *n=NULL;
        while(p!=NULL){
            if(n==NULL){
                n=p->left;
            }
            if(p->left!=NULL){
                p->left->next=p->right;
            }
            else break;
            if(p->next!=NULL){
                p->right->next=p->next->left;
                p=p->next;
            }
            else {
                p=n;
                n=NULL;
            }
        }
    }
};

//方法2
class Solution {
public:
    void connect(TreeLinkNode *root) {
        auto head=root;
        while(head!=NULL){
            auto temp=head;
            while(head!=NULL){
                if(head->left){
                    head->left->next=head->right;
                }
                if(head->right){
                    if(head->next){
                        head->right->next=head->next->left;
                    }
                }
                head=head->next;
            }
            head=temp->left;
        }
    }
};