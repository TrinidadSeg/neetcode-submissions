class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int n = s1.size();
        vector<int> f1(26,0);
        vector<int> window(26,0);
        for (char ch: s1) f1[ch-'a']++;
        int l = 0;
        int r = 0;
        for (int x: f1) cout<<x<<", ";
        cout<<'\n';
        for (r = 0; r < n; r++) window[s2[r]-'a']++;
        for (int y: window) cout<<y<<", ";
        cout<<"start "<<r<<endl;
        while (r < s2.size()) {
            if (check(f1, window)) return true;
            window[s2[l]-'a']--;
            window[s2[r]-'a']++;
            r++;
            l++;
            cout<<l<<" and "<< r << endl;
            for (int y: window) cout<<y<<", ";
            cout<<"\n";
        }
        if (check(f1, window)) return true;
        return false;
        
    }
    bool check(vector<int> p, vector<int> q) {
        for (int i = 0; i < 26; i++) if (p[i] != q[i]) return false;
        return true;
    }
};
