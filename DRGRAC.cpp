#include<stdio.h>
#include<cstdlib>
#include<vector>

using namespace std;

int main(){
    int t, n, i, j, d, x, y, dx, dy, f;
    scanf("%d",&t);
    vector<int> dummy(1, 1);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        vector< vector<int> > graph(n,dummy);
        for(j=0; j<n;j++){
            scanf("%d",&x);
            scanf("%d",&y);
            graph[j].push_back(x);
            graph[j].push_back(y);
        }
        while(true){
            for(j=0;j<n;j++){
                if(j<n-1){
                    dx = abs(graph[j][1] - graph[j+1][1]);
                    dy = abs(graph[j][2] - graph[j+1][2]);
                }
                else{
                    dx = abs(graph[j][1] - graph[0][1]);
                    dy = abs(graph[j][2] - graph[0][2]);
                }
                if(dx==0 || dy==0){
                    f = (dx > dy)?0:1;
                    switch(f){
                        case 0:
                        {
                            graph[j][0] = 1;
                            break;
                        }
                        case 1:
                        {
                            graph[j][0] = 0;
                            break;
                        }                
                    }
                }
                else{
                    if(j==0) continue;
                    graph[j][0] = graph[j-1][0];
                } 
            }
            for(j=0;j<n;j++){
                printf("%d ",graph[j][0]);
            }
            printf("\n");
        }
    }
}