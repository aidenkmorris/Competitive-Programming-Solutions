/**
 * @author Aiden K Morris
 * Original problem: https://open.kattis.com/problems/starguardians
 */
import java.util.*;

public class StarGuardians {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int[] additional = new int[n];
        int[] ability = new int[n];
        double average = 0.0;

        for(int i = 0; i < n; i++) {
            additional[i] = input.nextInt();
        }

        for(int i = 0; i < n; i++) {
            ability[i] = input.nextInt();
        }

        Arrays.sort(ability);

        // Calculate
        for(int i = 0; i < n; i++) {
            int calcAbility = 0;
            for(int j = n - 1; j >= n - (i + 1); j--) calcAbility += ability[j];

            double calcAverage = (1.0 * calcAbility + additional[i]) / (i + 1);
            average = (calcAverage > average) ? calcAverage : average;
        }

        System.out.println(average);
        input.close();
    }
}
