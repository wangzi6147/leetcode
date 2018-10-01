package interview.indeed;

import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class Ink {

    public static void ink(int[][] paper, int[][] points) {
        int m = paper.length, n = paper[0].length;
        Arrays.sort(points, (a, b) -> (b[2] - a[2]));
        Deque<int[]> q = new LinkedList<>();
        q.offer(points[0]);
        int i = 1;
        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            while (i < points.length && points[i][2] == q.peekLast()[2]) {
                q.offer(points[i++]);
            }
            int[] cur = q.poll();
            int x = cur[0], y = cur[1], val = cur[2];
            if (paper[x][y] > 0) {
                continue;
            }
            paper[x][y] = val;
            if (val == 1) {
                continue;
            }
            for (int[] dir : dirs) {
                int row = x + dir[0];
                int col = y + dir[1];
                if (row >= 0 && row < m && col >= 0 && col < n && paper[row][col] == 0) {
                    q.offer(new int[]{row, col, val - 1});
                }
            }
        }
    }

    public static void main(String[] args) {
        int[][] paper = new int[500][500];
        int[][] points = new int[][]{{0, 0, 100}, {5, 5, 50}, {95, 95, 100}, {250, 250, 100}};
        ink(paper, points);
        System.out.println("test");
    }

}
