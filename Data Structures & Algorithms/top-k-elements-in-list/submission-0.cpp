class Solution {
public:
    vector<pair<int,int>> sortCount(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }

        vector<pair<int,int>> p;
        for(auto it : freq){
            p.push_back({it.first, it.second});
        }

        sort(p.begin(), p.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        });

        return p;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<pair<int,int>> p = sortCount(nums); 
        
        vector<int> result;
        
        for(int i = 0; i < k; i++){
            result.push_back(p[i].first);
        }

        return result;
    }
};