#include <bits/stdc++.h>
#define LOCAL
#define SIZE 100010

using namespace std;
int pa[SIZE] , value[SIZE] , cnt=0 ;

int dfs(int k, int root ){
    cnt++ ;
    int temp ;
    pa[cnt] = root++ ;
    if(k <= 2){
        value[cnt] = 3 - k ;
        pa[cnt+1] = cnt ;
        value[++cnt] = 1 ;
        return 1 ;
    }
    temp = dfs(k/2,root) + dfs(2,root)  ;
    value[root] = temp + (k % 2 == 0);
    return temp ;
}

int main(){
    int k ;
    cin >> k ;
    dfs(k , 0);
    cout << cnt << '\n' ;
    for(int i = 2; i <= cnt ; i++)
        cout << pa[i] << ' ' ;
    cout << '\n' ;
    for(int i = 1 ; i <= cnt ; i++)
        cout << value[i] << ' ' ;


}
