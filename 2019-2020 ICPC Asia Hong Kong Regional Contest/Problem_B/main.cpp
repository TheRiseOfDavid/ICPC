#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

int main()
{
    int t ;
    cin >> t ;
    while(t--){
        int a , b , n ;
        cin >> n ;
        if(n % 2)
            cout << "Alice\n" ;
        else
            cout << "Bob\n" ;
        for(int i = 1 ; i < n ; i++){
            cin >> a >> b ;
        }


    }
    return 0;
}
