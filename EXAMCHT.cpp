#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int t, a, b, i, c, p, d;
    scanf("%d",&t);
    vector<int> ans;
    for(i=1;i<=t;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        d = abs(a-b);
        p = 1;
        c = 0;
        while(p<=sqrt(d)){
            if(d%p == 0){
                if(d/p == p) 
                    c++;
                else
                    c+=2;
            }
            p++;
        }
        if(d==0)
            c = -1;
        ans.push_back(c);
    }
    for(i=0;i<t;i++)
        printf("%d\n",ans[i]);
}