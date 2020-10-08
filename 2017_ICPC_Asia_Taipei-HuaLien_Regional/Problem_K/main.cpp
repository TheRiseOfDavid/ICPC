#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 30
using namespace std;
int path[MAXN][MAXN] = {} ;
int node[MAXN] = {} ;
int n , p , N ;

int DFS(int v){
    for(int i = 0 ; i < v ; i++){
        if(path[v][i] && node[v] == node[i])
            return false ;
    }

    if(n == v-1)
        return true ;

    for(int j = 0 ; j < 3 ; j++){
        node[v+1] = j ;
        if(DFS(v+1))
            return true ;
    }
    return false ;

}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int _i , _j ;
    cin >> N ;
    while(N--){
        cin >> n >> p ;
        //clear
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                path[i][j] = 0 ;
        }

        for(int i = 0 ; i < p ; i++ ){
            cin >> _i >> _j ;
            path[_i][_j] = 1 ;
            path[_j][_i] = 1 ;
        }
        if(DFS(0))
            cout << "Y" ;
        else
            cout << "N" ;
        cout << '\n' ;
    }
    return 0;
}
