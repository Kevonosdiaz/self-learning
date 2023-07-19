class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        if not bool(word1):
            return word2
        elif not bool(word2):
            return word1
        return word1[0] + word2[0] + self.mergeAlternately(word1[1:], word2[1:])
