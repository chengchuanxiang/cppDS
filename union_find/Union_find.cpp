class Union_find{
public:
    int Count(){return count;}
    int find(int x){
        while(x != father[x]){
            father[x] = father[father[x]];
            x = father[x];
        }
        return x;
    }
    void Union(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)return ;
        father[rootQ] = rootP;
        --count;
    }
    Union_find(int n){
        count = n;
        father = new int[n];
        for(int i = 0; i < n; ++i){
            father[i] = i;
        }
    }

private:
    int count;
    int *father;
};
