# chapter7

## 思考题
###Problems 1
####Q Hoare划分的正确性
The version of PARTITION given in this chapter is not the original partitioning algorithm. Here is the original partition algorithm, which is due to T. Hoare:

```
HOARE-PARTITION(A, p, r):
    x <- A[p]
    i <- p - 1
    j <- r + 1
    while TRUE:
        do repeat j <- j - 1
                until A[j] <= x
           repeat i <- i + 1
                until A[i] >= x
           if i < j:
                then exchange A[i] <-> A[j]
                else return j
```  
              
* a. Demonstrate the operation of HOARE-PARTITION on the array A = [13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21], showing the values of the array and auxiliary values after each iteration of the for loop in lines 4-11.

The next three questions ask you to give a careful argument that the procedure HOARE- PARTITION is correct. Prove the following:

* b. The indices i and j are such that we never access an element of A outside the subarray A[p...r].

* c. When HOARE-PARTITION terminates, it returns a value j such that p ≤ j < r.

* d. Every element of A[p...j] is less than or equal to every element of A[j+1...r] when HOARE-PARTITION terminates.

The PARTITION procedure in Section 7.1 separates the pivot value (originally in A[r]) from the two partitions it forms. The HOARE-PARTITION procedure, on the other hand, always places the pivot value (originally in A[p]) into one of the two partitions A[p...j] and A[j + 1...r]. Since p ≤ j < r, this split is always nontrivial.

* e. Rewrite the QUICKSORT procedure to use HOARE-PARTITION.

#### A
**Hoare-Partition方法正是stl中partition算法的实现**  

* a. 易证
* b. 一旦i和j有交错，则结束该函数，故不会
* c. 显然易见
* d. 显而易见
* e. [code](https://github.com/swananan/Wu-Algorithm/blob/master/Data_Structures_and_Algorithms/Sort/quicksort.h)

###Problems 2
####Q 针对相同元素的快速排序
The analysis of the expected running time of randomized quicksort in section 7.4.2 assumes that all element values are distinct. In this problem. we examine what happens when they are not.  

* a. Suppose that all element values are equal. What would be randomized quick-sort's running time in this case?

* b. The PARTITION procedure returns an index q such that each element of A[p…q−1] is less than or equal to A[q] and each element of A[q+1…r] is greater than A[q]. Modify the PARTITION procedure to produce a procedure PARTITION'(A, p, r) which permutes the elements of A[p…r] and returns two indices q and t where p≤q≤t≤r, such that:  

>> all elements of A[q…t] are equal,  
>>each element of A[p…q−1] is less than A[q],  
>>and each element of A[t+1…r] is greater than A[q].

* c. Modify the RANDOMIZED-QUICKSORT procedure to call PARTITION', and name the new procedure RANDOMIZED-QUICKSORT'. Then modify the QUICKSORT procedure to produce a procedure QUICKSORT'(p, r) that calls RANDOMIZED-PARTITION' and recurses only on partitions of elements not know to be equal to each other.
* d. Using QUICKSORT', how would you adjust the analysis of section 7.4.2 to avoid the assumption that all elements are distinct?
#### A
* a. 属于快排的最坏情况，时间复杂度为O(n^2 )
* b. c. [code]()
* d. 不清楚

###Problems 3
####Q 另一种快速排序的分析方法 
An alternative analysis of the running time of randomized quicksort focuses on the expected running time of each individual recursive call to QUICKSORT, rather than on the number of comparisons performed.

* a. Argue that, given an array of size n, the probability that any particular element is chosen as the pivot is 1/n. Use this to define indicator random variables Xi = I{ith smallest element is chosen as the pivot}. What is E [Xi]?
* b. 略
* c. 略
* d. 略
* e. Using the bound from equation (7.7), show that the recurrence in equation (7.6) has the solution E [T (n)] = Θ(n lg n). (Hint: Show, by substitution, that E[T (n)] ≤ an log n - bn for some positive constants a and b.)


#### A   数学题= =
* a. E[Xi]=1/n.
* b. 书中已经有了
* c. 显然易见
* d. 略
* e. 略

###Problems 4
####Q 快速排序的栈深度
The QUICKSORT algorithm of Section 7.1 contains two recursive calls to itself. After the call to PARTITION, the left subarray is recursively sorted and then the right subarray is recursively sorted. The second recursive call in QUICKSORT is not really necessary; it can be avoided by using an iterative control structure. This technique, called tail recursion, is provided automatically by good compilers. Consider the following version of quicksort, which simulates tail recursion.

```
QUICKSORT'(A, p, r):
    while p < r:
        do  Partition and sort left subarray.
            q <- PARTITION(A, p, r)
            QUICKSORT'(A, p, q-1)
            p <- q + 1
```

* a. Argue that QUICKSORT'(A, 1, length[A]) correctly sorts the array A.

Compilers usually execute recursive procedures by using a stack that contains pertinent information, including the parameter values, for each recursive call. The information for the most recent call is at the top of the stack, and the information for the initial call is at the bottom. When a procedure is invoked, its information is pushed onto the stack; when it terminates, its information is popped. Since we assume that array parameters are represented by pointers, the information for each procedure call on the stack requires O(1) stack space. The stack depth is the maximum amount of stack space used at any time during a computation.

* b. Describe a scenario in which the stack depth of QUICKSORT' is Θ(n) on an n-element input array.

* c. Modify the code for QUICKSORT' so that the worst-case stack depth is Θ(lg n). Maintain the O(n lg n) expected running time of the algorithm.

#### A
对快速排序的一种优化，减少了函数调用，在stl中的sort算法源代码中也是如此。 
 
* a. 自然是没问题的
* b. 遇到了最坏情况，每次PARTITION都return r
* c. 做出一个选择，选择范围小的一边进行递归调用  


###Problems 5
####Q 三数取中划分

One way to improve the RANDOMIZED-QUICKSORT procedure is to partition around a pivot that is chosen more carefully than by picking a random element from the subarray. One common approach is the median-of-3 method: choose the pivot as the median (middle element) of a set of 3 elements randomly selected from the subarray. (See Exercise 7.4-6.) For this problem, let us assume that the elements in the input array A[1...n] are distinct and that n ≥ 3. We denote the sorted output array by A'[1...n]. Using the median-of-3 method to choose the pivot element x, define pi = Pr{x = A'[i]}.

* a. Give an exact formula for pi as a function of n and i for i=2,3,...,n-1.(Note that p1 = pn = 0.)

* b. By what amount have we increased the likelihood of choosing the pivot as x = A'[⌊(n
1/2⌋], the median of A[1...n], compared to the ordinary implementation? Assume that n → ∞, and give the limiting ratio of these probabilities.  

* c. If we define a "good" split to mean choosing the pivot as x = A'[i], where n/ ≤ i ≤ 2n/3, by what amount have we increased the likelihood of getting a good split compared to the ordinary implementation? (Hint: Approximate the sum by an integral.)

* d. Argue that in the Ω(n lg n) running time of quicksort, the median-of-3 method affects only the constant factor.

#### A
stl中sort选取主元就是这样选取的

不想回答= =

###Problems 6
####Q 对区间的模糊排序
Consider the problem in which we do not know the numbers exactly. Instead, for each number, we know an interval on the real line to which it belongs. That is, we are given n closed intervals of the form [ai,bi], where ai≤bi. We wish to fuzzy-sort these intervals, i.e., to produce a permutation ⟨i1,i2,…,in⟩ of the intervals such that for j=1,2,…,n, there exists cj∈[aij,bij] satisfying c1≤c2≤⋯≤cn.

* a. Design a randomized algorithm for fuzzy-sorting n intervals. Your algorithm should have the general structure of an algorithm that quicksorts the left endpoints (the ai values), but it should take advantage of overlapping intervals to improve the running time. (As the intervals overlap more and more, the problem of fuzzy-sorting the intervals becoes progressively easier. Your algorithm should take advantage of such overlapping, to the extend that it exists).
* b. Argue that your algorithm runs in expected time Θ(nlgn) in general, but runs in expected time Θ(n) when all of the intervals overlap (i.e., when there exists a value x such that x∈[ai,bi] for all i). Your algorithm should not be checking for this case explicitly; rather, its performance should naturally improve as the amount of overlap increases.

#### A
[code](https://github.com/swananan/Wu-Algorithm/blob/master/Data_Structures_and_Algorithms/Sort/quicksort.h)