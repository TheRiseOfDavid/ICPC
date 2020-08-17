#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int path[30][30] = {} ;
int node[30] = {} ;
int s , t , e , a , b  ;

int DFS(int c ){
    for(int i = 0 ; i < (s+t) ; i++){
        if(path[c][i]){
            if(!node[i]){
                node[i] = 3 - node[c] ;
                path[i][c] = 0 ;
                path[c][i] = 0 ;
                DFS(i);
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    while(cin >> s){
        if(!s)
            return 0 ;

        cin >> t >> e ;

        //clear
        for(int i = 0 ; i < (s+t) ; i++){
            node[i] = 0 ;
        }

        //bulid
        for(int i = 0 ; i < e ; i++){
            cin >> a >> b ;
            path[a][b+s] = 1 ;
            path[b+s][a] = 1 ;
        }

        int record[3] = {} ;
        for(int i = 0 ; i < (s+t) ; i++){
            if(!node[i]){
                node[i] = 1 ;
                DFS(i);
            }
            record[node[i]]++;
        }

        /*//debug
        for(int i = 0 ; i < (s+t) ; i++)
            cout << node[i] << ' ' ;
        cout << '\n' ;
        */

        cout << min(record[1] , record[2]) << '\n' ;

    }

    return 0;
}
