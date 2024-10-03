#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<2;i++){
            ans.insert(ans.end(), nums.begin(), nums.end());
        }
        return ans;
    }
};