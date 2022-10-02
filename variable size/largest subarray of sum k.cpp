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
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            current_sum += nums[right];
            if (current_sum < sum) {
                right++;
            }
            else if (current_sum == sum) {
                max_arr = max(max_arr, right - left + 1);
                right++;
            }
            else {
                while (current_sum > sum) {
                    current_sum -= nums[left];
                    right++;
                }
                right++;
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
