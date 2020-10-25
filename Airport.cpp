#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()  {
    int counter=0;
    int K;
    cin >> K;
    vector < vector <int> > v;
    for(int i=0 ; i<K ; i++){
        vector <int> v2;
        for ( int j = 0 ; j<10000; j++){
            int a;
            cin >> a;
            if (a == 0) break;
            v2.push_back(a);
            counter++;
         }
        v.push_back(v2);
    }

    for ( int abc=0; abc<counter ; abc++){
        vector <int> v3;
        for(int i=0 ; i<K ; i++){
            if (v[i].empty()){
                continue;
            }
            else
                v3.push_back(v[i][0]);
        }
        int min_value = *min_element(v3.begin(),v3.end());
        cout << min_value << endl;
        for(int i=0 ; i<K ; i++){
            if (v[i].empty())
                continue;
            else {
                if (min_value == v[i].front()){
                    v[i].erase(v[i].begin());
                    break;
                }
                else {
                    continue;
                }
            }
        }
    }
    return 0;
}
