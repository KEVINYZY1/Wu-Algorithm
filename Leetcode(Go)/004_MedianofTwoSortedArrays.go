package Leetcode

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(A), len(B)
	length := m + n
	if length%2 == 1 {
		return float64(findKth(A, m, B, n, length/2+1))
	} else {
		small := findKth(A, m, B, n, length/2)
		large := findKth(A, m, B, n, length/2+1)
		return float64(small+large) / 2
	}
}

func findKth(A []int, m int, B []int, n int, k int) int {
	if m > n {
		return findKth(B, n, A, m, k)
	}
	if m == 0 {
		return B[k-1]
	}
	if k == 1 {
		return min(A[0], B[0])
	}

	pa := min(k/2, m)
	pb := k - pa
	if A[pa-1] < B[pb-1] {// 注意这里格式
		return findKth(A[pa:], m-pa, B, n, k-pa)
	} else if A[pa-1] > B[pb-1] {
		return findKth(A, m, B[pb:], n-pb, k-pb)
	} else {
		return A[pa-1]
	}
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}
