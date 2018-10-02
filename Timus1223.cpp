/*
we get the following recurrance relation

for proof : http://www.cs.umd.edu/~gasarch/BLOGPAPERS/eggold.pdf (TODO for me)
ans(x, n) = ans(x - 1, n - 1) + ans(x - 1, n) + 1 for all x >= 1 and n >= 1

two conditions are there 
ans(x, n) >= k --(1)
ans(x, n) = summation i = 1 to n (xCi) --(2)

binary seach find the minimum value of x that satisfies (1) and (2)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int bin_coeff(int x, int n, int k){
	int sum = 0, term = 1;
	for(int i = 1; i <= n && sum < k; ++i){
		term = term * (x - i + 1);
		term /= i;
		sum += term;
	}
	return sum;
}

int solve(int egg, int floor){
	int lo = 1, hi = floor;
	int mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(bin_coeff(mid, egg, floor) < floor)
			lo = mid + 1;
		else{
			res = mid;
			hi = mid - 1;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int egg, floor;
	while(1){
		cin >> egg >> floor;
		if(egg == 0 && floor == 0)break;
		cout << solve(egg, floor) << endl;
	}


	return 0;
}
