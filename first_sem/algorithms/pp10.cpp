#include<bits/stdc++.h>
using namespace std;

vector<int> greaterThan(vector<int>& arr, int n) {
    int max=INT_MIN;
    vector<int> res(arr.size());
    stack<int> st;
    st.push(arr[0]);
    for(int i=1; i<n; i++) {
        if(st.empty()) {
            st.push(arr[i]);
            continue;
        }
        while(!st.empty() and arr[i] > st.top()) {
            res[st.top()]=arr[i];
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()) {
        res[st.top()]=-1;
        st.pop();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> res=greaterThan(arr, n);
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}