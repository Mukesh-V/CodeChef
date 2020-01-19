#include<stdio.h>
#include<vector>

using namespace std;

int main(){
    int t, n, i, j, in, d, x, c;
    vector<int> ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        vector<int> fav;
        for(j=0;j<n;j++){
            scanf("%d",&in);
            fav.push_back(in);
        }
        x = 0;
        c = 1;
        d = -1;
        while(c<=fav.back()){
            for(j=0;j<n;j++){
                if(c%fav[j]==0){
                    if (d<(c-x))
                        d = c - x;
                    x = c;
                    break;
                }
            }
            c++;
        }
        ans.push_back(d);
    }
    for(i=0;i<t;i++){
        printf("%d \n",ans[i]);
    }
}