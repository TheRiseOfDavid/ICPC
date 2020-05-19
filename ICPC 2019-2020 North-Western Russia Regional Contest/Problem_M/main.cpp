#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int num[2020] = {} ;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t , n , ans, now  ;
    cin >> t ;
    while(t--){
        cin >> n ;
        unordered_map<int ,int > dict ;
        ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            cin >> num[i] ;
        }

        dict[num[n-1]] += 1 ;
        for(int j = n-2 ; j > 0 ; j--){
            for(int i = 0 ; i < j ; i++ ){
                now = 2 * num[j] - num[i] ;
                ans += dict[now];
            }
            dict[num[j]]+=1 ;
        }
        cout << ans << '\n' ;
    }

    return 0;
}
