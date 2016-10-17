# chapter9

## 思考题
###Problems 1
#### Q 有序序列中得i个最大数
Given a set of n numbers, we wish to find the i largest in sorted order using a comparison- based algorithm. Find the algorithm that implements each of the following methods with the best asymptotic worst-case running time, and analyze the running times of the algorithms in terms of n and i.

a. Sort the numbers, and list the i largest.   
b. Build a max-priority queue from the numbers, and call EXTRACT-MAX i times.  
c. Use an order-statistic algorithm to find the ith largest number, partition around that number, and sort the i largest numbers.
#### A   
* a. O(nlgn)+O(i)
* b. O(n)+O(ilgn)
* c. O(n)+O(ilgi)  
可见使用第三种方法速度最快  

###Problems 2
#### Q 带权中位数
For n distinct elements x1,x2,…,xn with positive weights w1,w2,…,wn such that ∑ni=1wi=1, the weighted (lower) median is the element xk satisfying ∑xi< xkwi<12 and ∑xi>xkwi≤12  
For example, if the elments are 0.1,0.35,0.05,0.1,0.15,0.05,0.2 and each element equals its weight (that is, wi=xi for i=1,2,…,7, then the median is 0.1, but the weighted median is 0.2.

a. Argue that the median of x1,x2,…,xn is the weighted median of xi with weights wi=1/n for i=1,2,…,n.  

b. Show how to compute the weighted median of n elements in O(nlgn) worst-case time using sorting.  

c. Show how to compute the weighted median in Θ(n) worst-case time using a linear-time median algorithm such as `SELECT` from Section 9.3.

*The post-office location problem* is defined as follows. We are given n points p1,p2,…,pn with associated weights w1,w2,…,wn. We wish to find a point p (not necessarily one of the input points) that minimizes the sum ∑ni=1wid(p,pi), where d(a,b) is the distance between the points a and b.  

d. Argue that the weighted median is a best solution for the 1-dimensional post-office location problem, in which points are simply real numbers and the distance between points a and b is d(a,b)=|a−b|.  

e. Find the best solution for the 2-dimensional post-office location problem, in which the points are (x,y) coordinate pairs and the distance between points a=(x1,y1) and b=(x2,y2) is the **Manhattan distance** given by d(a,b)=|x1−x2|+|y1−y2|.

#### A   
* a. 根据带权中位数定义，易证
* b. 先堆排序，然后累加权值，知道大于0.5然后确定带权中位数
* c. 和bfprt算法(即最坏情况线性时间的选择算法)类似，只不过最后比较的是左右区间的权值和是否符合要求。
* d. 
* e. 

###Problems 3
#### Q 小顺序统计量
The worst-case number T(n) of comparisons used by SELECT to select the ith order statistic from n numbers was shown to satisfy T(n) = Θ(n), but the constant hidden by the Θ-notation is rather large. When i is small relative to n, we can implement a different procedure that uses SELECT as a subroutine but makes fewer comparisons in the worst case.

a. Describe an algorithm that uses Ui(n) comparisons to find the ith smallest of n elements, where 公式略(Hint: Begin with   disjoint pairwise comparisons, and recurse on the set containing the smaller element from each pair.)

b. Show that, if i < n/2, then Ui(n) = n + O(T (2i) lg(n/i)).

c. Show that if i is a constant less than n/2, then Ui(n) = n + O(lg n).

d. Show that if i = n/k for k≥2,then Ui(n) = n+O(T(2n/k)lgk).

#### A   
* a.  
 step1:把数组分为两组，从中间分开，分别是A[1..n/2]和A[n/2+1..n]  
step2:依次比较A[1+k]和A[n/2+1+k]的大小，（0<=k<m/2），大的放右边，小的放左边  
step3:对小的一半进行select(i)操作，同时大的那一半也要相应变化。  
step4:select(i)后的结果，A[1..i-1] <= A[i] < A[i+1..n/2]，第i小的元素在A[1..i]和A[n/2+1..n/2+1+i]这两个区间中  
step5：把A[1..i]和A[n/2+1..n/2+1+i]中的元素拿出来，放在另一个数组B中，那么数组B的元素个数是2i，递归地SELECT(B, i)，直到最终找到第i小的元素
* b. 
* c. 
* d. 