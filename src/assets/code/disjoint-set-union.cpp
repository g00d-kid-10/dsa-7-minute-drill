class DSU {
private:
    vector<int> parent, rank;
    DSU(int n) : parent(n),  rank(n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if(parent[a] == a) {
            return parent[a];
        }

        return parent[a] = find(parent[a]);
    }

    void join(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if(pa == pb) {
            return;
        }

        if(rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if(rank[pb] < rank[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};