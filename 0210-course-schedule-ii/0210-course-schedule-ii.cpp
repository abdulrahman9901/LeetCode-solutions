class Solution {
    bool dfs(vector<bool>& visiting, vector<int>& visited, vector<vector<int>>& courses, int course) {
        if (visiting[course]) return false;

        if (find(visited.begin(),visited.end(),course) != visited.end()) return true;

        visiting[course] = true;

        for (int nextCourse : courses[course]) {
            if (!dfs(visiting, visited, courses, nextCourse)) {
                return false;
            }
        }
        cout<<course<<endl;
        visiting[course] = false;
        visited.push_back(course);

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1 ) return {0};

        if(prerequisites.empty()){
            std::vector<int> ivec(numCourses);
            std::iota(ivec.begin(), ivec.end(), 0);
            return ivec;
        }

        vector<vector<int>> courses(numCourses);
        vector<int> visited;
        vector<bool> visiting(numCourses, false);

        for (const auto& prerequisite : prerequisites) {
            courses[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (find(visited.begin(),visited.end(),i) == visited.end()) {
                if (!dfs(visiting, visited, courses, i)) {
                    return {};  
                }
            }
        }
        reverse(visited.begin(), visited.end());
        return visited;
    }
};