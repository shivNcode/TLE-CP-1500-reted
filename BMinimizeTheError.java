
import java.util.*;

public class BMinimizeTheError {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k1 = sc.nextInt();
        int k2 = sc.nextInt();

        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
            pq.add(Math.abs(a[i] - b[i]));
        }

        int k = k1 + k2;

        while (k-- > 0) {

            int x = pq.poll();

            if (x > 0) {
                x--;
            } else {
                x = 1;
            }

            pq.add(x);
        }

        long ans = 0;

        for (int x : pq) {
            ans += 1L * x * x;
        }

        System.out.println(ans);

        sc.close();
    }
}