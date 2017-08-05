#ifndef _HEAPSORT_H
#define _HEAPSORT_H
#include <vector>
using namespace std;
//堆排序 时间复杂度O(nlgn) 空间复杂度O(1)
//堆是一种数据结构，是一棵完全二叉树且满足性质：所有非叶子结点的值均不大于或均不小于其左、右孩子结点的值，用一维数组来表示堆
//调整堆不就是选择出待排序序列中的最大值吗？所以堆排序的本质和选择排序的本质是一样的。
//选择一个待排序序列中的最小（大）值，这就是选择排序的本质。

//调整堆，保持大顶堆的性质,参数i指向根结点
void maxHeap(vector<int>& nums, int len, int i) {
    int largest = 0, left = 0, right = 0;
    left = 2 * i + 1; 
    right = 2 * i + 2;
    if (left >= len)
        return;
    largest = left;
    //利用短路求值，看似会下标越界，但左边负责判断
    if (right < len && nums[right] > nums[left])
        largest = right;
    if (nums[i] < nums[largest]) {
        swap(nums[largest], nums[i]);
        //自上而下调整堆
        maxHeap(nums, len, largest);
    }
}

//建立堆
//关键，是从末尾有子节点的节点开始向顶点慢慢调整
void createHeap(vector<int>& nums, int len) {
    for (int i = (len - 1) * 0.5; i >= 0; --i) {
        maxHeap(nums, len, i);
    }
}

void heapSort(vector<int>& nums) {
    const int len = nums.size();
    createHeap(nums, len);
    for (int i = len - 1; i > 0; --i) {
        swap(nums[i], nums[0]);
        maxHeap(nums, i, 0);//第二个参数不能用len-1，则永远固定了长度
    }
}
//为什么堆排比快排慢
//在堆排里面有大量这种近乎无效的比较，因为被拿到堆顶的那个元素几乎肯定是很小的，而靠近堆顶的元素又几乎肯定是很大的，将一个很小的数和一个很大的数比较，结果几乎肯定是“小于”的，这就意味着问题的可能性只被排除掉了很小一部分。
//这就是为什么堆排比较慢（堆排虽然和快排一样复杂度都是O(NlogN)但堆排复杂度的常系数更大。
#endif