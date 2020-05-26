    #include <iostream>
    #include <bits/stdc++.h>
    #define LOCAL
    #define ll long long
    #define Maxn -100000020
    #define Minn 100000020
    using namespace std;

    int main()
    {
    #ifdef LOCAL
        freopen("in1.txt" , "r" , stdin ) ;
    #endif
        ll n ;
        ll MaxX , MinX , MaxY , MinY ;
        MaxX = Maxn ;
        MinX = Minn ;
        MaxY = Maxn ;
        MinY = Minn ;
        ll a , b , c ;
        cin >> n ;
        while(n--){
            cin >> a >> b >> c ;
            MaxX = max(a + c , MaxX);
            MinX = min(a - c , MinX);
            MaxY = max(b + c , MaxY);
            MinY = min(b - c , MinY);
        }
        int x , y , h , dx , dy ;

        //debug
        //cout << MaxX << " " << MinX << " " << MaxY << " " << MinY << '\n' ;
        x = (MaxX + MinX+1) /2 ;
        y = (MaxY + MinY+1) /2 ;
        h = (max(MaxX - MinX , MaxY - MinY)+1)/2;
        cout << x << ' ' << y << ' ' << h ;
        return 0;
    }
