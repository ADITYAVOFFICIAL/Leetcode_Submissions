class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        string result;
        for(int i=0;i<max(len1,len2);i++){
            if(i<len1){
               result+=word1[i];
            }
             if(i<len2){
               result+=word2[i];
            }
        }
        return result;
    }
};