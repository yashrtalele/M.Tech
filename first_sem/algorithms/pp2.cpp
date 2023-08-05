/*
  2. Given a binary string of length n, design a linear time algorithm to compute the length of the largest 
  dense sub-string of the given string.
*/
#include<bits/stdc++.h>
using namespace std;

int largestDense(string s) {
  int sum=0, k=0, curr_len=0;
  unordered_map<int, int> prevSum;
  for(int i=0; i<s.length(); i++) {
    if(s[i]=='1') sum++;
    else sum--;
    if(sum > 0) 
      k=i+1;
    else if(sum <= 0) {
      if(prevSum.find(sum-1) != prevSum.end()) {
        curr_len=i-prevSum[sum-1];
        k=max(curr_len, k);
      }
    }
    if(prevSum.find(sum) == prevSum.end()) {
      prevSum[sum]=i;
    }
  }
  return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    cout << largestDense(s) << endl;
    return 0;
}
