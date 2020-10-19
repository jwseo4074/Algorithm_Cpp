#include <iostream>
#include <vector>

using namespace std;

int f_x=0;
int f_y=0;
int cnt=0;
vector <int> v1;
vector <int> v2;

void set_func(){
    v1.push_back(f_x);
    v2.push_back(f_y);
    cnt++;
}
int main()
{
    int n_K;
    cin >> n_K;
    int n_xy[n_K+1][2];
    for(int j=0; j<n_K; j++){
        cin >> n_xy[j][0];
        cin >> n_xy[j][1];
    }

    f_x = n_xy[0][0];
    f_y = n_xy[0][1];
    n_xy[n_K][0] = n_xy[0][0];
    n_xy[n_K][1] = n_xy[0][1];

    v1.push_back(f_x);
    v2.push_back(f_y);

    int arr_t[5];
    for(int k=0;k<5;k++)
        cin >> arr_t[k];
    int v_xy;

    for(int i=0;i<n_K;i++){
        if(n_xy[i][0] == n_xy[i+1][0]){       //x 좌표가 같을때 -> y 비교
            if (n_xy[i][1] < n_xy[i+1][1] ){      // y 가 커질때
                //v_xy = abs(n_xy[i+1][1]-n_xy[i][1]);
                v_xy = abs(n_xy[i][1]-n_xy[i+1][1]);
                for(int j=0;j<v_xy;j++){
                    f_y++;
                    set_func();
                }
            }
            if (n_xy[i][1] > n_xy[i+1][1]){       // y 가 작아질때
                v_xy = abs(n_xy[i][1]-n_xy[i+1][1]);
                for(int j=0;j<v_xy;j++){
                    f_y--;
                    set_func();
                }

            }
        }
        if(n_xy[i][1] == n_xy[i+1][1]){     //y 좌표가 같을때 -> x 비교
            if (n_xy[i][0] < n_xy[i+1][0] ){      // x 가 커질때
                //v_xy = abs(n_xy[i+1][0]-n_xy[i][0]);
                v_xy = abs(n_xy[i][0]-n_xy[i+1][0]);
                for(int j=0;j<v_xy;j++){
                    f_x++;
                    set_func();
                }
            }
            if (n_xy[i][0] > n_xy[i+1][0] ){      // y 가 작아질때
                v_xy = abs(n_xy[i][0]-n_xy[i+1][0]);
                for(int j=0;j<v_xy;j++){
                    f_x--;
                    set_func();
                }
            }
        }
    }

    for (int j=0; j<5;j++)
        arr_t[j] = arr_t[j] % cnt ;
    for (int j=0; j<5;j++)
        cout << v1[arr_t[j]] <<" " << v2[arr_t[j]] << endl;
}
