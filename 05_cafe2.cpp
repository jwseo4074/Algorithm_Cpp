#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define B if (y2 == 1) boo = false ;
#define PB1 i_v.pb(y2);
#define PB2 r_v.pb(y2);
#define S sort(i_v.begin(),i_v.end());
#define C1 if (s < n+1) cout << a << " " << r_v.back()<< endl;
#define VS i_v.size()
#define M max_f(mvec2,mE,i_v)
using namespace std;
int max_f(vector <int> mv22, int max2, vector <int> inv2){
    int b;
    for (int j=0; j<inv2.size(); j++){
        if (mv22[j] == max2)    return j;
    }
}
int main() {
    bool boo = false;
    int n,k,p=0,s=0;
    cin >> n >> k;
    vector <int> v(1000000,0);
    vector <int> v2,i_v,r_v;
    int v2_m_v,v2_m_i,e_v;
    while(1){
       int a;
       cin >> a;
       p++;
       if (v[a]!=a) {
        v[a]=a;
        v2.pb(a);
         if ( p == 1 ) {
           i_v.pb(1);
           r_v.pb(1);
           i_v.pb(n+1);
           boo = false ;
           s++;
           C1 }
         else {
            if ( boo ){
                vector <int> mvec;
                vector <int> mvec2;
                for ( int k=0 ; k < VS-1 ; k++){
                    int x = i_v[k+1]-i_v[k] ;
                    mvec.pb(x);  }
                for ( int k=0 ; k<VS-1 ; k++){
                    int x = (i_v[k+1]-i_v[k]) / 2 ;
                    mvec2.pb(x);   }
                mvec.insert(mvec.begin(),i_v.front()-1);
                int y = (mvec.front() + mvec.back());
                int y3 = (mvec.front() + mvec.back())/2;
                mvec2.pb(y3);
                int mE = *max_element(mvec2.begin(), mvec2.end());
                int mE2 = *max_element(mvec.begin(), mvec.end());
                int y2;
                if ( (y3 == mE) && (M == mvec2.size()-1) )  {
                        if ( (i_v[VS-2] + y3) < n+1 ) y2 = i_v[VS-2] + y ;
                        else y2 = y3 - (n  - i_v[VS-2] ) ;
                    cout << "1" << endl;
                }
                else if (s==0)
                {
                    y2 = 1;
                    cout << "2" << endl;
                }
                else if( (y == mE2) && (M == 0) ) {
                    y2 = 1;
                    cout << "3" <<endl;
                }
                else {
                    y2 = i_v[M] + mE ;
                    cout << "4"  << endl;
                }
                s++;
                B PB1 PB2 S C1
            }
            else {
                vector <int> mvec2;
                int b,c ;
                for ( int k=0 ; k<VS-1 ; k++){
                    c = i_v[k+1]-i_v[k];
                    mvec2.pb(c); }
                int mE = *max_element(mvec2.begin(), mvec2.end());
                int y2 = i_v[M] + mE/2;
                s++;
                B PB1 PB2 S C1 }
        }
       }
       else {
         s--;
         v[a] = 0;
         int i_n = find(v2.begin(),v2.end(),a) - v2.begin();
         if (i_n == 0) boo = true;
         e_v = r_v[i_n];
         r_v.erase(r_v.begin() + i_n);
         v2.erase(remove(v2.begin(),v2.end(),a),v2.end());
         i_v.erase(remove(i_v.begin(),i_v.end(),e_v),i_v.end());    }
    if (p == k) break;
    }
    return 0;
}
