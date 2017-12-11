class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        s1 = set("qwertyuiop")
        s2 = set("asdfghjkl")
        s3 = set("zxcvbnm")
        ans = []
        for word in words:
            t = set(word.lower())
            if s1 & t == t:
                ans.append(word)
            if s2 & t == t:
                ans.append(word)
            if s3 & t == t:
                ans.append(word)
        return ans