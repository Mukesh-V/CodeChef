#include<stdio.h>
#include<cstdlib>
#include<vector>

using namespace std;

template < class mu >
mu ab(mu a)
{
	return (a > 0 ? a : a * -1);
}

int main(){
    long int t, i, j, in;
    vector<int> ans;

    scanf("%d",&t);
    for(i=1;i<=t;i++){
        long int n, a, b, c, pos, min = 10000000000;

        scanf("%l %l %l %l", &n, &a, &b, &c);
        pos = b;

        for(j=0;j<n;j++){
            scanf("%l",&in);
            min = ( min < (ab(b-in) + ab(a-in)) )?min:(ab(b-in) + ab(a-in));
        }
        ans.push_back(min+c);
    }
    for(i=0;i<ans.size();i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}