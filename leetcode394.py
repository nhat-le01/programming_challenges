"""
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
"""
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        for e in s:
            if e != "]":
                stack.append(e)
            else:
                a = ""
                while (len(stack) != 0 and stack[-1] != "["):
                    a = a + stack.pop()
                stack.pop()
                mul = ""
                while (len(stack) != 0 and stack[-1].isdigit()):
                    mul = mul + stack.pop()
                mul = mul[::-1]
                print(mul)
                a = a * int(mul)
                for c in a[::-1]:
                    stack.append(c)
        result = ""
        while (len(stack) != 0) :
            result  = result + stack.pop()
        return result[::-1]
                
                
                      
        
