#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector <vector <int>> v;
    vector <vector <int>> v2;

    for(int i=0 ; i<N ; i++){
        vector <int> v1;
        int a,b;
        cin >> a >> b;
        v1.push_back(a);
        v1.push_back(b);
        v.push_back(v1);
        v2.push_back(v1);
    }
    for(int i=0 ; i<N ; i++){
        for ( int j=0; j<N ; j++){
            if (v[i][0] > v[j][0] && v[i][1] < v[j][1]){
                v[j][0] = 0;
                v[j][1] = 0;
            }
        }
    }

    for ( int i =0 ;i<N;i++){
        if (v[i][0] != 0){
            for(int k=0; k<N; k++){
                if(v2[k][0] == v[i][0] && v2[k][1] == v[i][1] )
                    cout << k+1 << endl;
            }
        }
    }

}
