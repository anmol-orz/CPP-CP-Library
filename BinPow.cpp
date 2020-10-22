#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

ll power(ll x, ll y, ll p = LLONG_MAX)
{
    // re x^y if p not specified else (x^y)%p
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    if (p == LLONG_MAX)
        return res % p;
    else
        return (res + p) % p;
}

int main()
{
    cout << power(34, 634, mod);
}
