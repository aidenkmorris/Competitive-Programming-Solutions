/**
 * Written by Aiden Morris
 * Original solution: https://open.kattis.com/problems/snakeystring
 */
import java.util.Scanner;

public class SnakeyString {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int r = input.nextInt();
        int c = input.nextInt();
        input.nextLine();

        char[][] grid = new char[r][c];

        for(int i = 0; i < r; i++) {
            String line = input.nextLine();
            
            for(int j = 0; j < c; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        String answer = "";

        for(int j = 0; j < c; j++) {
            for(int i = 0; i < r; i++) {
                if(grid[i][j] == '.') continue;
                else {
                    answer += grid[i][j];
                    break;
                }
            }
        }

        System.out.println(answer);
        input.close();
    }
}
