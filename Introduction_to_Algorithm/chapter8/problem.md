# chapter8

## 思考题
###Problems 1
####Q 比较排序的概率下界
In this problem, we prove an Ω(n lg n) lower bound on the expected running time of any deterministic or randomized comparison sort on n distinct input elements. We begin by examining a deterministic comparison sort A with decision tree TA. We assume that every permutation of A's inputs is equally likely.


* a. Suppose that each leaf of TA is labeled with the probability that it is reached given a random input. Prove that exactly n! leaves are labeled 1/n! and that the rest are labeled 0.

* b. Let D(T) denote the external path length of a decision tree T ; that is, D(T) is the sum of the depths of all the leaves of T. Let T be a decision tree with k > 1 leaves, and let LT and RT be the left and right subtrees of T. Show that D(T) = D(LT) + D(RT) + k.

* c. Let d(k) be the minimum value of D(T) over all decision trees T with k > 1 leaves. Show that  

(Hint: Consider a decision tree T with k leaves that achieves the minimum. Let i0 be the number of leaves in LT and k - i0 the number of leaves in RT.)

* d. Prove that for a given value of k > 1 and i in the range 1 ≤ i ≤ k-1,the function ilgi+ (k - i)lg(k - i) is minimized at i = k/2. Conclude that d(k) = Θ(klgk).

The PARTITION procedure in Section 7.1 separates the pivot value (originally in A[r]) from the two partitions it forms. The HOARE-PARTITION procedure, on the other hand, always places the pivot value (originally in A[p]) into one of the two partitions A[p...j] and A[j + 1...r]. Since p ≤ j < r, this split is always nontrivial.

* e. Prove that D(TA) = Θ(n! lg(n!)), and conclude that the expected time to sort n elements is Θ(n lg n).

Now, consider a randomized comparison sort B. We can extend the decision-tree model to handle randomization by incorporating two kinds of nodes: ordinary comparison nodes and "randomization" nodes. A randomization node models a random choice of the form RANDOM(1, r) made by algorithm B; the node has r children, each of which is equally likely to be chosen during an execution of the algorithm.

* f. Show that for any randomized comparison sort B, there exists a deterministic comparison sort A that makes no more comparisons on the average than B does.

#### A

* a. 既然每一种排列都是等可能的，自然每个叶子结点到达概率为1/n!
* b. T比它的左右子树都多了一层，故最后T的叶子结点数k加上左右子树的外部路径长度，就是T的外部路径长度
* c. 由b推出的性质D(T) = D(LT) + D(RT) + k  
c中结论自然可以得出
* d. 求导
* e. TA一共有n!个叶子节点，所以有D(T) > d(n!) = Ω(n!lg(n!))，一共有n!个概率相同的叶子节点，故平均情况下，O(nlgn)  


* f.额，反正就n!种可能，必然有一种确定排序算法，比较次数不多于随机的


###Problems 2
####Q 线性时间的原址排序  

Suppose that we have an array of n data records to sort and that the key of each record has the value 0 or 1. An algorithm for sorting such a set of records might possess some subset of the following three desirable characteristics:

* The algorithm runs in O(n) time.

* The algorithm is stable.

* The algorithm sorts in place, using no more than a constant amount of storage space in addition to the original array.

a. Give an algorithm that satisfies criteria 1 and 2 above.

b. Give an algorithm that satisfies criteria 1 and 3 above.

c. Give an algorithm that satisfies criteria 2 and 3 above.

d. Can any of your sorting algorithms from parts (a)-(c) be used to sort n records with b- bit keys using radix sort in O(bn) time? Explain how or why not.

e.Suppose that the n records have keys in the range from 1 to k. Show how to modify counting sort so that the records can be sorted in place in O(n + k) time. You may use O(k) storage outside the input array. Is your algorithm stable? (Hint: How would you do it for k = 3?)  

#### A
* a. 排序算法满足O(n)时间复杂度，并且稳定，选择计数排序
* b. 排序算法满足O(n)时间复杂度，并且原址排序，7.1的算法
* c. 排序算法满足原址排序，并且稳定，选择归并排序
* d. 计数可以，归并超时，第二种不稳定
* e. [code](https://github.com/swananan/Wu-Algorithm/blob/master/Data_Structures_and_Algorithms/Sort/countsort.h)


###Problems 3
####Q 可变长数据项的排序
a. You are given an array of integers, where different integers may have different numbers of digits, but the total number of digits over all the integers in the array is n. Show how to sort the array in O(n) time.

b. You are given an array of strings, where different strings may have different numbers of characters, but the total number of characters over all the strings is n. Show how to sort the strings in O(n) time.

(Note that the desired order here is the standard alphabetical order; for example, a < ab < b.)

#### A
* a. 将相同位数的数分为一组，然后对每组进行基数排序。由于基数排序为O(n)，综合起来排序时间必然为O(n)
* b. 这里是按字典序，故与上一小题有所区别。字典序由于是从左边开始比较，为了方便比较，我们把所有字符串都逆序，最后排完序再逆转回来。逆序之后的字符串，我们可以从低位开始基数排序。当遍历某个字符串的长度不够时，则直接保持原位置不动，对足够长的字符串继续基数排序，直到排完最高位结束。

###Problems 4
####Q 水壶
Suppose that you are given n red and n blue water jugs, all of different shapes and sizes. All red jugs hold different amounts of water, as do the blue ones. Moreover, for every red jug, there is a blue jug that holds the same amount of water, and vice versa. It is your task to find a grouping of the jugs into pairs of red and blue jugs that hold the same amount of water. To do so, you may perform the following operation: pick a pair of jugs in which one is red and one is blue, fill the red jug with water, and then pour the water into the blue jug. This operation will tell you whether the red or the blue jug can hold more water, or if they are of the same volume. Assume that such a comparison takes one time unit. Your goal is to find an algorithm that makes a minimum number of comparisons to determine the grouping. Remember that you may not directly compare two red jugs or two blue jugs.

a. Describe a deterministic algorithm that uses Θ(n2) comparisons to group the jugs into pairs.

b. Prove a lower bound of Θ(n lg n) for the number of comparisons an algorithm solving this problem must make.

c. Give a randomized algorithm whose expected number of comparisons is O(n lg n), and prove that this bound is correct. What is the worst-case number of comparisons for your algorithm?

#### A
* a. 类似于选择排序，每次遍历找到一对。
* b. 题目所说情况下，只能通过比较判断红蓝瓶是否一致。分别有相同，红色大于蓝色，红色小于蓝色情况。决策树是三叉树。3^h >=n!，可见h最小也是O(nlgn)
* c. 随机化快排。最坏情况就是每次随机主元都不能有效划分区间，比较次数和选择排序一样多。

###Problems 5
####Q 平均排序
Suppose that, instead of sorting an array, we just require that the elements increase on average. More precisely, we call an n-element array A k-sorted if, for all i = 1, 2, . . ., n - k, the following holds:
公式略


a. What does it mean for an array to be 1-sorted?

b. Give a permutation of the numbers 1, 2, . . ., 10 that is 2-sorted, but not sorted.

c. Provethatann-element arrayisk-sortedifandonly if A[i]≤A[i+k]，for all i=1,2,.. ., n - k.

d. Give an algorithm that k-sorts an n-element array in O(n lg(n/k)) time.

e. Show that a k-sorted array of length n can be sorted in O(n lg k) time. (Hint: Use the solution to Exercise 6.5-8.)

f. Show that when k is a constant, it requires Θ(n lg n) time to k-sort an n-element array. (Hint: Use the solution to the previous part along with the lower bound on comparison sorts.)

#### A
* a. 正常升序
* b. 排列 2 1 3 4 5 6 7 8 9 10
* c. 由k排序的定义可以轻松得知
* d. c的结论逆推也是对的，故将一个数组k排序，即满足条件（if A[i]≤A[i+k]，for all i=1,2,.. ., n - k.）即可。应该将数组分成k组，每组的元素下标都是间隔k，然后都每组使用堆排序或者归并排序，可以保证时间复杂度。
* e. 长度为n的k排序数组，即该数组中有k组有序数组，然后使用6.5-9题目中的k路归并，可以保证在O(nlgk)时间内完成排序。
* f. k排序可以被看做对k组长度为(n/k)的数组进行排序，已知全排序的下界，故可以容易得出k排序的下界

###Problems 6
####Q 合并有序列表的下界
The problem of merging two sorted lists arises frequently. It is used as a subroutine of MERGE-SORT, and the procedure to merge two sorted lists is given as MERGE in Section 2.3.1. In this problem, we will show that there is a lower bound of 2n - 1 on the worst-case number of comparisons required to merge two sorted lists, each containing n items.

First we will show a lower bound of 2n - o(n) comparisons by using a decision tree.

a. Show that, given 2n numbers, there are ￼ possible ways to divide them into two sorted lists, each with n numbers.

b. Using a decision tree, show that any algorithm that correctly merges two sorted lists uses at least 2n - o(n) comparisons.

Now we will show a slightly tighter 2n - 1 bound.

c. Show that if two elements are consecutive in the sorted order and from opposite lists, then they must be compared.

d. Use your answer to the previous part to show a lower bound of 2n - 1 comparisons for merging two sorted lists.

#### A
* a. 全排列问题，从2n个数中找出n个数的组合。
* b. 2^h >(从2n个数中找出n个数的组合个数)
* c. 理所应当
* d. 面对所有情况在内，能做最少比较，至少是2n-1

###Problems 7
####Q 0-1排序引理和列排序

A compare-exchange operation on two array elements A[i] and A[j], where i<j has the form:

COMPARE-EXCHANGE(A, i, j)
  if A[i] > A[j]
      exchange A[i] with A[j]
After the compare-exchange operation, we know that A[i]≤A[j].

An oblivious compare-exchange algorithm operates solely by a sequence of prespecified compare-exchange operations. The indices of the positions compared in the sequence must be determined in advance, and although they can depend on the number of elements being sorted, they cannot depend on the values being sorted, nor can they depend on the result of any prior compare-exchange operation. For example, here is insertion sort expressed as an oblivious compare-exchange algorithm:

INSERTION-SORT(A)
  for j = 2 to A.length
      for i = j - 1 downto 1
          COMPARE-EXCHANGE(A, i, i + 1)
The 0-1 sorting lemma provides a powerful way to prove that an oblivious compare-exchange algorithm produces a sorted result. It states that if an oblivious compare-exchange algorithm correctly sorts all input sequences consisting of only 0s and 1s, then it correctly sorts all inputs containing arbitrary values.

You will prove the 0-1 sorting lemma by proving its contrapositive: if an oblivious compare-exchange algorithm fails to sort an input containing arbitrary values, then it fails to sort some 0-1 input. Assume that an oblivious compare-exchange algorithm X fails to correctly sort the array A[1..n]. Let A[p] be the smallest value in A that algorithm X puts into the wrong location, and let A[q] be the value that algorithm X moves to the location into which A[p] should have gone. Define an array B[1..n] of 0s and 1s as follows:

B[i]={01 if A[i]≤A[p] if A[i]>A[p]

* a  
Argue that A[q]>A[p], so that B[p]=0 and B[q]=1.
* b  
To complete the proof 0-1 sorting lemma, provide that algorithm X fails to sort array B correctly.
Now you will use the 0-1 sorting lemma to prove that a particular sorting algorithm works correctly. The algorithm, columnsort, works on a rectangular array of n elements. The array has r rows and s columns (so that n=rs), subject to three restrictions:

* r must be even,
* s must be a divisor of r, and
* r≥2s2.  


When columnsort completes, the array is sorted in column-major order: reading down the columns, from left to right, the elements monotonically increase.

Columnsort operates in eight steps, regardless of the value of n. The odd steps are all the same: sort each column individually. Each even step is a fixed permutation. Here are the steps:

1. Sort each column.
2. Transpose the array, but reshape it back to r rows and s columns. In other words, turn the leftmost column into the top r/s rows, in order; turn the next column into the next r/s rows, in order; and so on.
3. Sort each column.
4. Perform the inverse of the permutation performed in step 2.
5. Sort each column.
6. Shift the top half of each column into the bottom half of the same column, and shift the bottom half of each column into the top half of the next column to the right. Leave the top half of the leftmost column empty. Shift the bottom half of the last column into the top last column into the top half of a new rightmost column, and leave the bottom half of this new column empty.
7. Sort each column
8. Perform the inverse of the permutation performed in step 6.
Figure 8.5 shows an example of the steps of columnsort with r=6 and s=3. (Even though this example violated the requirement that r≥2s2, it happens to work.)

* c  
Argue that we can treat columnsort as an oblivious compare-exchange algorithm, even if we do not know what sorting method the odd steps are.
Although it might seem hard to believe that columnsort actually sorts, you will use the 0-1 sorting lemma to prove that it does. The 0-1 dorting lemma applies because we can treat columnsort as an oblivious compare-exchange algorithm. A couple of definitions will help you apply the 0-1 sorting lemma. We say that an area of an array is clean if we know that it contains either all 0s or all 1s. Otherwise, the area might contain mixed 0s and 1s, and it is dirty. From here on, assume that the input array contains only 0s and 1s, and that we can treat it as an array with r rows and s columns.
* d  
Prove that after steps 1-3, the array consists of some clean rows of 0s at the top, some clean rows of 1s at the bottom, and at most s dirty rows between them
* e  
Prove that after step 4, the array, read in column-major order, starts with a clean area of 0s, ends with a clean area of 1s, and has a dirty area of at most s2 elements in the middle.
* f  
Prove that steps 5-8 produce a fully sorted 0-1 output. Conclude that columnsort correctly sorts all inputs containing arbitrary values.
* g  
Now suppose that s does not divide r. Prove that after steps 1-3, the array consists of some clean rows of 0s at the top, some clean rows of 1s at the bottom, and at most 2s−1 dirty rows between them. How large must r be, compared with s, for columnsort to correctly sort when s does not divide r?
* h  
Suggest a simple change to step 1 that allow us to maintain the requirement that r≥2s2 when s does not divide r, and prove that with your change, columnsort correctly sorts.

#### A

证明0-1排序引理

* a. 由B数组的定义，可以证明
* b. 

列排序算法（通过0-1排序引理证明列排序）

* c.
* d.
* e.
* f.
* g.
* h.