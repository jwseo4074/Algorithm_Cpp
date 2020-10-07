#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Polymulti{
private:
    int cnt;
    vector <long long> v = vector <long long> (10001,0);
    vector <long long> v2 = vector <long long> (10001,0);

public:
    Polymulti(){
        cnt = 0;
    }

     void getf(int n){
         int m;
         long long a;
         long long b;
         long long c;
         long long e;

         for(int j=0;j<n;j++){
            cin >> c >> e;
            if ( cnt == 0 ) {
                v[e] += c;
            }

            else {
                m = max_i();
                for(int j=m;j>-1;j--){
                    a = j+e;
                    b = v[j]*c;
                    v2[a] += b;
                }
            }
        }
        cnt++;
    }

     int max_i(){
        for ( int i=v.size()-1 ; i>-1 ; i--){
            if(v[i] != 0)   return i;
        }
        return 0;
     }

     void copy_v(){
        for ( int i=0; i<v.size()-1 ; i++)    v[i] = 0;
        v.assign(v2.begin(), v2.end());
        for ( int i=0; i<v2.size()-1 ; i++)   v2[i] = 0;
     }

     void printf(int m){
        cnt = 0;
        if (m==0 && v[m] == 0)  {
            cout << 1 << endl;
            cout << 0 << " " << 0;
        }
        else {
            for(int i=m ; i>-1 ; i--){
                if ( v[i] != 0 ) cnt++;
            }
            cout << cnt << endl;
            for(int i=m ; i>-1 ; i--){
                if (v[i] == 0) continue;
                cout << v[i] << " " << i << endl;
            }
        }
    }
};

int main()
{
    Polymulti poly = Polymulti();
    int m;
    int cnt_fun;
    cin >> cnt_fun ;

    for (int i=0; i<cnt_fun ; i++){
        int cnt_term;
        cin >> cnt_term;
        poly.getf(cnt_term);
        if ( i != 0 )   poly.copy_v();
    }

    m = poly.max_i();
    poly.printf(m);

    return 0;
}
