class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        res = []
        rows = len(nums)
        columns = len(nums[0])
        if rows * columns != r * c:
            return nums
        
        a = 0
        b = 0
        for i in range(r):
            temp = []
            for j in range(c):
                temp.append(nums[a][b])
                b += 1
                if b == columns:
                    b = 0
                    a += 1
            res.append(temp)
            
        return res

    class Solution2(object):
        def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        
        # check if nums is empty
        if not nums :
            return nums
            
        # calculate h(height) and w(width) of nums
        h = len(nums)
        w = len(nums[0])
        
        # check if the reshape operation is valid
        if h*w != r*c :
            return nums
            
        # build reshaped list
        res = [[0]*c for _ in xrange(r)] 
        
        # do reshape
        for i in xrange(h*w):
                res[i/c][i%c] = nums[i/w][i%w]
        return res