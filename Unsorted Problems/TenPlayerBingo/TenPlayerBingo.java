/**
 * @author Aiden K Morris
 * Original problem: https://open.kattis.com/problems/tenplayerbingo
 */
import java.util.Scanner;

public class TenPlayerBingo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = 0;

        while(input.hasNext()) {
            num = input.nextInt();
        }

        System.out.println(num % 10 == 0 ? 10 : num % 10);
    }
}
