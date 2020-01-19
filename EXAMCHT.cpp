#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t, a, b, i, c, p;
    scanf("%d",&t);
    vector<int> ans;
    for(i=1;i<=t;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        a -= 1;
        b -= 1;
        p = 1;
        c = 0;
        while(p<=(max(a,b)/2)+1){
            if(a%p == b%p)  c++;
            p++;
        }
        ans.push_back(c);
    }
    for(i=0;i<t;i++)
        printf("%d\n",ans[i]);
}