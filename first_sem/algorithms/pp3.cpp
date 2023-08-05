#include<bits/stdc++.h>
using namespace std;

int balancedSubstring(string s) {
  int res=0, sum=0;
  unordered_map<int, int> mp;
  mp[0]=-1;
  for(int i=0; i<s.length(); i++) {
    if(s[i]=='0') sum--;
    else sum++;
    if(mp.find(sum) != mp.end())
      res=max(res, i-mp[sum]);
    else
      mp[sum]=i;
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
    string s;
    getline(cin, s);
    cout << balancedSubstring(s);
    return 0;
}
