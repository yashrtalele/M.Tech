#include<bits/stdc++.h>
using namespace std;

int binarySearch(int* s, vector<int>& arr, int start, int end, int target) {
    int potentialAns = -1;
    while(start <= end) {
        int mid = (start+end)/2;
        if(arr[s[mid]] < target) {
            potentialAns = mid;
            end = mid-1;
        } else {
            start = mid + 1;
        }
    }
    if(potentialAns == -1) return -1;
    return s[potentialAns];
}

vector<int> greaterThan(vector<int>& arr, int n) {
    vector<int> b(n);
    int* s=new int[n];
    int top=-1;
    for(int i=0; i<n; i++) {
        if(top==-1 || arr[i] < arr[s[top]]) {
            b[i] = -1;
            s[++top] = i;
        } else {
            b[i]=binarySearch(s, arr, 0, top, arr[i]);
        }
    }
    return b;
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