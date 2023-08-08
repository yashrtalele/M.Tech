#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarrayAtmostK(vector<int> arr, int n, int k) {
    int csum=0, mx=INT_MIN, count=0, start=0;
    for(int i=0; i<n; i++) {
        csum+=arr[i];
        mx=max(mx, csum);
        count++;
        if(count==k) {
            i=start++;
            csum=0;
            count=0;
        }
    }
    return mx;
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
    cout << maximumSumSubarrayAtmostK(arr, n, k);
    return 0;
}