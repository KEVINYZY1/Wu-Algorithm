#ifndef BINARYSEARCHTREE_H
#define BINARYSERCHTREE_H

#include<cstdlib>

//二分搜索树
struct TreeNode {
    int key;
    int val;
    TreeNode *left, *right;
    int num;//统计以该节点为根节点的的大小

    TreeNode(int key, int value = 0) {
        this->key = key;
        this->val = value;
        left = NULL;
        right = NULL;
        num = 1;
    }
};
class binarySearchTree {
    public:
        binarySearchTree() {
            root_ = NULL;
            size_ = 0;
        }
        
        TreeNode* insert(int key, int value) {
            auto root = root_;
            TreeNode *parent = NULL;
            while (root != NULL) {
                parent = root;
                if (root->val > key)
                    root = root->left;
                else if (root->val < key)
                    root = root->right;
                else {
                    root->val = value;
                    return root;//插入重复的键，等于修改val
                }
                parent->num++;//插入操作维护num变量
            }
            size_++;
            if (parent == NULL) {
                root_ = new TreeNode(key);
                return root_;
            } else if (parent->val > key) {
                parent->left = new TreeNode(key);
                return parent->left;
            } else {
                parent->right = new TreeNode(key);
                return parent->right;
            }
        }

        bool delete(int key) {
            if(!search(key))
                return false;
            size_--;
            auto root = root_;
            TreeNode *parent = NULL;
            while (root != NULL) {
                if(root->val>key)
                    root = root->left;
                else if (root->val < key)
                    root = root->right;
                else break;
                parent = root;
                parent->num--;//删除操作维护num变量
            }
            if (parent == NULL) {//删除的是根结点
                if (root->left == NULL && root->right == NULL) {
                    delete root;
                    root_ = NULL;
                } else if(root->left && root->right) {
                    auto pre = root;
                    auto preParent = root;
                    pre = root->left;
                    while (pre->right) {
                        preParent = pre;
                        preParent->num--;//删除操作维护num变量
                        pre = pre->right;
                    }
                    if (preParent != root)
                        preParent->right = NULL;
                    else preParent->left = NULL;
                    root_ = pre;
                    pre->right = root->right;
                    pre->left = root->left;
                    pre->num = pre->left->num + pre->right->num + 1;
                    delete root;
                } else {
                    if (root->left) {
                        root_ = root->left;
                        delete root;
                    } else {
                        root_ = root->right;
                        delete root;
                    }
                }
            } else {
                if(root->left==NULL && root->right == NULL) {
                    if(parent->left == root)
                        parent->left = NULL;
                    else parent->right = NULL;
                    delete root;
                } else if (root->left && root->right) {
                    auto pre=root;
                    auto preParent=root;
                    pre=root->left;
                    while (pre->right) {
                        preParent=pre;
                        preParent->num--;//删除操作维护num变量
                        pre=pre->right;
                    }
                    if (preParent != root)
                        preParent->right = NULL;
                    else preParent->left = NULL;
                    if (parent->left == root)
                        parent->left = pre;
                    else parent->right = pre;
                    pre->right = root->right;
                    pre->left = root->left;
                    pre->num = pre->left->num + pre->right->num + 1;
                    delete root;
                } else {
                    if (root->left) {
                        if(parent->left == root)
                            parent->left = root->left;
                        else parent->right = root->left;
                        delete root;
                    } else {
                        if(parent->left == root)
                            parent->left = root->right;
                        else parent->right = root->right;
                        delete root;
                    }
                }
            }
            return true;
        }

        bool search(int key) {
            auto node = root_;
            while (node != NULL) {
                if(key == node->val)
                    return true;
                else if (key > node->val)
                    node = node->right;
                else node = node->left;
            }
            return false;
        }

        int findMin() {
            auto node=root_;
            while(node->left!=NULL)
                node=node->left;
            return node->val;
        }

        int findMax() {
            auto node=root_;
            while(node->right!=NULL)
                node=node->right;
            return node->val;
        }

        //大前提，二叉搜索树中值全部不相等
        //前驱，在不含父指针的情况下
        TreeNode* predecessor(TreeNode *node) {
            if (node == root_)//根节点没有前驱
                return NULL;
            //如果node存在左子树，那么返回左子树最大的结点
            if (node->left != NULL) {
                auto pre = node->left;
                while (pre->right != NULL)
                    pre = pre->right;
                return pre;
            }
            //如果node不存在左子树
            TreeNode *pLeft, *root, *parent;
            root = root_;
            while (root != NULL) {
                parent = root;
                if (root->val>node->val)
                    root=root->left;
                else if (root->val<node->val) {
                    pLeft = root;//距离node最近的一次出现右拐点
                    root = root->right;
                } else break;
            }
            if(parent->right == node)
                return parent;
            else
                return pLeft;
        }
        
        //后继
        TreeNode* successor(TreeNode *node){
            //如果node存在右子树，那么返回右子树最小的结点
            if(node->right!=NULL){
                auto pre=node->right;
                while(pre->left!=NULL)
                    pre=pre->left;
                return pre;
            }
            //如果node不存在右子树
            TreeNode *pRight=NULL, *root, *parent;
            root=root_;
            while(root!=NULL){
                parent=root;
                if(root->val>node->val{
                    pRight=root;//距离node最近的一次出现左拐点
                    root=root->left;
                }
                else if(root->val<node->val)
                    root=root->right;
                else break;
            }
            
            if(parent->left==node)
                return parent;
            else
                return pRight;//pRight为空，则说明没有后继
        }

        //顺序量相关的操作，依赖于结点中维护的num参数
        int rank(TreeNode *node){//给出node排名
            int rankNum=0;
            if(node==NULL)
                return -1;
            auto root=root_;
            while(root!=NULL){
                if(node->val>root->val){
                    rankNum+=root->num;
                    root=root->right;
                }
                else if(node->val<root->val){
                    rankNum-=1;
                    root=root->left;
                }
                else return rankNum
            }
            return rankNum;
        }

        TreeNode* searchKth(int k){
            auto root=root_;
            if(k->root->num)
                return NULL;
            while(root!=NULL){
                if(k==1)
                    return root;
                if(root->left){
                    if(k>root->left->num){
                        k-=root->left->num+1;
                        root=root->right;
                    }
                    root=root->left;
                    continue;
                }
                root = root->right;
                k -= 1;
            }
            return NULL;
        }

    private:
        TreeNode* root_;
        int size_;
};

#endif