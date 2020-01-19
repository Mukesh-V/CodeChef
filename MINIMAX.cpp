#include<iostream>
#include<vector>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int  n, i, j, k, c, p, num,r=0;
    vector<int> a;
    vector<int> b;

    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        a.push_back(num);
    }
    for(i=0;i<n;i++){
        cin >> num;
        b.push_back(num);
    }

    vector<int> dummy(1, 0);
    vector< vector<int> > graph(n,dummy);

    for(i=1;i<n;i++){
        cin >> p;
        cin >> c;
        graph[p-1].push_back(c);
    }

    for(i=0;i<n;i++){
        for(j=1;j<graph[i].size();j++){
            for(k=0;k<graph[graph[i][j]-1].size();k++){
                if(graph[graph[i][j]-1][k] == 0)
                    continue;
                graph[i].push_back(graph[graph[i][j]-1][k]);
            }
        }
    }

    for(i=0;i<n;i++){
        r = r + min(a[i],b[i]);
        for(j=0;j<graph[i].size();j++){
            if(graph[i][j] == 0)
                continue;
            r = r + min(max(a[i],a[graph[i][j]-1]),max(b[i],b[graph[i][j]-1]));
        }
    }
    cout << r;
}