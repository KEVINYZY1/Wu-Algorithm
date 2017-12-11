# coding:utf-8
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        #使用列表作为栈
        stack = []
        dict = {"]":"[", "}":"{", ")":"("}
        for char in s:
            if char in dict.values(): #这样可以判断values
                stack.append(char)
            elif char in dict.keys(): #这样可以判断keys
                if stack == [] or dict[char] != stack.pop(): #列表做栈
                    return False
            else:
                return False
        return stack == []