#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>


using namespace std;
class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      // Map the frequency string signature to a list of original strings
        unordered_map<string, vector<string>> anagramGroups;
        
        for (string s : strs) {
            // Step 1: Count character frequencies in O(K) time
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // Step 2: Convert the frequency array into a string signature
            // Example: 1 'a', 0 'b', 2 'c' becomes "1#0#2#..."
            string signature = "";
            for (int i = 0; i < 26; i++) {
                signature += to_string(count[i]) + "#";
            }
            
            // Step 3: Group the string using this O(K) generated signature
            anagramGroups[signature].push_back(s);
        }
        
        // Transfer the grouped vectors to the final result
        vector<vector<string>> result;
        for (auto const& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> test = {"act","pots","tops","cat","stop","hat"};
    sol.groupAnagrams(test);
    return 0;
}

