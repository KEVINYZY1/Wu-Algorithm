/*
题目描述:
现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
输入
输入的第一行表示节点的个数n（1<=n<=1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
输出
输出树的高度，为一个整数
*/

#include <iostream>
#include <vector>
using namespace std;

/* 就是先建树，再递归找，最后把树删了，有更好方法吗，懒得写这个了
struct TreeNode{
  	TreeNode (){
    	l=NULL;
      	r=NULL;
    }
	TreeNode *l, *r;
};

int main(){
	int n;
  	cin>>n;
  	vector<TreeNode*> v(n, NULL);
  	//还需要一个布尔数组，来确定root是哪个，root不会出现在y上面
  	for(int i=0; i<n; i++){
    	int x, y;
      	cin>>x>>y;
      	if(v[x]){
        	if(v[x]->l){
            	if(!v[y]){
          			v[x]->r=new TreeNode;
          			v[y]=v[x]->r;
            	}
          		else{
            		v[x]->r=v[y];
           		}
            }
        }
        else{
        	//放到左子树
          	v[x]=new TreeNode;
          	if(!v[y]){
          		v[x]->l=new TreeNode;
          		v[y]=v[x]->l;
            }
          	else{
            	v[x]->l=v[y];
            }
        }
    }
   //遍历树高
   
   //删除新建的树
}
*/