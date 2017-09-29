# coding:utf-8

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) <= 1:
            return False
        #考虑下重复数字
        #省略了排序，非常赞
        bucks = {}
        for i in xrange(len(nums)):
            if nums[i] not in bucks:
                bucks[target - nums[i]] = i
            else:
                return [bucks[nums[i]], i]