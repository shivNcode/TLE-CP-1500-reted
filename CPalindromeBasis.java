import java.util.*;

public class CPalindromeBasis {

    public static boolean check(int num) {
        String str = Integer.toString(num);
        String reversed = new StringBuilder(str).reverse().toString();

        return str.equals(reversed);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        int N = 100005;
        long mod = 1000000007L;

        ArrayList<Integer> arr = new ArrayList<>();

        for (int i = 1; i < N; i++) {
            if (check(i)) {
                arr.add(i);
            }
        }

        long[] dp = new long[N + 1];

        dp[0] = 1;

        for (int i = 0; i < arr.size(); i++) {

            int coin = arr.get(i);

            for (int j = coin; j <= N; j++) {

                dp[j] = (dp[j] + dp[j - coin]) % mod;
            }
        }

        while (t-- > 0) {

            int n = sc.nextInt();

            System.out.println(dp[n]);
        }

        sc.close();
    }
}