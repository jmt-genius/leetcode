class Solution {

    public void dfs(int node, int[] visited, ArrayList<ArrayList<Integer>> adj) {
        visited[node] = 1;

        for (int neighbor : adj.get(node)) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, visited, adj);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isConnected[i][j] == 1) {
                    adj.get(i).add(j);
                }
            }
        }

        int[] visited = new int[n];
        int count = 0;

        // Count connected components
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                count++;
                dfs(i, visited, adj);
            }
        }

        return count;
    }
}