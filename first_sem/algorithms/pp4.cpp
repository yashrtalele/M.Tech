#include<bits/stdc++.h>
using namespace std;

int computeK(string s) {
  int slow=0, fast=s.length()-1, count=0;
  while(slow<=fast) {
    if(s[slow]=='0') {
      if(s[fast]=='1') {
        count++;
        slow++; fast--;
      } else {
        fast--;
      }
    } else {
      slow++;
    }
  }
  return count ? slow : -1;
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
    cout << computeK(s);
    return 0;
}
