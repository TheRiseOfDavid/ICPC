#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int m , n , flag=1;
int Maxn_city = 0 , Maxn_path = 0 ;
vector<int>tree[200020] ;
int city[200020] = {} ;
int visit[200020] = {} ;
vector<int> travel ;

void BFS_to_large_path(int root ){
    visit[root] = 1 ;
    travel.push_back(root);
    for(int i = 0 ; i < tree[root].size() ; i++){
        int node = tree[root][i] ;
        if(!visit[node]){
            BFS_to_large_path(node);
            travel.pop_back();
        }
    }

    //debug to check large path
    //cout << root << ' ' << travel.size() << ' ' << Maxn_path << ' ' << city[root] << '\n' ;

    visit[root] = 0 ;
    if(city[root] && travel.size() > Maxn_path){
        Maxn_city = travel[travel.size()/2];
        Maxn_path = travel.size();
    }
}

void BFS_to_other_path(int root ,int path){
    visit[root] = 1 ;
    for(int i = 0 ; i < tree[root].size() ; i++){
        int node = tree[root][i] ;
        if(!visit[node])
            BFS_to_other_path(node , path+1);
    }
    visit[root] = 0 ;

    //debug
    //cout << "city=" << root << " path= " << path << '\n' ;

    if(city[root] && path != Maxn_path / 2 +1)
        flag = 0 ;
}


int main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
#endif // LOCAL
    cin >> n >> m ;
    int a , b ;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> a >> b ;
        tree[a].push_back(b) ;
        tree[b].push_back(a) ;
    }

    for(int i = 0 ; i < m ; i++){
        cin >> a ;
        city[a] = 1 ;
    }
    BFS_to_large_path(a);

    // each visit element must be false
    //for(int i = 0 ; i <= n ; i++){
    //    cout << visit[i] << ' ';
    //}
    //cout << '\n' ;

    BFS_to_other_path(Maxn_city , 1 );
    if(flag)
        cout << "YES\n" << Maxn_city ;
    else
        cout << "NO" ;

    //debug
    //cout << "Maxn_path= " << Maxn_path << " Maxn_city= " << Maxn_city << '\n' ;
}
