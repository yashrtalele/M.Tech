#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

vector<long long> greaterThan(vector<int>& arr, int n) {
    vector<long long> v(n, -1);
    long long mx=arr[n-1];
    for(int i=n-2; i>=0; i--) {
        if(arr[i+1] > arr[i])
            v[i]=arr[i+1];
        else {
            if(v[i+1] > arr[i])
                v[i] = v[i+1];
            else if(mx > arr[i]) {
                int k=i+1;
                while(arr[k] <= arr[i])
                    k++;
                v[i]=arr[k];
            }
            else
                v[i]=-1;
        }
        mx=max(mx, arr[i]);
    }
    return v;
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
    greaterThan(arr, n);
    vector<long long> res=greaterThan(arr, n);
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}