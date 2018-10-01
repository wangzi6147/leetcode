package interview.palantir;

import java.util.*;

public class JobInvoice {

    public static List<String> invalidInvoices(String[] input) {
        List<String> result = new LinkedList<>();
        Map<String, List<int[]>> map = new HashMap<>();
        int prev = 0;
        for (int i = 0; i < input.length; i++) {
            String s = input[i];
            String[] ss = s.split(";");
            String name = ss[0];
            if (ss[1].equals("START")) {
                if (!map.containsKey(name)) {
                    map.put(name, new LinkedList<>());
                }
                map.get(name).add(new int[]{i + 1, prev});
            } else {
                String[] ids = ss[1].split(",");
                int[] is = new int[ids.length];
                for (int j = 0; j < ids.length; j++) {
                    is[j] = Integer.valueOf(ids[j]);
                }
                Arrays.sort(is);
                List<int[]> l = map.get(name);
                boolean invalid = false;
                int index = 0;
                for (int id : is) {
                    int prevID = l.get(index)[1];
                    if (prevID > id) {
                        invalid = true;
                        if (is[is.length - 1] < prevID) {
                            result.add(l.get(index)[0] + ";" + name + ";SHORTENED_JOB");
                        }
                    }
                    index++;
                }
                prev = Math.max(prev, is[is.length - 1]);
                if (invalid && is.length > 1) {
                    result.add(i + 1 + ";" + name + ";SUSPICIOUS_BATCH");
                }
                map.remove(name);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        String[] testCase1 = new String[]{"A;START", "B;START", "B;1", "C;START", "A;15", "C;6", "D;START", "D;24", "E;START", "E;24", "E;START", "E;18", "F;START"};
        String[] testCase2 = new String[]{"L;START", "L;10", "A;START", "A;START", "A;8,14"};
        String[] testCase3 = new String[]{"L;START", "L;10", "A;START", "A;START", "A;8,9"};
        String[] testCase4 = new String[]{"L;START", "A;START", "A;START", "L;10", "A;8,9"};
        String[] testCase5 = new String[]{"D;START", "A;START","C;START", "C;28", "D;24", "A;18"};
        String[] testCase6 = new String[]{"T;START", "J;START","D;START", "J;4", "D;2", "J;START","L;START","J;5","N;START","T;1", "N;6","L;3"};
        String[] testCase7 = new String[]{"Jeremy;START","Leah;START","Leah;50","Jeremy;START","Leah;START","Leah;100","Jeremy;START","Leah;START","Leah;150","Jeremy;START","Jeremy;37,52,68,86","John;START","John;START","John;500,5000"};
        String[] testCase8 = new String[]{"L;START", "L;10", "A;START", "A;START","A;START", "A;8,9,10"};
        System.out.println(invalidInvoices(testCase1));
        System.out.println(invalidInvoices(testCase2));
        System.out.println(invalidInvoices(testCase3));
        System.out.println(invalidInvoices(testCase4));
        System.out.println(invalidInvoices(testCase5));
        System.out.println(invalidInvoices(testCase6));
        System.out.println(invalidInvoices(testCase7));
        System.out.println(invalidInvoices(testCase8));
    }

}
