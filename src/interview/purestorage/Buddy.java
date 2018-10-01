package interview.purestorage;

public class Buddy {

    private int[][] bits;

    public Buddy(int[] a) {
        int levels = Integer.toBinaryString(a.length).length();
        bits = new int[levels][];
        int i = 0, level = 0;
        while (i < a.length) {
            int l = Math.min((1 << level), a.length - i);
            bits[level] = new int[l];
            int count = 0;
            while (count < l) {
                bits[level][count++] = a[i++];
            }
            level++;
        }
    }

    public void setBits(int offset, int length) {
        int curLevel = bits.length - 1;
        int left = offset, right = offset + length - 1;
        while (curLevel >= 0) {
            for (int i = left; i <= right; i++) {
                bits[curLevel][i] = 1;
            }
            if (left % 2 == 1 && bits[curLevel][left - 1] == 0) {
                // left是奇数位并且left-1是0的话，不更新left的父节点，要left++再除以2
                left++;
            }
            if (right % 2 == 0 && right < bits[curLevel].length - 1 && bits[curLevel][right + 1] == 0) {
                // right是偶数位并且right+1是0的话，不更新right的父节点，要right--再除以2
                right--;
            }
            left /= 2;
            right /= 2;
            curLevel--;
            if (left > right) {
                break;
            }
        }
    }

    public void clearBits(int offset, int length) {
        int curLevel = bits.length - 1;
        int left = offset, right = offset + length - 1;
        while (curLevel >= 0) {
            for (int i = left; i <= right; i++) {
                bits[curLevel][i] = 0;
            }
            left /= 2;
            right /= 2;
            curLevel--;
        }
    }

    public static void main(String[] args) {
        new Buddy(new int[]{0,0,1,1,0,1,1,1,1,1,0,1});
    }

}
