# Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        stack = []
        stack.append(n - 1)

        for i in range( n - 2, -1, -1):
            num = temperatures[i]
            while stack and num >= temperatures[stack[-1]] :
                stack.pop()
            if not stack:
                stack.append(i)
                continue
            j = stack[-1]
            res[i] = j - i
            stack.append(i)
        return res

