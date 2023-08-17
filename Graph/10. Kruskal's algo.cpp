

#include<bits/stdc++.h>
bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
void makeSet(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findParent(int i,vector<int> &parent){
    //base case
    if(parent[i]==i){
        return i;
    }
    return findParent(parent[i],parent);
}
void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int ans=0;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        int par1=findParent(u,parent);
        int par2=findParent(v,parent);

        if(par1!=par2){
            ans+=edges[i][2];
            unionSet(par1,par2,parent,rank);
        }
    }
    return ans;
}

