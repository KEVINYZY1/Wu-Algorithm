class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        res = 0
        for i in range(32):
            temp = num & 1
            if not temp:
                res += 1 << i
            
            num >>= 1
            if not num:
                break
                
        return res

class Solution2(object):
    def findComplement(self, num):
        i = 1
        while i <= num:
            i = i << 1
        return (i - 1) ^ num