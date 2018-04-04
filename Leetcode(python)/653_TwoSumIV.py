class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        res = False
        s = set()
        def dfs(root):
            if not root:
                return
            if (k - root.val) in s:
                nonlocal res#python3的新特性，这样就会往上层寻找res变量了
                res = True#这里不是使用了上一层函数的res，而是创建了一个res的局部变量
                return
            s.add(root.val)
            dfs(root.left)
            dfs(root.right)
            
        dfs(root)
        return res