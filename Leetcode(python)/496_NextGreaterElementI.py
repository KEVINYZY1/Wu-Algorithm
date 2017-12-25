#要求将数组2对应数组1中元素略大的数找出来
#关键在于数组1是数组2的子集，采用栈配合哈希表的方式来做，其实就是空间换时间
class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        stack = []
        res = []
        dicts = {}
        for item in nums:
            while len(stack) and stack[-1] < item:
                dicts[stack.pop()] = item
            stack.append(item)
            
        for item in findNums:
            res.append(dicts.get(item, -1))#get接口
            
        return res