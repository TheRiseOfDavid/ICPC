#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
vector<int> path[30] ;
deque<int> nodes ;

int N , n , p  ;

struct Node{
    int color[3] = {} ;
    int use = 0 ;
    void clear(){
        color[0] = 0 ;
        color[1] = 0 ;
        color[2] = 0 ;
        use = 0 ;
    }

}node[30];

int choose(int i , int k ){
    for(int j = 0 ; j < path[i].size() ; j++){
        if(!node[path[i][j]].use){
            nodes.push_back(path[i][j]);
            node[path[i][j]].use = 1 ;
        }

        if(node[path[i][j]].color[k])
            return 0 ;
    }
    return 1 ;
}

int check(int i ){
    for(int k = 0 ; k < 3 ; k++){
        if(node[i].color[k])
            continue ;
        if(choose(i,k)){
            node[i].color[k] = 1 ;
            return 1 ;
        }
    }
    return 0 ;
}

int BFS(){
    //node[0].color[0] = 1 ;
    nodes.push_back(0) ;
    node[0].use = 1 ;
    while(nodes.size()){
        if(!check(nodes.front()))
            return 0 ;
        nodes.pop_front();
    }
    return 1 ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int i , j ;
    cin >> N ;
    while(N--){
        cin >> n >> p ;

        //clear
        for(int i = 0 ; i < n ; i++){
            path[i].clear() ;
            node[i].clear() ;
        }
        nodes.clear() ;

        //bulid
        for(int k = 0 ; k < p ; k++){
            cin >> i >> j ;
            path[i].push_back(j) ;
            path[j].push_back(i) ;
        }

        if(BFS())
            cout << "Y" ;
        else
            cout << "N" ;
        cout << '\n' ;

        /*//debug
        for(int i = 0 ; i < n ; i++){
            cout << i << ' ' << node[i].color[0] << ' ' << node[i].color[1] << ' ' << node[i].color[2] << '\n' ;
        }
        */

    }
    return 0;
}
