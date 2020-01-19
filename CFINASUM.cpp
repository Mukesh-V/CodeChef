#include<stdio.h>
#include<vector>

using namespace std;

int sum(vector<int> subseq, int no){
    int x, total = 0, right_sum=0, count=0;
    for(x=0;x<no;x++){
        total += subseq[x];
    }
    for(x=no;x>0;x--){
        right_sum += subseq[x];
        total -= subseq[x];
        if(right_sum == total)
            count++;
    }
    return count;
}

int create_seq(vector<int> inp, int index, int num){
    vector<int> b;
    for(int l=0;l<num; l++){
        if(l==index-1)
            b.push_back(0);
        else
            b.push_back(inp[l]);
    }
    return sum(b, num);
}

int main(){
    int t, n, i, j, in, k, s;
    vector<int> ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        vector<int> a;
        for(j=0;j<n;j++){
            scanf("%d",&in);
            a.push_back(in);
        }
        s = 0;
        for(k=1;k<=n;k++){
            s += create_seq(a, k, n);
        }
        ans.push_back(s);
    }
    for(i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
}