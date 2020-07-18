#include <bits/stdc++.h>
#define MAXN 2020
#define LOCAL
using namespace std ;
int arr[MAXN] = {} ;

int main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int t , k , l ;
    cin >> t ;
    while(t--){
        cin >> k >> l ;
        arr[1] = -1 ;
        if(l >= 2000){
            cout << -1 << '\n' ;
            continue ;
        }

        fill(arr+2 , arr+2000 , (1999 + k) / 1998) ;
        arr[1999] += (1999 + k ) % 1998 ;

        cout << 1999 << '\n' ;
        for(int i = 1 ; i <= 1999 ; i++){
            cout << arr[i] << ' ' ;
        }
        cout << '\n' ;
    }
}
