typedef pair<int,int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        
        priority_queue<pi, vector<pi>,greater<pi>> pq;
        for(auto it:freq){
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
        
    }
};

