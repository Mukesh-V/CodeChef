#include<stdio.h>
#include<vector>

using namespace std;

struct Node{
    int index, a, b;
    struct Node* parent;
    Node(int index)
    {
        this->index = index;
        this->parent = NULL;
    }
};

bool subTree(Node* node1, Node* node2)
{
    if(node2 == NULL)
        return false;
    if(node1->index == node2->index)
        return true;
    return subTree(node1, node2->parent);
}

int main(){
    int  n, i, j,c, p, r=0;
    vector<Node> nodes;

    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        nodes.push_back(Node(i));
        scanf("%d",&(nodes[i].a));
    }
    for(i=0;i<n;i++)
        scanf("%d",&(nodes[i].b));
    
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&p,&c);
        nodes[c-1].parent = &(nodes[p-1]);
    }

    r = min(nodes[0].a,nodes[0].b);
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if ( subTree(&(nodes[i]),&(nodes[j])) )
                r += min(max(nodes[i].a,nodes[j].a),max(nodes[i].b,nodes[j].b));
        }
    }
    
    printf("%d",r);
    return 0;
}