class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = cmp(x, 0)
        r = int (`s * x`[::-1])
        if r != x:
            return False
        else:
            return True