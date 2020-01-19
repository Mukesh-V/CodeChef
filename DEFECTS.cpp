#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int i, j, t, n, m, num;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> m;
        vector<int> dummy(m,0);
        vector< vector<int> > board(n,dummy);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                cin >> board[i][j];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(board[i][j]==0){

                }
            }
        }
        }
    }

}