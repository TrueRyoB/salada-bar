// SPDX-License-Identifier: CC0-1.0
//
// [English]
// To the extent possible under law, the author(s) have dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide. This software is distributed without any warranty.
// See <https://creativecommons.org/publicdomain/zero/1.0/> for details.
//
// [日本語]
// 法律上可能な範囲で、著作者はこのソフトウェアに関する著作権および
// 著作隣接権を含むすべての関連する権利を、全世界でパブリックドメインに
// 提供しています。本ソフトウェアは一切の保証なく配布されます。
// 自由にコピー・改変・再配布・商用利用できます（クレジット表記は不要です）。
// 詳細は <https://creativecommons.org/publicdomain/zero/1.0/deed.ja> を参照してください。
// ※ 英語の文面および CC0 1.0 の正式な条文（英語）が優先されます。

#include <iostream>
#include <bitset>
#include <random>
#include <chrono>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <ranges>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;

#include <atcoder/all>
using mint=atcoder::modint998244353;

ostream& operator<<(ostream& os,const mint& x){
	os<<x.val();
	return os;
}
istream& operator>>(istream& is,mint& x){
	int t;
	is>>t;
	x=t;
	return is;
}

template <typename S,typename T>
ostream& operator<<(ostream& os,const pair<S,T>& p);
template <typename S,typename T>
istream& operator>>(istream& is,pair<S,T>& p);
template <typename T,size_t n>
ostream& operator<<(ostream& os,const array<T,n>& arr);
template <typename T,size_t n>
istream& operator>>(istream& is,array<T,n>& arr);
template <typename T>
ostream& operator<<(ostream& os,const vector<T>& vec);
template <typename T>
istream& operator>>(istream& is,vector<T>& vec);

template <typename S,typename T>
ostream& operator<<(ostream& os,const pair<S,T>& p){
	os<<p.first<<" "<<p.second;
	return os;
}
template <typename S,typename T>
istream& operator>>(istream& is,pair<S,T>& p){
	is>>p.first>>p.second;
	return is;
}

template <typename T,size_t n>
ostream& operator<<(ostream& os,const array<T,n>& arr){
	for(int i=0;i<n;i++)os<<arr[i]<<(i+1==n?"":" ");
	return os;
}
template <typename T,size_t n>
istream& operator>>(istream& is,array<T,n>& arr){
	for(int i=0;i<n;i++)is>>arr[i];
	return is;
}
template <typename T>
ostream& operator<<(ostream& os,const vector<T>& vec){
	for(int i=0;i<(int)vec.size();i++)os<<vec[i]<<(i+1==(int)vec.size()?"":" ");
	return os;
}
template <typename T>
istream& operator>>(istream& is,vector<T>& vec){
	for(int i=0;i<(int)vec.size();i++)is>>vec[i];
	return is;
}

template<class... Vecs>
void input_vec(Vecs&... vs) {
    const auto n = get<0>(tie(vs...)).size();

    for (size_t i = 0; i < n; ++i)
        ((cin >> vs[i]), ...);
}

template <class... Vecs>
void output_vec(const Vecs&... vs) {
    const auto n = get<0>(tie(vs...)).size();

    for (size_t i = 0; i < n; ++i) {
        bool first = true;
        (((cout << (exchange(first, false) ? "" : " ") << vs[i])), ...);
        cout << endl;
    }
}

template <typename T>
vector<T> make_unique(vector<T> vec){
	ranges::sort(vec);
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	return vec;
}

vector<int> Iota(int n,int s=0){
	vector<int> res(n);
	iota(res.begin(),res.end(),s);
	return res;
}

vector<ll> Iotall(int n,ll s=0){
	vector<ll> res(n);
	iota(res.begin(),res.end(),s);
	return res;
}
void YESNO(bool f){
	if(f)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using vvvl=vector<vector<vector<ll>>>; 
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vvvi=vector<vector<vector<int>>>;
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	int ttt;
	cin>>ttt;
	while(ttt--){
		ll n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		vl cnt(4);
		for(int i=0;i<n;i++){
			cnt[(a[i]-'0')*2+(b[i]-'0')]++;
		}
		if(a==b){
			cout<<"Yes"<<endl;
			continue;
		}
		ll ans=cnt[0]+4*cnt[2]+3*cnt[1]-2;
		YESNO(ans+1<k);
	}
}



