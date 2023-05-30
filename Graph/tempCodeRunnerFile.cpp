   void print_BFS(int n){
        q.push(n);
        visited[n] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto l:adj_list[n]){
                if (!visited[l])
                {
                    q.push(l);
                    visited[l]=true;
                }
            }
            cout<<node<<" ";
        }
    }