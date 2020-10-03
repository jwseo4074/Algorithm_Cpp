#include <iostream>
#include <vector>
#define pb push_back
#define vxy11(t,r) vxy = nxy[t+1][r]-nxy[t][r]
#define vxy12(t,r) vxy = nxy[t][r]-nxy[t+1][r]
#define vxy13(t,r) vxy = nxy[t][0]-nxy[r][0]
#define vxy14(t,r) vxy = nxy[t][1]-nxy[r][1]
#define FOR(l,t,r) for(int l=t;l<r;l++)

using namespace std;

int fx=0,fy=0,cnt=0,vxy = 0;
int a,b,c,i;
vector <int> v1,v2,v1x,v1y,v2x,v2y;

void func(){
    v1.pb(fx);
    v2.pb(fy);
    cnt++;
}
void fxy(int x){
        switch (x){
        case 1:
            FOR(j,0,vxy){
                fx++;
                func();
            }  break;
        case 2:
            FOR(j,0,vxy){
                fx--;
                func();
            }  break;
        case 3:
            FOR(j,0,vxy){
                fy++;
                func();
            }  break;
        case 4:
            FOR(j,0,vxy){
                fy--;
                func();
            }  break;
    }
}
int main()
{
    int nK;
    cin >> nK;
    int nxy[nK][2];
    FOR(j,0,nK){
        cin >> nxy[j][0];
        cin >> nxy[j][1];
    }
    fx = nxy[0][0]; fy = nxy[0][1];
    v1.pb(fx);  v2.pb(fy);
    int r;
    cin >> r;
    for(i=0;i<nK;i++){
        if(nxy[i][0] == nxy[i+1][0]){
            if (nxy[i][1] < nxy[i+1][1] ){
                vxy11(i,1);
                fxy(3);
            }
            else{
                vxy12(i,1);
                fxy(4);
            }
        }
        if(nxy[i][1] == nxy[i+1][1]){
            if (nxy[i][0] < nxy[i+1][0] ){
                vxy11(i,0);
                fxy(1);
            }
            else{
                vxy12(i,0);
                fxy(2);
            }
        }
        if ( i == nK/2 - 2 ){
            a = cnt /2;
            c = cnt;
        }
        if ( i == nK-1)
            b = c + ((cnt - c) / 2 );
    }
    i--;
    if(nxy[i][0] == nxy[0][0]){
            if (nxy[i][1] < nxy[0][1] ){
                vxy14(0,i);
                fxy(3);
            }
            else{
                vxy14(i,0);
                fxy(4);
            }
    }
    if(nxy[i][1] == nxy[0][1]){
        if (nxy[i][0] < nxy[0][0] ){
            vxy13(0,i);
            fxy(1);
        }
        else{
            vxy13(i,0);
            fxy(2);
        }
    }
    if ( i == nK-1){
        b = c + ((cnt - c) / 2 );
    }
    FOR(i,0,a){
            v1x.pb(v1[i]);
            v1y.pb(v2[i]);
        }
    for(i=a; i>0; i--){
        v1x.pb(v1[i]);
        v1y.pb(v2[i]);
    }
    if(a%2 != 0){
        for(i=c;i>a+1;i--){
            v2x.pb(v1[i]);
            v2y.pb(v2[i]);
        }
        FOR(i,a+1,c){
            v2x.pb(v1[i]);
            v2y.pb(v2[i]);
        }
    }
    else {
        for(i=c;i>a;i--){
            v2x.pb(v1[i]);
            v2y.pb(v2[i]);
        }
        FOR(i,a,c){
            v2x.pb(v1[i]);
            v2y.pb(v2[i]);
        }
    }
    if (c % 2 != 0){
        for(i=cnt;i>b+1;i--){
            v1x.pb(v1[i]);
            v1y.pb(v2[i]);
        }
        FOR(i,b+1,cnt){
            v1x.pb(v1[i]);
            v1y.pb(v2[i]);
        }
    }
    else{
        for(i=cnt;i>b;i--){
            v1x.pb(v1[i]);
            v1y.pb(v2[i]);
        }
        FOR(i,b,cnt){
            v1x.pb(v1[i]);
            v1y.pb(v2[i]);
        }
    }
    FOR(i,c,b){
            v2x.pb(v1[i]);
            v2y.pb(v2[i]);
        }
    for(i=b;i>c;i--){
            v2x.pb(v1[i]);
            v2y.pb(v2[i]);
    }
    if ( r > cnt-1 ){
        r = r % cnt - 1 ;
    }
    cout << v1x[r] << " " << v1y[r] << endl;
    cout << v2x[r] << " " << v2y[r] << endl;
}
