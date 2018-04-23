class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
//         cout << "count is: " << count << endl;
        
//         cout << "degree:\n";
//         for(int i = 0; i < degree.size(); i++)
//             cout << degree[i] << ", ";
//         cout << endl;
        
//         cout << "heads:\n";
//         for(int i = 0; i < heads.size(); i++)
//             cout << heads[i] << ", ";
//         cout << endl;
        
//         cout << "points:\n";
//         for(int i = 0; i < points.size(); i++)
//             cout << points[i] << ", ";
//         cout << endl;
        
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(degree[i] == 0)
                q.push(i);
        
        
        vector<int> res;
        
        
        while(!q.empty())
        {
            to = q.front();
            res.push_back(to);
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
                return {};
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
