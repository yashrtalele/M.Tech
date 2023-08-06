#include<bits/stdc++.h>
using namespace std;

vector<int> slidingWindow(vector<int>& arr, int n, int k) {
    vector<int> vec;
        deque<int> dq(k);
        int i=0;
        for(i=0; i<k; i++) {
            while(!dq.empty() and arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        while(i<arr.size()) {
            vec.push_back(arr[dq.front()]);
            while(!dq.empty() and dq.front() <= i-k)
                dq.pop_front();
            while(!dq.empty() and arr[i] >= arr[dq.back()]) 
                dq.pop_back();
            dq.push_back(i);
            i++;
        }
        vec.push_back(arr[dq.front()]);
        return vec;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> k;
    vector<int> res=slidingWindow(arr, n, k);
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}