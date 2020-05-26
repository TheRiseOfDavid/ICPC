#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int arr[200020] = {} ;
int save[1000200] = {} ;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , sum =0 , Mv = 0 ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){ //cin array
        cin >> arr[i] ;
        sum += arr[i] ;
        arr[i] = sum ;
        Mv = max(Mv, arr[i] - arr[i-1]);
    }

    memset(save , -1 , sizeof(save));
    int seaT , t , seaN , index ;
    cin >> seaN ;
    for(int i = 0 ; i < seaN ; i++){
        cin >> t ;
        seaT = t ;
        sum = 0 ;
        index = 0 ;
        int flag = 0; //flag = 1 non-impossible flag2 = impossible

        if(save[t] != -1)
            flag = 1 ;

        if(Mv > t)
            flag = 2 ;

        while(flag==0){
            index = upper_bound(arr+index , arr+n , seaT )-arr; // 透過 index 限定區間
            //debug
            //cout << "seaT=" << " " << seaT << " value=" << arr[index-1] << '\n' ;

            if(index == n){ // index成功跑至最後位置，即沒有右子樹
                flag = 1;
                save[t] = ++sum ;
                break;
            }
            seaT = arr[index-1] + t ;
            sum++ ;
        }
        if(flag == 2 || save[t] == 0 )
            cout << "Impossible" ;
        else{
            cout << save[t] ;

        }
        cout << '\n' ;
    }



    return 0;
}
