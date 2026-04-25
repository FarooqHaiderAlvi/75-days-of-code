class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                stack<int> st;
                st.push(i);
                visited[i] = true;

                while (!st.empty()) {
                    int currentCity = st.top();
                    st.pop();

                    for (int neighbor = 0; neighbor < n; neighbor++) {
                        if (isConnected[currentCity][neighbor] == 1 &&
                            !visited[neighbor]) {
                            visited[neighbor] = true;
                            st.push(neighbor);
                        }
                    }
                }
                provinces++;
            }
        }

        return provinces;
    }
};