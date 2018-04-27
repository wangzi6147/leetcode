package k_empty_slots;

public class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] days = new int[flowers.length];
        for (int i = 0; i < flowers.length; i++) {
            days[flowers[i] - 1] = i;
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < days.length - k - 1; i++) {
            int j = i + 1;
            for (; j < i + k + 1; j++) {
                if (days[j] < days[i] || days[j] < days[i + k + 1]) {
                    break;
                }
            }
            if (j == i + k + 1) {
                result = Math.min(result, Math.max(days[i], days[i + k + 1]));
            }
            i = j - 1;
        }
        return result == Integer.MAX_VALUE ? -1 : result + 1;
    }


    public int kConsecutiveSlots(int[] flowers, int k) {
        int N = flowers.length;
        int[] days = new int[N];
        for (int i = 0; i < N; i++) {
            days[flowers[i] - 1] = i;
        }
        int result = -1;
        for (int i = -1; i < N - k; i++) {
            int j = i + 1;
            for (; j < i + k + 1; j++) {
                if (i >= 0 && days[j] > days[i] || i < N - k - 1 && days[j] > days[i + k + 1]) {
                    break;
                }
            }
            if (j == i + k + 1) {
                int left = i >= 0 ? days[i] : N;
                int right = i < N - k - 1 ? days[i + k + 1] : N;
                result = Math.max(result, Math.min(left, right));
            }
            i = j - 1;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().kConsecutiveSlots(new int[]{2, 3, 6, 5, 1, 7, 4}, 2));
    }
}
