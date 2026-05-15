class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        for (int i = 0; i < strs.size(); i++) {
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            seen[sortedWord].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto& pair: seen) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
