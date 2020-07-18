#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

void dfs(int x , int k){
    if(!x)
        return ;
    x--;
    dfs(x/k , k );
    cout << 10 - k + x % k ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt","r",stdin);
#endif // LOCAL
    int t , x , k ;
    cin >> t ;
    while(t--){
        cin >> k >> x ;
        dfs(x,k);
        cout << '\n' ;
    }
    return 0;
}
