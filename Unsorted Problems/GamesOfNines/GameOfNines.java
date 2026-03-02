/**
 * Written by Aiden K Morris
 * Original problem: https://open.kattis.com/problems/gameofnines
 */
import java.util.*;

public class GameOfNines {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int[] digits = new int[n];

        for(int i = 0; i < n; i++) digits[i] = input.nextInt();
        input.close();

        for(int mod : new int[]{2, 5}) {
            boolean noncondensible = true;

            for(int i = 0; i < n; i++) {
                if(digits[i] % mod != 0) {
                    noncondensible = false;
                    break;
                }
            }

            if(noncondensible) {
                System.out.println(n);
                return;
            }
        }

        System.out.println(1);
    }
}
