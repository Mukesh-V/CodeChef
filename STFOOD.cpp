#include<stdio.h>
#include<vector>

using namespace std;

int main(){
    int t, n, in1, in2, in3, i, j, max=0;
    vector<int> ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        max = 0;
        vector<int> s, p, v, possible;
        for(j=0;j<n;j++){
            scanf("%d %d %d", &in1, &in2, &in3);
            s.push_back(in1);
            p.push_back(in2);
            v.push_back(in3);
            if(in2%in1!=0)
                possible.push_back(j);
        }
        for(j=0;j<possible.size();j++){
            max = (max>=(p[j]/s[j])*v[j])?max:(p[j]/s[j])*v[j];
        }
        ans.push_back(max);
    }
    for(j=0;j<ans.size();j++){
        printf("%d\n",ans[j]);
    }
}