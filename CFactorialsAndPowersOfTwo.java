import java.util.*;

public class CFactorialsAndPowersOfTwo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        
        ArrayList<Long> fact = new ArrayList<>();

        long temp = 1;

        for(int i = 1; i <= 14; i++) {
            temp *= i;

            if(i >= 3) {
                fact.add(temp);
            }
        }

        int t = sc.nextInt();

        while(t-- > 0) {

            long n = sc.nextLong();

            int ans = Integer.MAX_VALUE;


            for(int mask = 0; mask < (1 << 12); mask++) {

                long sum = 0;
                int cnt = 0;

                for(int j = 0; j < 12; j++) {

                    // If jth bit is set
                    if((mask & (1 << j)) != 0) {

                        sum += fact.get(j);
                        cnt++;
                    }
                }


                if(sum > n) continue;


                long remaining = n - sum;

                cnt += Long.bitCount(remaining);

                ans = Math.min(ans, cnt);
            }

            ans = Math.min(Long.bitCount(n) , ans);
            System.out.println(ans);
        }

        sc.close();
    }
}