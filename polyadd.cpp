#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Polyadd{
private:
    int cnt;
    int c;
    int e;
    int max_index;
    vector <int> v = vector <int> (1001,0);

public:
     Polyadd(){
        cnt = 0;
    }

     void printf(int m){
        if (m==0 && v[m] == 0){
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

     void getf(){
        cin >> c >> e;
        if (v[e] == 0) {
            v[e] = c ;
        }
        else v[e] += c;
     }

     int max_i(){
        for ( int i=v.size()-1 ; i>-1 ; i--)
            if(v[i] != 0)   return i;
        return 0;
     }
};

int main()
{
    Polyadd poly = Polyadd();
    int m;
    int cnt_fun;
    cin >> cnt_fun ;

    for (int i=0; i<cnt_fun ; i++){
        int cnt_term;
        cin >> cnt_term;

        for (int j=0;j<cnt_term;j++){
            poly.getf();
        }

    }
    m = poly.max_i();
    poly.printf(m);
    return 0;
}
