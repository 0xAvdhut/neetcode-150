#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

//here I used set instead of unordered later I changed it to unordered to save some resources as we dont care about the sorting
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return nums.size() - s.size() ;

    }
};

int main()
{
    Solution sol;
    vector<int> vec = {1,2,3,1,3,4};
    
    cout << sol.hasDuplicate(vec);
    return 0;
}









/*
// IDEAL Solution 

class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (seen.count(num)) {
                return true; 
            }
            // Otherwise, add it and keep going
            seen.insert(num);
        }
        return false;
    }
};
*/