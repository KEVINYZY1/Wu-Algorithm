class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        index = 1
        for i in xrange(len(nums)):
            if i == 0:
                continue
            if nums[i] != nums[i - 1]:
                nums[index] = nums[i]
                index += 1
        
        return index