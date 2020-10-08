#include <iostream>
#include <bits/stdc++.h>
#include <ext/rope>
#define LOCAL
#define MAXN 30
using namespace std;
using namespace __gnu_cxx ;
int a[MAXN] , b[MAXN] ;
int cntA , cntB , d ;
rope<char> strArr[500020];

int main()
{
//#ifdef LOCAL
//    freopen("in3.txt" , "r" , stdin );
//#endif // LOCAL
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string temA , temB ;
    getline(cin,temA);
    getline(cin,temB);
    rope<char> strA , strB ;
    strA.insert(0 , temA.c_str());
    strB.insert(0 , temB.c_str());

    cntA = cntB = 0 ;
    for(int i = 0 ; i < strA.length() ; i++ ){
        a[i] = strA.at(i) - '0' ;
        cntA += a[i] ;
    }
    for(int j = 0 ; j < strB.length() ; j++){
        b[j] = strB.at(j) - '0' ;
        cntB += b[j] ;
    }

    cin >> d ;
    int cnt = 0 ;
    //cout << strA << ' ' << strB << '\n' ;
    for(int i = 0 ; i < strA.length() ; i++){
        if(strA.at(i) != strB.at(i)){
            strA.replace(i,strB.at(i)) ;
            strArr[cnt++] = strA ;
            d-- ;
        }
    }
    if(d < 0 ){
        cout << "-1" << '\n';
        return 0 ;
    }


    while(d--){
        strA.replace(0,(strA.at(0) == '0' ? '1' : '0'));
        strArr[cnt++] = strA ;
    }
    if(strA != strB ){
        cout << "-1" << '\n' ;
        return 0 ;
    }

    for(int i = 0 ; i < cnt ; i++)
        cout << strArr[i] << '\n' ;

    return 0;
}
