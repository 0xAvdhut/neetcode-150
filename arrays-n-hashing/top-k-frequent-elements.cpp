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


    // IDEAL SOLLUTION 

    vector<int> IDEALtopKFrequent(vector<int>& nums, int k) {
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
