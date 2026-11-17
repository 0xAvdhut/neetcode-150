#include <vector>
#include <unordered_map>
#include <map>
#include<iostream>

using namespace std;


class Solution {
public:

    //ORIGINAL SOLUTION
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
       
        for(int i = 0; i < nums.size(); i++){
           mp[nums[i]]++;
        }

        vector<int> res = {};

        for(int i = 0; i < k; i++){
            //find max element of the map
            int max = 0;
            int max_el = 0;
            for(auto it : mp){
                
                if(it.second > max){
                    max = it.second;
                    max_el = it.first;
                }

            }   
            res.push_back(max_el);
            mp.erase(max_el);
            
        }
        return res;
    };


    /* 
    IDEAL SOLLUTION 


    MEMORY OPTIMISATION
    HG: res.reserve(k) fixing the vector size 
    */
    vector<int> IDEALtopKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for(int n : nums){
            count[n]++;
        }
        for(auto &it : count){
            freq[it.second].push_back(it.first);
        }
        vector<int> res; 

        
       
        // loop from highest freq till it res.size reaches k

        for(int i = freq.size()- 1; i > 0; --i ){
            for(int n : freq[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;

    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> vc = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    vector<int> ans = sol.topKFrequent(vc,2);
    for(int el : ans){
        cout << el;
    }
    return 0;
}
