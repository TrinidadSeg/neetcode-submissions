class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        for (const string& word: strs) {
            string s = word;
            sort(s.begin(), s.end());
            seen[s].push_back(word);
        }
        vector<vector<string>> ans;
        for (auto& pair: seen) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
