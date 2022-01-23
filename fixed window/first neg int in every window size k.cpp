vector<long long> printFirstNegativeInteger(long long int A[],
    long long int N, long long int K) {
    queue<long long int> q;
    vector<long long int> first_neg;
    long long int i = 0;
    long long int j = 0;
    while (j < N) {
        if (A[j] < 0) {
            q.push(j);
        }
        if (j - i + 1 < K) {
            j++;
        }
        else if (j - i + 1 == K) {
            long long temp = 0;
            if (q.size() > 0) {
                temp = A[q.front()];
            }
            first_neg.push_back(temp);
            i++;
            j++;
        }
        //remove front element if it's out of window size k
        if (q.size() > 0 and q.front() < i) {
            q.pop();
        }
    }
    return first_neg;
}
