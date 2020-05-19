#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
map<int ,int > dict ;
int num[2020] = {} ;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int t , n , temp , ans, now  ;
    cin >> t ;
    while(t--){
        cin >> n ;
        dict.clear();
        ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            cin >> temp ;
            dict[temp] += 1 ;
            num[i] = temp ;
        }

        for(int i = 0 ; i < n-2 ; i++){
            dict[num[i]] -= 1 ;
            for(int j = i+1; j < n-1 ; j++){
                dict[num[j]] -= 1 ;
                now = 2 * num[j] - num[i] ;
                ans += dict[now];
            }
            for(int j = i+1 ; j < n-1 ; j++)
                dict[num[j]] += 1 ;

            //debug
            //cout << "OK" << '\n' ;
        }
        cout << ans << '\n' ;
    }

    return 0;
}
