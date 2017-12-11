#弱智版
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        vert, level = 0, 0
        for i in range(len(moves)):
            if moves[i] == 'R':
                level += 1
            elif moves[i] == 'L':
                level -= 1
            elif moves[i] == 'U':
                vert += 1
            elif moves[i] == 'D':
                vert -= 1
            else:
                return False
            
        if level == 0 and vert == 0:
            return True
        else:
            return False

#算法上不是特别好，4次遍历了，虽然写起来很舒服
    def judgeCircle2(self, moves):
        return moves.count('L') == moves.count('R') and moves.count('U') == moves.count('D')    

#优化方案应该是构造了一个哈希表，都是欺负我对python库不熟悉啊，但是Counter好像不是哈希表
    def judgeCircle3(self, moves):
        c = collections.Counter(moves)
        return c['L'] == c['R'] and c['U'] == c['D']

#最佳，空间和时间都最佳
    def judgeCircle4(self, moves):
        direct = {'U': 1, 'D': -1, 'L': 1j, 'R': -1j}
        return 0 == sum(direct[m] for m in moves)