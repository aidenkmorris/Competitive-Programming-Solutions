/**
 * Solution by Aiden K Morris
 * Original problem: https://nasouth25.kattis.com/contests/nasouth25d2/problems/memoriesofpassportcontrol
 */
import java.util.Scanner;

public class MemoriesOfPassportControl {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int k = input.nextInt();
        int s = input.nextInt();

        int output = s / k + s % k;
        System.out.println(output);
        input.close();
    }
}
