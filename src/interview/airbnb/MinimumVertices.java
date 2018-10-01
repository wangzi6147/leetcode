package interview.airbnb;

import java.util.*;

/**
 * Given a directed graph, find the minimal number of vertices that can traverse all the vertices from them.
 * For example
 * 2->3->1->2->0, 4->5
 * Then we need [1, 4] (or [2, 4], [3, 4]) to traverse all the vertices.
 * Only one solution is needed if there are more than one possibilities.
 */

public class MinimumVertices {

    public List<Integer> getMin(int[][] edges, int n) {
        Stack<Integer> stack = new Stack<>();

        Map<Integer, Set<Integer>> nodes = new HashMap<>();
        for (int i = 0; i < n; i++) {
            nodes.put(i, new HashSet<>());
        }
        for (int[] edge : edges) {
            nodes.get(edge[0]).add(edge[1]);
        }

        Set<Integer> visited = new HashSet<>();
        for (int i = 0; i < n; i++) {
            dfs(nodes, i, visited, stack);
        }

        List<Integer> result = new LinkedList<>();
        visited.clear();
        while (!stack.isEmpty()) {
            int cur = stack.pop();
            if (visited.contains(cur)) {
                continue;
            }
            result.add(cur);
            dfs(nodes, cur, visited, new Stack<>());
        }
        return result;
    }

    private void dfs(Map<Integer, Set<Integer>> nodes, int start, Set<Integer> visited, Stack<Integer> stack) {
        if (visited.contains(start)) {
            return;
        }
        visited.add(start);
        for (int next : nodes.get(start)) {
            dfs(nodes, next, visited, stack);
        }
        stack.push(start);
    }

    public static void main(String[] args) {
        MinimumVertices mv = new MinimumVertices();
        //    1->2->3->1, 2->0->0
        int[][] edges1 = {{0, 0}, {1, 2}, {2, 0}, {2, 3}, {3, 1}};
        System.out.println(mv.getMin(edges1, 4));
        //      0  1  2  3  4  5  6  7  8  9
        //    0[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        //    1[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        //    2[0, 0, 0 ,0, 0, 0, 0, 0, 0, 1]
        //    3[0, 0, 0, 1, 0, 1, 0, 1, 0, 0]
        //    4[0, 0, 0, 0, 0, 0 ,0, 0, 1, 0]
        //    5[0, 0, 0, 0, 0, 0, 0, 0, 1, 0]
        //    6[0, 0, 0, 0, 0, 0, 1, 0, 0 ,0]
        //    7[0, 0, 0, 0, 1, 0, 0, 0, 0, 0]
        //    8[0, 0, 0, 0, 0, 0, 0, 1, 0, 0]
        //    9[0, 0, 0, 1, 0, 0, 1, 0, 0, 0]
        int[][] edges2 = {{2, 9}, {3, 3}, {3, 5}, {3, 7}, {4, 8}, {5, 8}, {6, 6}, {7, 4}, {8, 7}, {9, 3}, {9, 6}};
        System.out.println(mv.getMin(edges2, 10));
        //    0->1->0, 2->3->2->1
        int[][] edges3 = {{0, 1}, {1, 0}, {2, 1}, {2, 3}, {3, 2}};
        System.out.println(mv.getMin(edges3, 4));
    }

}
