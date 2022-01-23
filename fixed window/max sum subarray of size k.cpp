class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int _max_sum = INT_MIN;
        int i = 0;
        int j = 0;
        int current_sum = 0;
        while (j < N){
            current_sum += Arr[j];
            if (j - i + 1 < K){
                j++;
            }
            else if (j - i + 1 == K){
                _max_sum = max(_max_sum, current_sum);
                current_sum -= Arr[i];
                i++;
                j++;
            }
        }
        return _max_sum;
        
    }
};
