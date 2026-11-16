#include <vector>
#include <unordered_set>

#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){

            // assuming the difference of the two numbers exist in the array
            int diff = target - nums[i];
            // searching the 2nd element in the map
            if(mp.find(diff) != mp.end()){
                
                // return the index of the 1st element as the map is previous element of array
                return {mp[diff], i};
            };
            // insert the previous element and the index of it
            mp.insert({nums[i], i});
        };
        return {};
    };
};










//  I USED SET WHICH WAS INCORRECT IDEALLY SHOULD BE MAP

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {

//         unordered_set<int> s(nums.begin(), nums.end());
        

//         for (int a = 0; a < size(nums);){
//             auto it = s.find(target - nums[0]);
            
//             if (it != s.end()) {
//                 int id = distance(s.begin(),it);
             
//                 return {a, id-1};
//             }
//         }
//         return {0, 0};

//         // for( int i : s){
           
//         //     auto it = s.find(target - i);
//         //     cout << it;
            
//         // }
        
//     };
// };


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> test = {4,5,6};

    for (int i : sol.twoSum(test, 10)){
        cout << i;
    }
    return 0;
}
