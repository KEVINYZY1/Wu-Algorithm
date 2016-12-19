#include<cstdlib>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//不是完全二叉树，难度加大
class Solution {
public:
    void connect(TreeLinkNode *root) {
        auto head=root;
        while(head!=NULL){
            TreeLinkNode *dump=new TreeLinkNode(-1);
            auto temp=dump;
            while(head!=NULL){
                if(head->left){
                    dump->next=head->left;
                    dump=dump->next;
                }
                if(head->right){
                    dump->next=head->right;
                    dump=dump->next;
                }
                head=head->next;
            }
            head=temp->next;
            delete temp;
        }
    }
};