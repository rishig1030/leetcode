class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions for North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, dir = 0;
        int maxDistSquared = 0;

        // Set of obstacles for quick lookup
        unordered_set<string> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for (int command : commands) {
            if (command == -2) {
                // Turn left 90 degrees
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                // Turn right 90 degrees
                dir = (dir + 1) % 4;
            } else {
                // Move forward k units
                for (int i = 0; i < command; ++i) {
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;

                    // Check if new position is an obstacle
                    if (obstacleSet.find(to_string(newX) + "," + to_string(newY)) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDistSquared = max(maxDistSquared, x * x + y * y);
                    } else {
                        break;  // Stop moving in this direction due to obstacle
                    }
                }
            }
        }
        return maxDistSquared;
    }
};