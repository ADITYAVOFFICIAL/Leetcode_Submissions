class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        // Ensure words1 is the longer sentence
        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }
        
        int i = 0, j = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        // Check for matching prefix
        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }
        
        // Check for matching suffix
        while (j < n2 - i && words1[n1 - j - 1] == words2[n2 - j - 1]) {
            j++;
        }
        
        // The sentences are similar if all words from the smaller sentence are covered
        return i + j >= n2;
    }

private:
    // Helper function to split the sentence into words
    vector<string> split(const string& sentence) {
        vector<string> words;
        istringstream stream(sentence);
        string word;
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }
};