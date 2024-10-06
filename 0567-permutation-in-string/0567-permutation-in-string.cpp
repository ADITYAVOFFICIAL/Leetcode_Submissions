class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>freq,curr;
          if (s1.size() > s2.size()) return false;
        for(auto e:s1){
            freq[e]++;
        }
         int n=s1.size();
         int m=s2.size();
        for(int i=0;i<m;i++){
            curr[s2[i]]++;
              if (i >= n) {
                if (curr[s2[i - n]] == 1) {
                    curr.erase(s2[i - n]);
                } else {
                    curr[s2[i - n]]--;
                }
            }
            if(curr==freq)
            return true;
        }
        return false;
    }
};