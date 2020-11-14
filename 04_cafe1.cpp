#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ENDL if( i != k-1) cout << endl;
#define vs v2.size()

using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector <int> v(n+1,0);
    vector <int> :: iterator it;
    vector <int> v2;

    for (int i=0; i<k; i++){
        int a;
        cin >> a;

        if (v[a] != a) {
            v[a] = a;
            v2.push_back(a);
            sort(v2.begin(),v2.end());

            if ( vs == 1 ) {
                cout << a << " " << v2[0] <<" "<< v2[0];
                ENDL
            }

            else {
                if ( a == v2[v2.size()-1]) {
                    cout << a << " " << v2[vs-2] <<" "<< v2[0];
                    ENDL
                }
                else if (a == v2[0]){
                    cout << a << " " << v2[vs-1] << " " << v2[1];
                    ENDL
                }
                else {
                    int x;
                    for ( int i=0 ; i<vs;i++){
                        if (v2[i] == a)     x = i ;
                    }
                    cout << a << " " << v2[x-1] <<" "<< v2[x+1];
                    ENDL
                }

            }
        }
        else {
            v[a] = 0;
            v2.erase(remove(v2.begin(),v2.end(),a));
            sort(v2.begin(),v2.end());

        }
    }

    return 0;
}
