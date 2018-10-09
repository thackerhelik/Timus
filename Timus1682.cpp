/*
Answer can never be -1. we can always have a cycle with atmost 2k + 1 numbers.
Now start simulating. 
Precalculation is done with 2k + 1 numbers 
we should be able to have the numbers of interest so vector<int>s[200005] stores all such numbers at i % k
while ss stores i*i % k
now for a particular number we put everything into set (we dont have multiple edges if both conditions are satisfied)
then dsu find if returns same for any 2 numbers in pair we know that cycle with current value will be formed and that is our answer
else unite every with value and continue
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 200005;

ll parent[MAXN];

void dsu_init(){
	for(int i = 0; i < MAXN; ++i)
		parent[i] = i;
}

ll dsu_find(ll x){
	return parent[x] = (parent[x] == x) ? x : dsu_find(parent[x]);
}

void dsu_union(ll p, ll q){
	parent[dsu_find(p)] = dsu_find(q);
}


vector<int>s[200005];
vector<int>ss[200005];

int main(){
	ll k;
	cin >> k;
	dsu_init();

	for(ll i = 1; i < MAXN; ++i){
		s[i%k].push_back(i);
		ss[(i*1LL*i)%k].push_back(i);
	}

	ll value = 2;

	while(1){


		ll find1 = (k - (value % k)) % k;
		ll find2 = (k - ((value*value) % k)) % k;
			
		set<ll>joinall;
		for(auto it: s[find2]){
			if(it >= value)break;
			joinall.insert(it);
		}
		
		 for(auto it: ss[find1]){
			if(it >= value)break;
			joinall.insert(it);
		}


		for(auto it: joinall){
			for(auto it2: joinall){
				if(it == it2)continue;
				if(dsu_find(it) == dsu_find(it2)){
					cout << value << endl;
					return 0;
				}
			}
		}

		for(auto it: joinall){
			dsu_union(it, value);
		}
		
		value++;	

	}
	return 0;
}
