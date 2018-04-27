package next_closest_time;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public String nextClosestTime(String time) {
        Set<Integer> set = new HashSet<>();
        set.add(Integer.parseInt(time.substring(0, 1)));
        set.add(Integer.parseInt(time.substring(1, 2)));
        set.add(Integer.parseInt(time.substring(3, 4)));
        set.add(Integer.parseInt(time.substring(4, 5)));
        int cur = Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3, 5));
        String result = time;
        int min = Integer.MAX_VALUE;
        for (int h1 : set) {
            for (int h2 : set) {
                int hVal = h1 * 10 + h2;
                if (hVal < 24) {
                    for (int m1 : set) {
                        for (int m2 : set) {
                            int mVal = m1 * 10 + m2;
                            if (mVal < 60) {
                                int val = hVal * 60 + mVal;
                                int interval = val - cur;
                                if (interval <= 0) {
                                    interval += 1440;
                                }
                                if (interval < min) {
                                    min = interval;
                                    StringBuilder sb = new StringBuilder();
                                    if (hVal < 10) {
                                        sb.append(0);
                                    }
                                    sb.append(hVal).append(":");
                                    if (mVal < 10) {
                                        sb.append(0);
                                    }
                                    result = sb.append(mVal).toString();
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }

    public String nextClosestTimeWithoutDuplicates(String time) {
        Set<Integer> set = new HashSet<>();
        int[] arr = new int[4];
        arr[0] = Integer.parseInt(time.substring(0, 1));
        arr[1] = Integer.parseInt(time.substring(1, 2));
        arr[2] = Integer.parseInt(time.substring(3, 4));
        arr[3] = Integer.parseInt(time.substring(4, 5));
        int cur = Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3, 5));
        String result = time;
        int min = Integer.MAX_VALUE;
        for (int h1 = 0; h1 < 4; h1++) {
            set.add(h1);
            for (int h2 = 0; h2 < 4; h2++) {
                if (!set.contains(h2)) {
                    set.add(h2);
                    int hVal = arr[h1] * 10 + arr[h2];
                    if (hVal < 24) {
                        for (int m1 = 0; m1 < 4; m1++) {
                            if (!set.contains(m1)) {
                                set.add(m1);
                                for (int m2 = 0; m2 < 4; m2++) {
                                    if (!set.contains(m2)) {
                                        set.add(m2);
                                        int mVal = arr[m1] * 10 + arr[m2];
                                        if (mVal < 60) {
                                            int val = hVal * 60 + mVal;
                                            int interval = val - cur;
                                            if (interval <= 0) {
                                                interval += 1440;
                                            }
                                            if (interval < min) {
                                                min = interval;
                                                StringBuilder sb = new StringBuilder();
                                                if (hVal < 10) {
                                                    sb.append(0);
                                                }
                                                sb.append(hVal).append(":");
                                                if (mVal < 10) {
                                                    sb.append(0);
                                                }
                                                result = sb.append(mVal).toString();
                                            }
                                        }
                                        set.remove(m2);
                                    }
                                }
                                set.remove(m1);
                            }
                        }
                        set.remove(h2);
                    }
                }
            }
            set.remove(h1);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().nextClosestTimeWithoutDuplicates("19:34"));
    }
}