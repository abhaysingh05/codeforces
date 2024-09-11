#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isprime(ll n) {
    if (n <= 1) return 0;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll min(ll a, ll b) {
    return (a < b) ? a : b;
}

ll sum2n(ll n) {
    return (n * (n + 1)) / 2;
}

ll sumlr(ll l, ll r) {
    return ((l + r) * (r - l + 1)) / 2;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

bool issorted(ll arr[], ll n) {
    for (ll i = 1; i < n; i++) { // start from 1, not 0
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}
ll mod=1000000007;
void solve() {
    ll n;
    cin>>n;
    vector<vector<ll> > adj(n+1);
    ll c=n-1;
    while(c--)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string s;
    cin>>s;
    vector<ll> deg(n+1);
    for (ll i=1;i<=n;i++) deg[i]=adj[i].size();
    vector<ll> leaf;
    for (ll i=2;i<=n;i++) if (deg[i]==1) leaf.push_back(i);
    string t="a";
    t+=s;
    s=t;
    ll c0=0,c1=0,c2=0;
    for (auto p: leaf)
    {
        if (s[p]=='1') c1++;
        else if (s[p]=='0') c0++;
        else c2++;
    }
    ll score=0;
    if (s[1]=='1') score=c0;
    else if (s[1]=='0') score=c1;
    if (s[1]!='?')
    {
        score+=(c2+1)/2;
        cout<<score<<endl;
        return;
    }
    ll p=0;
    for (ll i=1;i<=n;i++) if (s[i]=='?') p++;
    p-=c2+1;
    if (c0==c1)
    {
        if (p&1) score++;
        score+=c1;
        score+=c2/2;
        cout<<score<<endl;
        return;
    }
    score=max(c0,c1);
    score+=c2/2;
    cout<<score<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}