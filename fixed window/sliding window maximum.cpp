//time: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_array;
        deque<int> dq;
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 and nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        int i = 0;
        int j = k;
        while (j < nums.size()) {
            //front of dequeue will contain the max value and back will contain 
            //min value
            max_array.push_back(nums[dq.front()]);
            //push the max value at the front side always
            while (dq.size() > 0 and nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            //now slide the window
            i++;
            j++;
            //remove element which is out of window
            while (dq.size() > 0 and dq.front() < i) {
                dq.pop_front();
            }
            
        }
        max_array.push_back(nums[dq.front()]);
        return max_array;

    }
};
