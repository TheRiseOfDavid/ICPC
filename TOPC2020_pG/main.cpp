#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
int n , m ;
unordered_map<int,int> ma[MAXN];

void sea(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(ma[i][j] == 0){
                ma[i][j] = -2 ;
                ma[i-1][j] = (ma[i-1][j]==0?-3:ma[i-1][j]) ;
                ma[i+1][j] = (ma[i+1][j]==0?-3:ma[i+1][j]) ;
                ma[i][j-1] = (ma[i][j-1]==0?-3:ma[i][j-1]) ;
                ma[i][j+1] = (ma[i][j+1]==0?-3:ma[i][j+1]) ;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(ma[i][j] == -1 ) cout << '*' ;
            else if (ma[i][j] == -2) cout << 'C' ;
            else if (ma[i][j] == -3 )cout << '.' ;
        }
        cout << '\n' ;
    }

}

int main()
{
//#ifdef LOCAL
//    freopen("in2.txt" , "r" , stdin );
//#endif // LOCAL
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m ;
    string strA ;
    for(int i = 0 ; i <= n ; i++){
        ma[i][0] = -1 ;
        ma[i][m+1] = -1 ;
    }
    for(int j = 0 ; j <= m ; j++){
        ma[0][j] = -1 ;
        ma[n+1][j] = -1 ;
    }

    for(int i = 1 ; i <= n ; i++){
        cin >> strA ;
        for(int j = 1 ; j <= m ; j++){
            if(strA[j-1] == '*') ma[i][j] = -1 ;
        }
    }

    sea();

    return 0;
}
