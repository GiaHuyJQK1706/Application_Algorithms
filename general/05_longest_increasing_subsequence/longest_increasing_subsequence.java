//JAVA 
import java.util.*; 
/*
Note: thời gian chạy khá chậm, chỉ ăn 60/100 điểm
**/
@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    public static int findLongestIncreasingSubsequence(Vector<Integer> sequence) {
        int n = sequence.size();
        Vector<Integer> lis = new Vector<>(n);

        for (int i = 0; i < n; ++i) {
            lis.add(1);
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (sequence.get(i) > sequence.get(j) && lis.get(i) < lis.get(j) + 1) {
                    lis.set(i, lis.get(j) + 1);
                }
            }
        }

        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            if (lis.get(i) > maxLength) {
                maxLength = lis.get(i);
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Vector<Integer> sequence = new Vector<>(n);

        for (int i = 0; i < n; ++i) {
            sequence.add(scanner.nextInt());
        }

        int longestIncreasingSubsequenceLength = findLongestIncreasingSubsequence(sequence);

        System.out.println(longestIncreasingSubsequenceLength);

        scanner.close();
    }
}
