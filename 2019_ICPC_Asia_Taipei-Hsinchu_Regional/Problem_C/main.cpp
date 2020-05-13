#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FB if(!flag) break

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int num[60] ;
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> num[i] ;
    }
    int flag = 1 , intMod ;

    for(int i = 0 ; i < n ; i++){
        for(int j = i +1  ; j < n ; j++ ){
            for(int k = 0 ; k < n ; k++){
                if( i == k || j == k)
                    continue ;
                intMod = abs(num[i] - num[j]) % num[k] ;
                if (intMod != 0 ){
                    flag = 0 ;

                    //debug
                    //cout << intMod << ' ' << num[i] << ' ' << num[j] << ' ' << num[k] << '\n' ;
                }

            }
            FB;
        }
        FB;
    }
    if(flag)
        cout << "yes" ;
    else
        cout << "no" ;

    return 0;
}
