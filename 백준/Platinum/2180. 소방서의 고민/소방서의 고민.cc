#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct G{
	ll a;
	ll b;

	ll f(ll x){
		return (((a*x)% 40'000)  + (b % 40'000))%40'000;
	}
};

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	vector<G>v;

	for (ll i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;

		if (a!=0||b!=0){
			v.push_back({a,b});
		}
	}

	sort(v.begin(), v.end(), [](auto i , auto j){
		return j.a * i.b < i.a * j.b;
	});


	ll t = 0;
	ll sum = 0;
	for (auto it : v){
		sum += it.f(t);
		sum %= 40'000;
		t += it.f(t);
	}
	cout << sum;


	return 0;
}