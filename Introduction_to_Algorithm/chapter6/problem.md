# chapter6

## 思考题
###Problems 1
####Q 用插入的方法建堆
The procedure BUILD-MAX-HEAP in Section 6.3 can be implemented by repeatedly using MAX-HEAP-INSERT to insert the elements into the heap. Consider the following implementation:

```
BUILD-MAX-HEAP'(A)
    heap-size[A] ← 1
    for i←2 to length[A]
        do MAX-HEAP-INSERT(A, A[i])
```
a. Do the procedures BUILD-MAX-HEAP and BUILD-MAX-HEAP' always create the same heap when run on the same input array? Prove that they do, or provide a counterexample. ￼￼￼￼￼￼￼￼￼￼￼ b. Show that in the worst case, BUILD-MAX-HEAP' requires Θ(n lg n) time to build an n-element heap.

####A 

* a. BUILD-MAX-HEAP'函数是将元素插入末尾，再不断的向上调整。BUILD-MAX-HEAP函数则是将从倒数第二层元素开始一直到第一个元素，不断调用MAX-HEADPIFY函数，将元素向下调整。
* b. 最坏情况，即数组是按递增序列排放。
然后每次都要花费lg(heapsize)的时间来调整堆，heapsize是依次增长的，故总时间是lg(heapsize!),heapsize=n,故时间复杂度为O(nlgn)

###Problems 2
####Q 对**d叉堆**的分析
A d-ary heap is like a binary heap, but (with one possible exception) non-leaf nodes have d children instead of 2 children.

a. How would you represent a d-ary heap in an array? b. What is the height of a d-ary heap of n elements in terms of n and d? c. Give an efficient implementation of EXTRACT-MAX in a d-ary max-heap. Analyze its running time in terms of d and n. d. Give an efficient implementation of INSERT in a d-ary max-heap. Analyze its running time in terms of d and n. e. Give an efficient implementation of INCREASE-KEY(A, i, k), which first sets A[i] ← max(A[i], k) and then updates the d-ary max-heap structure appropriately. Analyze its running time in terms of d and n.

####A 

c++代码实现[code](https://github.com/swananan/Wu-Algorithm/blob/master/Data_Structures_and_Algorithms/Queue/d_aryheap.h)

* a. d叉堆的意思就是，一个树的子节点有d个，而不是原来的两个，其他性质不变。故数组还是原样隐式存放d叉堆，只不过计算节点的父节点与子节点的方法要相应改变。
* b. 设高度为h，1+d+d^2 +...+d^h =n   
					n=(d^h -1)/(d-1)   
可知，h是以d为底的logn
* c. EXTRACT-MAX 时间复杂度 O(dlogd^n )
* d. INSERT 时间复杂度 O(logd^n )
* e. INCREASE-KEY 时间复杂度 O(logd^n )   

当d>2的时候，可见插入有所优化，删除效率变低

###Problems 3
####Q Young氏矩阵
An m × n Young tableau is an m × n matrix such that the entries of each row are in sorted order from left to right and the entries of each column are in sorted order from top to bottom. Some of the entries of a Young tableau may be ∞, which we treat as nonexistent elements. Thus, a Young tableau can be used to hold r ≤ mn finite numbers.

a. Draw a 4×4 Young tableau containing the elements {9, 16, 3, 2, 4, 8, 5, 14, 12}. b. Arguethatanm×nYoungtableauYisemptyifY[1,1]=∞.ArguethatYisfull (contains mn elements) if Y[m, n] < ∞. c. Give an algorithm to implement EXTRACT-MIN on a nonempty m × n Young tableau that runs in O(m + n) time. Your algorithm should use a recursive subroutine that solves an m × n problem by recursively solving either an (m - 1) × n or an m × (n - 1) subproblem. (Hint: Think about MAX-HEAPIFY.) Define T(p), where p = m + n, to be the maximum running time of EXTRACT-MIN on any m × n Young tableau. Give and solve a recurrence for T(p) that yields the O(m + n) time bound. d. Show how to insert a new element into a nonfull m × n Young tableau in O(m + n) time. e. Using no other sorting method as a subroutine, show how to use an n × n Young tableau to sort n^2 numbers in O(n^3) time. f. Give an O(m+n)-time algorithm to determine whether a given number is stored in a given m × n Young tableau.
#### A
c++实现代码 [code](https://github.com/swananan/Wu-Algorithm/blob/master/Data_Structures_and_Algorithms/Queue/youngmatrix.h)

* a. 略
* b. 根据Young氏矩阵的定义，显而易见
* c. 见代码
* d. 见代码
* e. 每次提取其中的最小元素，调用YOUNG-EXTRACT-MIN，共需调用n^2 次，而每次YOUNG-EXTRACT-MIN需要O(n+n)运行时间，故总的运行时间为O(n^3 )
* f. leetcode原题[code](https://github.com/swananan/Wu-Algorithm/blob/master/Leetcode/240_Searcha2DMatrixII.cc)
