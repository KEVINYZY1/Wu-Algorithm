#自除数，一个数中的每一位上的数能够整除自身
class Solution(object):
    def selfDividingHelper(self, num):
        temp = num
        while temp:
            bit = temp % 10
            temp /= 10
            if bit == 0 or num % bit:
                return False
        
        return True
        
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        res = []
        for i in range(left, right + 1):
            #python这样调用内部成员函数
            if self.selfDividingHelper(i):
                res.append(i)
                
        return res