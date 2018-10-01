package interview.twosigma;

import java.util.*;

public class VowelConsonant {

    static class Item {
        char c;
        int index;
        int len;

        Item(char c, int index, int len) {
            this.c = c;
            this.index = index;
            this.len = len;
        }
    }

    public static List<String> minMSuaxbstring(String s) {
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        int start = 0, end = s.length() - 1;
        while (start < s.length() && !set.contains(s.charAt(start))) {
            start++;
        }
        while (end >= 0 && set.contains(s.charAt(end))) {
            end--;
        }
        if (end < start) {
            return new ArrayList<>();
        }
        s = s.substring(start, end + 1);
        char[] cs = new char[]{'a', 'e', 'i', 'o', 'u'};
        PriorityQueue<Item> minPQ = new PriorityQueue<>((a, b) -> {
            if (a.c == b.c) {
                return b.len - a.len;
            }
            return a.c - b.c;
        });
        PriorityQueue<Item> maxPQ = new PriorityQueue<>((a, b) -> {
            if (a.c == b.c) {
                return b.len - a.len;
            }
            return b.c - a.c;
        });
        for (char c : cs) {
            boolean found = false;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    found = true;
                    minPQ.offer(new Item(c, i, 1));
                }
            }
            if (found) {
                break;
            }
        }
        for (char j = 4; j >= 0; j--) {
            boolean found = false;
            char c = cs[j];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    found = true;
                    maxPQ.offer(new Item(c, i, 1));
                }
            }
            if (found) {
                break;
            }
        }
        if (minPQ.isEmpty()) {
            return new ArrayList<>();
        }
        List<String> result = new LinkedList<>();
        while (!minPQ.isEmpty()) {
            Item cur = minPQ.poll();
            if (!set.contains(cur.c)) {
                int p = cur.index - cur.len + 1;
                while (s.charAt(p) == s.charAt(p + 1)) {
                    p++;
                }
                if (s.charAt(p) < s.charAt(p + 1)) {
                    p = cur.index - cur.len + 1;
                }
                result.add(s.substring(p, cur.index + 1));
                break;
            }
            if (cur.index < s.length() - 1) {
                minPQ.offer(new Item(s.charAt(cur.index + 1), cur.index + 1, cur.len + 1));
            }
        }
        while (!maxPQ.isEmpty()) {
            Item cur = maxPQ.poll();
            if (!set.contains(cur.c)) {
                int p = cur.index - cur.len + 1;
                while (s.charAt(p) == s.charAt(p + 1)) {
                    p++;
                }
                if (s.charAt(p) > s.charAt(p + 1)) {
                    p = cur.index - cur.len + 1;
                }
                result.add(s.substring(p, s.length()));
                break;
            }
            if (cur.index < s.length() - 1) {
                maxPQ.offer(new Item(s.charAt(cur.index + 1), cur.index + 1, cur.len + 1));
            }
        }
        return result;
    }

    public static String minSubstring(String s) {
        String set = "aeiou";
        PriorityQueue<Item> pq = new PriorityQueue<>((a, b) -> {
            if (a.c == b.c) {
                return b.len - a.len;
            }
            return a.c - b.c;
        });
        for (int i = 0; i < s.length(); i++) {
            if (set.contains(s.charAt(i) + "")) {
                pq.offer(new Item(s.charAt(i), i, 1));
            }
        }
        if (pq.isEmpty()) {
            return "";
        }
        while (!pq.isEmpty()) {
            Item cur = pq.poll();
            if (!set.contains(cur.c + "")) {
                return s.substring(cur.index - cur.len + 1, cur.index + 1);
            }
            if (cur.index < s.length() - 1) {
                pq.offer(new Item(s.charAt(cur.index + 1), cur.index + 1, cur.len + 1));
            }
        }
        return "";
    }


    public static void main(String[] args) {
        System.out.println(minMSuaxbstring("aab"));
        System.out.println(minMSuaxbstring("aubauub"));
        System.out.println(minMSuaxbstring("aba"));
        System.out.println(minMSuaxbstring("rejhiuecumovsutyrulqaeuouiecodjlmjeaummaoqkexylwaaopnfvlbiiiidyckzfhe"));
        System.out.println(minMSuaxbstring("aibaec"));
        System.out.println(minMSuaxbstring("aaaaaaaaaaaaaaaaaaaaaaab"));
        System.out.println(minMSuaxbstring("uuuuuuuuuuuuub"));
        System.out.println(minMSuaxbstring("aaiiuubbggeeooeecczz"));
        System.out.println(minMSuaxbstring("aebaaib"));
    }

}
