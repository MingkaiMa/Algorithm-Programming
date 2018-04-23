class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> heads(numCourses, -1);
        vector<int> degree(numCourses, 0);
        vector<int> points, args;
        
        pair<int, int> p;
        int from, to, count = 0, len = prerequisites.size();
        
        for(int i = 0; i < len; i++)
        {
            p = prerequisites[i];
            from = p.second;
            to = p.first;
            ++degree[from];
            args.push_back(heads[to]);
            points.push_back(from);
            heads[to] = count++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(degree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            to = q.front();
            q.pop();
            from = heads[to];
            while(from != -1)
            {
                if(--degree[points[from]] == 0)
                    q.push(points[from]);
                from = args[from];
            }
            
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            if(degree[i] > 0)
                return false;
        }
        return true;
    }
};
