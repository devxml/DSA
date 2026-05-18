bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Step 1: Build adjacency list and indegree array
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    for (auto& pre : prerequisites) {
        int course = pre[0];
        int prereq = pre[1];
        adj[prereq].push_back(course); // prereq → course
        indegree[course]++;
    }

    // Step 2: Push all courses with no prerequisites into queue
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: BFS
    int completed = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        completed++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 4: If all courses completed → no cycle
    return completed == numCourses;
}