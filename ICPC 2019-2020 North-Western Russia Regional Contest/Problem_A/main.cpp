#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin) ;
#endif // LOCAL
    int a , b , n ;
    cin >> a >> b >> n ;
    int ans , temp ;
    temp = (n-b) / (b-a) ;
    if( (n-b) % (b-a) != 0 )
        temp += 1 ;
    ans = temp * 2 + 1 ;
    cout << ans ;
    return 0;
}
