# chapter13

## 思考题
###Problems 1
#### Q 持久动态集合
a. For a general persistent binary search tree, identify the nodes that need to be changed to insert a key k or delete a node y.

b. Write a procedure PERSISTENT-TREE-INSERT that, given a persistent tree T and a key k to insert, returns a new persistent tree T′ that is the result of inserting k into T.

c. If the height of the persistent binary search tree T is h, what are the time and space requirements of your implementation of PERSISTENT-TREE-INSERT? (The space requirement is proportional to the number of new nodes allocated.)

d. Suppose that we had included the parent field in each node. In this case, PERSISTENT-TREE-INSERT would need to perform additional copying. Prove that PERSISTENT-TREE-INSERT would then require Ω(n) time and space, where n is the number of nodes in the tree.

e. Show how to use red-black trees to guarantee that the worst-case running time and space are O(lg n) per insertion or deletion.

#### A
* a. 插入一个节点，根节点到被插入的这个叶子节点上路径都会改变   
  删除一个节点，有多种情况，如果被删除的节点是单孩子，那么改变的是根节点到被删除的节点，如果是双孩子，那么改变的时根节点到被删除节点的后继的节点，这一条路径。
* b. 从根节点开始，每往下寻找一个节点，就创建一个新节点，完全复制，直到将要插入的节点插入。然后返回复制的根节点。
* c. 都是O(h)。
* d. 增加了父指针，则需要复制整个树，因为一旦根节点改变了，其他所有节点的父指针都要变。
* e. 根据d的要求，不能有父指针的情况下，实现红黑树，可以用辅助的栈来记录经过的节点。

###Problems 2
#### Q 红黑树的连接操作
a. Given a red-black tree T, we store its black-height as the field bh[T]. Argue that this field can be maintained by RB-INSERT and RB-DELETE without requiring extra storage in the nodes of the tree and without increasing the asymptotic running times. Show that while descending through T, we can determine the black-height of each node we visit in O(1) time per node visited.

b. Assume that bh[T1] ≥ bh[T2]. Describe an O(lg n)-time algorithm that finds a black node y in T1 with the largest key from among those nodes whose black-height is bh[T2].

c. Let Ty be the subtree rooted at y. Describe how   can replace  in O(1) time without destroying the binary-search-tree property.

d. What color should we make x so that red-black properties 1, 3, and 5 are maintained? Describe how properties 2 and 4 can be enforced in O(lg n) time.

e. Argue that no generality is lost by making the assumption in part (b). Describe the symmetric situation that arises when bh[T1] = bh[T2].

f. Argue that the running time of RB-JOIN is O(lg n).

#### A
* a. 
* b. 
* c. 
* d. 
* e. 


###Problems 3
#### Q AVL树
An AVL tree is a binary search tree that is height balanced: for each node x, the heights of the left and right subtrees of x differ by at most 1. To implement an AVL tree, we maintain an extra field in each node: h[x] is the height of node x. As for any other binary search tree T, we assume that root[T] points to the root node.

a. Prove that an AVL tree with n nodes has height O(lg n). (Hint: Prove that in an AVL tree of height h, there are at least Fh nodes, where Fh is the hth Fibonacci number.)

b. To insert into an AVL tree, a node is first placed in the appropriate place in binary search tree order. After this insertion, the tree may no longer be height balanced. Specifically, the heights of the left and right children of some node may differ by 2. Describe a procedure BALANCE(x), which takes a subtree rooted at x whose left and right children are height balanced and have heights that differ by at most 2, i.e., |h[right[x]] - h[left[x]]| ≤ 2, and alters the subtree rooted at x to be height balanced. (Hint: Use rotations.)

c. Using part (b), describe a recursive procedure AVL-INSERT(x, z), which takes a node x within an AVL tree and a newly created node z (whose key has already been filled in), and adds z to the subtree rooted at x, maintaining the property that x is the root of an AVL tree. As in TREE-INSERT from Section 12.3, assume that key[z] has already been filled in and that left[z] = NIL and right[z] = NIL; also assume that h[z] = 0. Thus, to insert the node z into the AVL tree T, we call AVL-INSERT(root[T], z).

d. Show that AVL-INSERT,run on an n-node AVL tree,takes O(lgn) time and performs O(1) rotations.

#### A
* a. 
* b. 
* c. 
* d. 


###Problems 4
#### Q Treap树

a. Show that given a set of nodes x1, x2, ..., xn, with associated keys and priorities (all distinct), there is a unique treap associated with these nodes.

b. Show that the expected height of a treap is Θ(lg n), and hence the time to search for a value in the treap is Θ(lg n).

c. Explain how TREAP-INSERT works. Explain the idea in English and give pseudocode. (Hint: Execute the usual binary-search-tree insertion procedure and then perform rotations to restore the min-heap order property.)

d. Show that the expected running time of TREAP-INSERT is Θ(lg n).

e. Consider the treap T immediately after x is inserted using TREAP-INSERT. Let C be the length of the right spine of the left subtree of x. Let D be the length of the left spine of the right subtree of x. Prove that the total number of rotations that were performed during the insertion of x is equal to C + D.

#### A
* a. 最小堆，所以每个根都是最小的。并且二叉搜索树，要求左子树一定小于右子树，故可以唯一确定一颗treap树
* b. 
* c. 
* d. 
* e.