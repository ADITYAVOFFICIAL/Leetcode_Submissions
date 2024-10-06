class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        # Split both sentences into words
        words1 = sentence1.split()
        words2 = sentence2.split()
        
        # Ensure words1 is the longer sentence
        if len(words1) < len(words2):
            words1, words2 = words2, words1
        
        # Two pointers: one from the start (i) and one from the end (j)
        i, j = 0, 0
        
        # Check for matching prefix
        while i < len(words2) and words1[i] == words2[i]:
            i += 1
        
        # Check for matching suffix
        while j < len(words2) - i and words1[-(j+1)] == words2[-(j+1)]:
            j += 1
        
        # The sentences are similar if all words from sentence2 are consumed
        return i + j >= len(words2)