class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle in haystack:
            res=haystack.index(needle)
            return res
        else:
            return -1
        