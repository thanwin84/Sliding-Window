#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums, int sum) {
        int max_arr = 0;
        int current_sum = 0;
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            current_sum += nums[j];
            if (current_sum < sum) {
                j++;
            }
            else if (current_sum == sum) {
                max_arr = max(max_arr, j - i + 1);
                j++;
            }
            else {
                while (current_sum > sum) {
                    current_sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        return max_arr;
    }
};
int main() {
    vector<int> nums = {4, 1, 1, 1,  2, 3, 5};
    Solution obj;
    cout << obj.solve(nums, 5);
    return 0;
}
