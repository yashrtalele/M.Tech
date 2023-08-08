#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int> arr, int n) {
    int sum = 0, smax = INT_MIN, start=0, end=0, s=0;
    for (int i=0; i<arr.size(); i++) {
        sum += arr[i];
        if(sum>=smax) {
            smax=sum;
            start=s;
            end=i;
        }
        if (sum < 0) {
            sum=0;
            s=i+1;
        }
    }
    return end-start+1;
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
    cout << maximumSumSubarray(arr, n);
    return 0;
}