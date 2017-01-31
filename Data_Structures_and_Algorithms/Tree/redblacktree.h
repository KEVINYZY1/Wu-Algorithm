#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include<cstdlib>

//红黑树
//红黑树是2-3-4树（即4阶的B树）的一种抽象表示。
//左倾红黑树，是对红黑树的一种改进，增加了只有左子树是红色的条件限制，这样代码实现比起红黑树简单许多。
//左倾红黑树是对2-3树（即3阶的B树）的一种抽象表示。
//下面的实现就是左倾红黑树。
enum colour{RED, BLACK};

struct TreeNode{
    int key;
    int val;
    TreeNode *left, *right;
    colour rb;
    int num;
    TreeNode(int key, int value=0, colour r=RED){
        this->key=key;
        this->val=value;
        left=NULL;
        right=NULL;
        rb=r;
        num=1;
    }
};

class redBlackTree{
    public:
        redBlackTree(){
            root_=NULL;
            size_=0;
        }
        
        void insert(int key, int value){
            root_=put(root_,key,value);
            root_->colour=BLACK;
        }
        bool delete(int key){
            if(root_==NULL)
                return false;
            if(!isRed(root_->left) && !isRed(root_->right))
                root_->colour=RED;
            root=delete(root_,key);
            if(root_)
                root_->colour=BLACK;
            return true;
        }

        void deleteMin() {
            if (root_==NULL)             
                return;
            if (!isRed(root_.left) && !isRed(root_.right))
                root_.color = RED;

            root_ = deleteMin(root_);
            if (root_!=NULL) root.color = BLACK;
        }

        void deleteMax() {
            if (root_==NULL)             
                return;
            if (!isRed(root_.left) && !isRed(root_.right))
                root_.color = RED;

            root_ = deleteMax(root_);
            if (root_!=NULL) root.color = BLACK;
        }

        //除了插入删除操作，其余操作都是二叉搜索树的操作直接复用
        bool search(int key){
            auto node=root_;
            while(node!=NULL){
                if(key==node->val)
                    return true;
                else if(key>node->val)
                    node=node->right;
                else node=node->left;
            }
            return false;
        }
        int findMin(){
            auto node=root_;
            while(node->left!=NULL)
                node=node->left;
            return node->val;
        }
        int findMax(){
            auto node=root_;
            while(node->right!=NULL)
                node=node->right;
            return node->val;
        }
        //大前提，二叉搜索树中值全部不相等
        //前驱，在不含父指针的情况下
        TreeNode* predecessor(TreeNode *node){
            if(node==root_)//根节点没有前驱
                return NULL;
            //如果node存在左子树，那么返回左子树最大的结点
            if(node->left!=NULL){
                auto pre=node->left;
                while(pre->right!=NULL)
                    pre=pre->right;
                return pre;
            }
            //如果node不存在左子树
            TreeNode *pLeft, *root, *parent;
            root=root_;
            while(root!=NULL){
                parent=root;
                if(root->val>node->val)
                    root=root->left;
                else if(root->val<node->val){
                    pLeft=root;//距离node最近的一次出现右拐点
                    root=root->right;
                }
                else break;
            }
            if(parent->right==node)
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
                root=root->right;
                k-=1;
            }
            return NULL;
        }
    private:
        //插入的辅助操作
        TreeNode *put(TreeNode *h, int key, int value){
            if(h==NULL){
                h=new TreeNode(key, value, RED);//每次插入的节点都是红色，这样是为了不破坏黑色完美平衡
                return h;
            }
            if(h->val>key)
                h->left=put(h->left, key, value);
            else if(h->val<key)
                h->right=put(h->right, key, value);
            else {
                h->val=value;
                return h;
            }
            //情况1，h的左子树黑色，右子树红色
            if(!isRed(h->left) && isRed(h->right))
                h=rotateLeft(h);
            //情况2，h的左子树红色，h的左子树的左子树也是红色
            if(isRed(h->left) && isRed(h->left->left))
                h=rotateRight(h);
            //情况3，h的左右子树都是红色
            if((isRed(h->left) && isRed(h->right))
                flipColorsInsert(h);
            h->num=h->left->num+h->right->right+1;
            return h;
        
        //删除的辅助操作
        TreeNode * deleteMin(TreeNode * h) { 
            if (h->left == NULL)
                return NULL;

            if (!isRed(h->left) && !isRed(h->left->left))
                h = moveRedLeft(h);

            h->left = deleteMin(h->left);
            return balance(h);
        }
        TreeNode * deleteMax(TreeNode * h) { 
            if (isRed(h->left))
                h = rotateRight(h);

            if (h->right == NULL)
                return NULL;
            if (!isRed(h->right) && !isRed(h->right->left))
                h = moveRedRight(h);

            h->right = deleteMax(h->right);
            return balance(h);
        }
        TreeNode *delete(TreeNode * h, int key){
            if(h->key>key){
                if(!isRed(h->left) && !isRed(h->left->left))
                    h=moveRedLeft(h);
                h->left=delete(h->left,key);
            }
            else{
                if(isRed(h->left))
                    h=rotateRight(h);
                if(h->key==key && h->right==NULL)
                    return null;
                if(!isRed(h->right) && !isRed(h->right->left)){
                    h=moveRedRight(h);
                }
                if(h->key==key){
                    h->val=
                    h->key=
                    h->right=deleteMin(h->right);
                }
                else h->right=delete(h->right,key);
            }
            return balance(h);
        }
        TreeNode *balance(TreeNode *h){
            if(isRed(h->right))
                rotateLeft(h);
            //情况1，h的左子树黑色，右子树红色
            if(!isRed(h->left) && isRed(h->right))
                h=rotateLeft(h);
            //情况2，h的左子树红色，h的左子树的左子树也是红色
            if(isRed(h->left) && isRed(h->left->left))
                h=rotateRight(h);
            //情况3，h的左右子树都是红色
            if((isRed(h->left) && isRed(h->right))
                flipColorsDelete(h);
            h->num=h->left->num+h->right->right+1;
            return h;
        }
        TreeNode *moveRedLeft(TreeNode *h){
            flipColorsDelete(h);
            if(isRed(h->right->left)){
                h->right=rotateRight(h);
                h=rotateLeft(h);
            }
            return h;
        }
        TreeNode *moveRedRight(TreeNode *h){
            flipColorsDelete(h);
            if(isRed(h->left->left))
                h=rotateRight(h);
            return h;
        }
        //旋转操作只保证了红黑性质中的二叉搜索树性质和黑色结点的完美平衡性
        //左旋
        TreeNode * rotateLeft(TreeNode *h){
            auto temp=h->right;
            h->right=temp->left;
            temp->left=h;
            temp->colour=h->colour;
            h->colour=RED;
            temp->num=h->num;
            h->num=1+h->left->num+h->right->num;
        }
        //右旋 
        TreeNode * rotateRight(TreeNode *h){
            auto temp=h->left;
            h->left=temp->right;
            temp->right=h;
            temp->colour=h->colour;
            h->colour=RED;
            temp->num=h->num;
            h->num=1+h->left->num+h->right->num;
        }
        //颜色操作
        void flipColorsInsert(TreeNode *h){
            h->colour=RED;
            h->left->colour=BLACK;
            h->right->colour=BLACK;
        }
        void flipColorsDelete(TreeNode *h){
            h->colour=BLACK;
            h->left->colour=RED;
            h->right->colour=RED;
        }
        bool isRed(TreeNode *h){
            if(h==NULL)
                return false;
            return h->colour==RED;
        }

        TreeNode *root_;
        int size_;
};

#endif