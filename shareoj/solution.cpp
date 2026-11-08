#include <bits/stdc++.h>
using namespace std;
#define ll long long

void won(bool win) {
  cout << (win ? "Yes" : "No") << '\n';
}

void solve() {
  int N, K; 
  cin>>N>>K;
  
  string A, B;
  cin>>A>>B;
  
  int cnt00=0, cnt01=0, cnt10=0, cnt11=0;
  
  for(int i=0; i<N; ++i) {
    if(A[i]=='0' && B[i]=='0') cnt00++;
    if(A[i]=='0' && B[i]=='1') cnt01++;
    if(A[i]=='1' && B[i]=='0') cnt10++;
    if(A[i]=='1' && B[i]=='1') cnt11++;
  }
  
  int rem=N-(cnt00+cnt11);
  
  if(rem==0) {
    won(true);
    return;
  }
  
  int sum=0;
  
  //「なにもしない」
  if(rem==N) {
    if(N==1) {
      won(K>1);
      return;
    }
    
    if(cnt01==rem) {
      //倍加RUさんで終焉
      if(rem==2) {
        won(K>2);
        return;
      }
      
      cnt00++, cnt11++;
      cnt01-=2;
      sum+=2;
    }
    else {
      cnt11++;
      cnt10--;
      sum++;
    } 
  }
  
  //ターンのminimax数
  sum+=2*cnt01 + 3*cnt10 + max(0, cnt01+cnt10-1) + (cnt01+cnt10>0 ? 1:0)*cnt00;
  won(sum<K);
}

int main() {
  int T; cin>>T;
  while(T-->0) solve();
}
