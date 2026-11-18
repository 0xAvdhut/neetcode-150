#include <string>
#include <vector>
#include <iostream>
using namespace std;


// TOOK HELP need to RESOLVE
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for(string str : strs){
            encoded.append( to_string(str.size()) +"#"+ str);
        }
        return encoded;

    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp;


        for(int pos = 0; pos < s.size();){

            int hashPos = s.find('#', pos);
            
            int len = stoi(s.substr(pos, hashPos - pos));
         
            result.push_back(s.substr(hashPos+1, len));
            pos = hashPos + len + 1 ;

        }
        return result;
        
    }
};

// 5#Hello5#World

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> vec = {"Hello","World"};
    vector<string> vec1;
    cout << sol.encode(vec);
    vec1 = sol.decode(sol.encode(vec));

    for(string str : vec){
        cout << str << "\n";
    }
    return 0;
}
