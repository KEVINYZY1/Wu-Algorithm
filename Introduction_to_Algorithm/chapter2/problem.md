#chapter2

## 思考题
###Problems 1
####Q 归并排序结合插入排序
Although merge sort runs in Θ(n lg n) worst-case time and insertion sort runs in Θ(n^2) worst- case time, the constant factors in insertion sort make it faster for small n. Thus, it makes sense to use insertion sort within merge sort when subproblems become sufficiently small. Consider a modification to merge sort in which n/k sublists of length k are sorted using insertion sort and then merged using the standard merging mechanism, where k is a value to be determined.

a. Show that the n/k sublists, each of length k, can be sorted by insertion sort in Θ(nk) worst-case time.

b. Show that the sublists can be merged in Θ(n lg (n/k) worst-case time.

c. Given that the modified algorithm runs in Θ(nk + n lg (n/k)) worst-case time, what is the largest asymptotic (Θnotation) value of k as a function of n for which the modified algorithm has the same asymptotic running time as standard merge sort?

d. How should k be chosen in practice?  
####A  
* a. 每个长度为k的数组采用插入排序，所需时间为Θ(k<sup>2</sup>)，一共有n/k个这样的数组，故总时间为Θ(nk)
* b. 每一层需要线性时间来合并，而一共有lgn/k层
* c. 修改后算法的渐进运行时间为Θ(nlg(n/k)+nk)，要求	Θ(nlg(n/k)+nk)=Θ(nlgn)，则要么Θ(nk) = Θ(nlgn)，要么是Θ(nlg(n/k)) = Θ(nlgn)。后者不成立，故k=lgn
* d. 由书中已知n>43时候，归并排序才优于插入排序，那么k一般取小于40，并且尽量为lgn  
  
###Problems 2
####Q 冒泡排序
Bubblesort is a popular sorting algorithm. It works by repeatedly swapping adjacent elements that are out of order.  
####A 
冒泡排序C++实现代码  [BubbleSort](https://github.com/swananan/Wu-Algorithm.git/Data_Structures_and_Algorithms/Sort/bubblesort.h)  
 
* a. 证明冒泡排序输出结果正确，我们需要确定输出数组是按升序排序，并且数组中的元素还是原来输入数组的元素
* b. 按照书上循环不变式证明的三个步骤来即可
* c. 每次循环前，A[1,i-1]是排序好的数组，并且小于A[i...]中元素，证明略
* d. 冒泡排序最坏情况时间复杂度Θ(n<sup>2</sup>)，**与插入排序相比，冒泡排序要更慢一些，因为有很多交换操作**  

###Problems 3
####Q 霍顿法则

Correctness of Horner's rule（见书上）
####A 

* a. Θ(n)
* b.    
朴素多项式求值算法伪代码

```  
y=0
for i=0 to n
	m=1
	for k=1 to i
		m=m*x
	y=y+A[i]*m
```  
这里每次要多求一个x的幂次方，时间复杂度为Θ(n<sup>2</sup>) 比起霍纳算法要慢很多

* c. 略
* d. 略  

###Problems 4
####Q 逆序对 
Let A[1..n] be an array of n distinct numbers. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A.

a. List the five inversions of the array 2, 3, 8, 6, 1.

b. What array with elements from the set {1, 2, . . . , n} has the most inversions? How many does it have?

c. What is the relationship between the running time of insertion sort and the number of inversions in the input array? Justify your answer.

d. Give an algorithm that determines the number of inversions in any permutation on n elements in Θ(n lg n) worst-case time. (Hint: Modify merge sort.)
####A 
* a. (2,1) (3,1) (8,6) (8,1) (8,1)
* b. (n,n-1,...1)这样逆序排放的数组具有最多的逆序对。 一共有（n-1)*n/2个逆序对
* c. 逆序对越多，插入排序运行时间越长。因为每一对逆序对，在插入排序中，都要多交换一次。
* d.   

```cpp
//求数组中逆序对数量
//由于要求了时间复杂度Θ(nlgn)，故不能用双重循环暴力求解的方法
//利用归并排序的算法，因为归并排序的交换次数就是这个数组的逆序对个数
static int count =0;
void combineArray(vector<int>&nums,int start,int mid,int end){
    vector<int>temp(end+1-start,0);
    int i=start,m=mid;
    int j=mid+1,n=end;
    int k=0;
    while(i<=m&&j<=n){
        if(nums[i]>nums[j]){
            temp[k++]=nums[j++];
//最关键一步，i注定比j小，则nums[i]>nums[j]，那i到mid之间的元素肯定都可以和nums[j]形成逆序对
            count+=mid-i+1;
        }
        else if(nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        }
    }
    while(i<=m){
        temp[k++]=nums[i++];
    }
    while(j<=n){
        temp[k++]=nums[j++];
    }
    for(int d=0;d<k;++d){
        nums[start+d]=temp[d];
    }
}
void mergeSort(vector<int>&nums,int start,int end){
    int mid=start+(end-start)/2;
    if(start<end){
        mergeSort(nums, start, mid);
        mergeSort(nums,mid+1,end);
        combineArray(nums, start, mid, end);
    }
    
}
void mergeSort(vector<int>&nums){
    const int len=nums.size();
    mergeSort(nums,0,len-1);
}
```