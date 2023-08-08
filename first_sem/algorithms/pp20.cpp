#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int> arr, int n, int k) {
    int csum=arr[0], length=0, temp=0, exactK=0, ans=INT_MIN;
    int* maxSum=new int[n];
    int* lenSum=new int[n];
    maxSum[0]=csum;
    for(int i=1; i<n; i++) {
        if(csum > 0) {
            csum+=arr[i];
            temp++;
        }
        else {
            csum=arr[i];
            lenSum[i]=temp;
            temp=0;
        }
        maxSum[i]=csum;
    }
    for(int i=0; i<k; i++) {
        exactK+=arr[i];
    }
    if(exactK > ans)
        ans=exactK;
    for(int i=k; i<n; i++) {
        exactK = exactK+arr[i]-arr[i-k];
        if(exactK > ans) {
            ans=exactK;
            if(length < k) {
                length=k;
            }
        }
        int moreThanK = maxSum[i-k] + exactK;
        if(moreThanK > ans) {
            ans=moreThanK;
            length=lenSum[i-k]+k;
        }
    }
    return length;
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
    cout << maximumSumSubarray(arr, n, k);
    return 0;
}