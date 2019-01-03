"""
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
"""

class Solution:
    def helper(self, S):
        stack = []
        for c in S:
            if c.isalpha():
                stack.append(c)
            elif c == "#":
                if (len(stack) != 0):
                    stack.pop()
        return ''.join(stack)
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        newS = self.helper(S)
        newT = self.helper(T)
        return newS == newT
