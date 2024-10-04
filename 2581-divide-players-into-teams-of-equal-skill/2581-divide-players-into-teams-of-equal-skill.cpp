class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        long long totalSkill = 0;
        int n = skill.size();
        
        // Calculate total skill
        for (int s : skill) {
            totalSkill += s;
        }
        
        // Check if the total skill can be evenly divided
        if (totalSkill % (n / 2) != 0) {
            return -1;
        }
        
        long long targetSkill = totalSkill / (n / 2);
        long long chemistrySum = 0;
        
        // Sort the skills array
        std::sort(skill.begin(), skill.end());
        
        int left = 0, right = n - 1;
        
        // Form pairs
        while (left < right) {
            if (skill[left] + skill[right] != targetSkill) {
                return -1; // Not possible to divide into teams with equal total skill
            }
            chemistrySum += static_cast<long long>(skill[left]) * skill[right];
            left++;
            right--;
        }
        
        return chemistrySum;
    }
};
