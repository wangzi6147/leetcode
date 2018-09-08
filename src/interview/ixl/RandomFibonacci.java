package interview.ixl;

import java.util.Random;

public class RandomFibonacci {

    // 随机返回一个比输入整数小的Fibnacci number

    public int randomFibonacci(int n) {
        Random r = new Random();
        int a = 1, b = 1, size = 1, result = -1;
        while (b <= n) {
            if (r.nextInt(size++) == 0) {
                result = b;
            }
            int c = a + b;
            a = b;
            b = c;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(new RandomFibonacci().randomFibonacci(100000));
        System.out.println(new RandomFibonacci().randomFibonacci(100000));
        System.out.println(new RandomFibonacci().randomFibonacci(100000));
        System.out.println(new RandomFibonacci().randomFibonacci(100000));
        System.out.println(new RandomFibonacci().randomFibonacci(100000));
    }
}
