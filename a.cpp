#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a; i <=b; i++)
#define for_e(i, u) for(int i = firstE[u]; i; i=e[i].next)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define QWQ(x, y) cout<<#x<<": "<<(x)<<"  "<<#y<<": "<<(y)<<endl, exit(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5, M = 1e5+5;
const ll INF = 1e9, mod = 998244353;

int n, m;

int a[N];
ll pw[55];

ll qpow(ll a, ll b){
    a %= mod;
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod; b >>= 1;
    }
    return res;
}
void solve(){
    ll x, y; cin>>x>>y>>n;
    REP(i, 1, 50) pw[i] = qpow(i, n);

    ll k = y/x, ans = 1;
    for(int i=2; i*i <= k; ++i){
        if(k%i == 0){
            int c = 0;
            while(k%i == 0){
                ++c;
                k /= i;
            } ++c;
            ans = (ans * (pw[c] - pw[c-1]*2 + pw[c-2])%mod)%mod;
        }
    }
    if(k > 1) ans = (ans * (pw[2] - pw[1]*2 + pw[0])%mod)%mod;
    cout<<(ans%mod + mod)%mod<<endl;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}