#include <iostream>
using namespace std;

int func(int a, int b, int M , int N);

int point_x[4] = {-1,0,1,0};
int point_y[4] = {0,1,0,-1};
int V[1000]; //잡의 수 새기
int number_v ,msize ,answer = 0;
int map[30][30];
bool alreadycom[30][30];

int main() {
    int N,M,K;

    cin >> N >> M >> K;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            char shap;
            cin >> shap;

            if(shap == '#') shap = 1;
            else shap = 0;

            map[i][j] = shap;
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                if (alreadycom[i][j] == false){
                    number_v++;
                    func(i,j,M,N);
                }
            }
        }
    }

    for(int i = 0; i < N*M; i++){
        if(V[i] >= K){
            if(V[i] > msize) msize = V[i];

            answer++;
        }
    }

    cout << answer << " " << msize;

}

int func(int a, int b, int M , int N){
    V[number_v]++;
    alreadycom[a][b] = true;

    for(int i=0 ; i<4; i++){
        int xsum = point_x[i] + a;
        int ysum = point_y[i] + b;

        if(0 <= xsum && xsum < M && 0 <= ysum && ysum < N){
            if(map[xsum][ysum] == 1){
                if(alreadycom[xsum][ysum] == false) func(xsum,ysum,M,N);
            }
        }
    }
    return 0 ;
}
