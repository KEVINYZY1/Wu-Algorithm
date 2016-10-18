# chapter10

## 思考题
###Problems 1
#### Q 链表间的比较

For each of the four types of lists in the following table, what is the asymptotic worst-case running time for each dynamic-set operation listed?
#### A   
书p128中有相应操作的详细介绍   

| 链表操作  | 未排序单链表  | 已排序单链表 | 未排序双向链表 | 已排序双向链表 |
|:------------- |---------------:| -------------:| -------------:| -------------:|
| SEARCH(L, k)  | O(n)|O(n)|O(n)|O(n)| 
| INSERT(L, x)  | O(1)|O(n)|O(1)|O(n)|               
| DELETE(L, x)  | O(n)|O(n)|O(1)|O(1)| 
| SUCCESSOR(L, x)|O(n)|O(1)|O(n)|O(1)| 
| PREDECESSOR(L, x)|O(n)|O(n)|O(n)|O(1)| 
| MINIMUM(L, k)|O(n)|O(1)|O(n)|O(1)| 
| MAXIMUM(L, k)|O(n)|O(n)|O(n)|O(n)|  
###Problems 2
#### Q 利用链表实现可合并堆
A mergeable heap supports the following operations: MAKE-HEAP (which creates an empty mergeable heap), INSERT, MINIMUM, EXTRACT-MIN, and UNION. Show how to implement mergeable heaps using linked lists in each of the following cases. Try to make each operation as efficient as possible. Analyze the running time of each operation in terms of the size of the dynamic set(s) being operated on.

a. Lists are sorted.

b. Lists are unsorted.

c. Lists are unsorted, and dynamic sets to be merged are disjoint.

#### A      

| 堆操作  |  已排序单链表 | 未排序单链表 | 未排序单链表(union操作是合并不相交的集合) |
|:------------- |-------------:| -------------:| -------------:|
| INSERT  | O(1)|O(n)|O(n)|               
| MINIMUM|O(n)|O(n)|O(n)|
| EXTRACT-MIN|O(n)|O(1)|O(1)|
| UNION|O(n)|O(n)|O(n)|

###Problems 3
#### Q 搜索已排序的紧凑链表
asked how we might maintain an n-element list compactly in the first n positions of an array. We shall assume that the keys are distinct and that the compact list is also sorted, that is, key[i] < key[next[i]] for all i=1,2,…,n such that next[i] ≠ NIL. We will also assume that we have a variable L that contains the index of the first element on the list. Under these assumptions, you will show that we can use the following randomized algorithm to search the list in O(n√) expected time.

```
COMPACT-LIST-SEARCH(L, n, k)
  i = L
  while i ≠ ␀ and key[i] < k
      j = RANDOM(1, n)
      if key[i] < key[j] and key[j] ≤ k
          i = j
          if key[i] == k
              return i
      i = next[i]
  if i == ␀ or key[i] > k
      return ␀
```
If we ignore lines 3-7 of the procedure, we have an ordinary algorithm for searching a sorted linked list, in which index i points to each position of the list in turn. The search terminates once the index i "falls off" the end of the list or once key[i] ≥ k. In the latter case, if key[i] = k, clearly we have found a key with value k. If, however, key[i] > k, then we will never find a key with the value k, and so terminating the search was the right thing to do.

Lines 3-7 attempt to skip ahead to a randomly chosen position j. Such a skip benefits us if key[j] is larger than key[i] and no larger than k; in such a case, j marks a position in the list that i would have to reach during an ordinary list search. Because the list is compact, we know that in any choice of j between 1 and n indexes some object in the list rather than a slot on the free list.

Instead of analyzing the performance of COMPACT-LIST-SEARCH directly, we shall analyze a related algorithm, COMPACT-LIST-SEARCH', which executes two separate loops. This algorithm takes an additional parameter t which determines an upper bound on the number of iterations of the first loop.

```
COMPACT-LIST-SEARCH(L, n, k)
  i = L
  for q = 1 to t
      j = RANDOM(1, n)
      if key[i] < key[j] and key[j] ≤ k
          i = j
          if key[i] == k
              return i
  while i ≠ ␀ and key[i] < k
      i = next[i]
  if i == ␀ or key[i] > k
      return ␀
  else
      return i
```

To compare the execution of the algorithms COMPACT-LIST-SEARCH(L, n, k) and COMPACT-LIST-SEARCH(L, n, k, t), assume that the sequence of integers returned by the calls of RANDOM(1, n) is the same for both algorithms.

a. Suppose that COMPACT-LIST-SEARCH(L, n, k) takes t iterations of the while loop of lines 2-8. Argue that COMPACT-LIST-SEARCH'(L, n, k, t) returns the same answer and that total number of iterations of both the for and while loops within COMPACT-LIST-SEARCH' is at least t.  

In the call COMPACT-LIST-SEARCH'(L, n, k, t), let Xt be the random variable that describes the distance in the linked list (that is, through the chain of next pointers) from position i in the desired key k after t iterations of the for loop of lines 2-7 have occurred.

b. Argue that the expected running time of COMPACT-LIST-SEARCH'(L, n, k, t) is O(t+E[Xt]).  

c. Show that E[Xt]≤∑nr=1(1−r/n)t. (Hint: Use equation (C.25).)

d. Show that ∑n−1r=0rt≤nt+1/(t+1).

e. Prove that E[Xt]≤n/(t+1).

f. Show that COMPACT-LIST-SEARCH'(L, n, k, t) runs in O(t+n/t) expected time.

g. Conclude that COMPACT-LIST-SEARCH runs in O(n√) expected time.

h. Why do we assume that all keys are distinct in COMPACT-LIST-SEARCH? Argue that random skips do not necessarily help asymptotically when the list contains repeated key values.  

