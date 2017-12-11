#排序
class Solution1(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(sorted(nums)[::2])

#因为输入数组中数字的范围在-10000~100000之间，所以可以使用类似计数排序
#使用哈希表，来把数组排序起来，再便利一遍，取出第二个数
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hashs = [0] * 20001 #python 给列表申请大空间的方法
        for x in nums:
            hashs[x + 10000] += 1
        sums, adjust = 0, False
        for idx, freq in enumerate(hashs):
            if freq:
                freq = freq - 1 if adjust else freq
                if freq & 1:
                    sums += ((freq // 2) + 1) * (idx - 10000)
                    adjust = True
                else:
                    sums += ((freq // 2)) * (idx - 10000)
                    adjust = False
        return sums
