import java.util.*;

public class LControllers {

    // Function to calculate GCD
    public static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to calculate LCM
    public static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String str = sc.next();

        int pos = 0;
        int neg = 0;

        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);

            if (ch == '+') {
                pos++;
            } else {
                neg++;
            }
        }

        int q = sc.nextInt();

        while (q-- > 0) {

            long a = sc.nextLong();
            long b = sc.nextLong();

            long mx = Math.max(a, b);
            long mn = Math.min(a, b);

            a = mx;
            b = mn;

            if (pos == neg) {
                System.out.println("YES");
                continue;
            }

            if (a == b) {
                System.out.println("NO");
                continue;
            }

            long l = lcm(a, b);

            long x = l / a;
            long y = l / b;

            long diff = Math.abs(pos - neg);

            if (diff % Math.abs(x - y) == 0) {

                long p = diff / Math.abs(x - y);

                if ((x + y) * p > n) {
                    System.out.println("NO");
                } else {
                    System.out.println("YES");
                }

            } else {
                System.out.println("NO");
            }
        }

        sc.close();
    }
}