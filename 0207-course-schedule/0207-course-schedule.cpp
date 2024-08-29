class Solution {
    bool dfs(vector<bool>& visiting, vector<bool>& visited, vector<vector<int>>& courses, int course) {
        if (visiting[course]) return false;

        if (visited[course]) return true;

        visiting[course] = true;

        for (int nextCourse : courses[course]) {
            if (!dfs(visiting, visited, courses, nextCourse)) {
                return false;
            }
        }

        visiting[course] = false;
        visited[course] = true;

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.empty()) return true;

        vector<vector<int>> courses(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);

        for (const auto& prerequisite : prerequisites) {
            courses[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (!dfs(visiting, visited, courses, i)) {
                    return false;  
                }
            }
        }

        return true;
    }
};
