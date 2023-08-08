#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr, int n, int k) {
    int profit=0;
    int max=INT_MIN;
    stack<int> st;
    for(int i=n-1; i>k; i--) {
        if(st.empty() || arr[st.top()] < arr[i]) {
            st.push(i);
        }
    }
    stack<int> temp=st;
    while(!temp.empty()) {
        for(int i=0; i<temp.top()-k; i++) {
            if(arr[temp.top()] - arr[i] > max) {
                max=arr[temp.top()] - arr[i];
            }
        }
        temp.pop();
    }
    return max;
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
    int res=maxProfit(arr, n, k);
    if(res < 0) cout << "Stock is bearish";
    else cout << res;
    return 0;
}