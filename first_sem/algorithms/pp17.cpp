#include<bits/stdc++.h>
using namespace std;

int slidingWindow(vector<int>& arr, int n, int k) {
    deque<int> dq(k);
    unordered_map<int, int> mp;
    int h=0;
    int i=0;
    for(i=0; i<k; i++) {
        while(!dq.empty() and arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    while(i<arr.size()) {
        if(mp.find(dq.front()) != mp.end() || h==0)
            mp[h++]=dq.front();
        while(!dq.empty() and dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() and arr[i] >= arr[dq.back()]) 
            dq.pop_back();
        dq.push_back(i);
        i++;
    }
    mp[h]=dq.front();
    int max=INT_MIN;
    for(int i=0; i<=h; i++) {
        for(int j=i; j<mp[i]-k+1; j++) {
            if(arr[mp[i]]-arr[j] > max)
            max=arr[mp[i]] - arr[j];
        }
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
    cout << slidingWindow(arr, n, k);
    return 0;
}