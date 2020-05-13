#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    string strTemp , strAns[5] ;
    int index = 0 ;
    while(cin >> strTemp){
        if(strTemp == "bubble" || strTemp == "tapioka")
            continue ;
        strAns[index] = strTemp ;
        index++ ;
    }

    if(index == 0 ){
        cout << "nothing" ;
        return  0 ;
    }
    for(int i = 0 ; i < index -1 ; i++){
        cout << strAns[i] << ' ' ;
    }
    cout << strAns[index-1] ;


    return 0;
}
