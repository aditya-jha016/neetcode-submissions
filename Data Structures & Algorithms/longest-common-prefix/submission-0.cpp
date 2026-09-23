class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string &a = strs[0];
        string &b = strs[strs.size()-1];

        int n = min(a.size(), b.size());
        int i = 0;

        while (i < n && a[i] == b[i]) {
            i++;
        }

        return a.substr(0, i);

        
    }
};