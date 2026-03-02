/**
 * Written by Aiden K Morris
 * Original problem: https://open.kattis.com/problems/lightup
 */
import java.util.*;

public class LightUp {
    private static Scanner input = new Scanner(System.in);
    private static char[][] grid;
    private static int n;

    private static boolean charIn(char c, String s) {
        for(int i = 0; i < s.length(); i++) {
            if(c == s.charAt(i)) return true;
        }

        return false;
    }

    private static boolean light(int r, int c) {
        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(int[] direction : directions) {
            int row = r + direction[0];
            int col = c + direction[1];

            while(row > -1 && row < n && col > -1 && col < n
                    && (charIn(grid[row][col], "*.?"))) {
                if(grid[row][col] == '?') return false;

                grid[row][col] = '*';
                row += direction[0];
                col += direction[1];
            }
        }

        return true;
    }

    private static boolean checkLight(int r, int c) {
        int num = grid[r][c] - '0';
        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int count = 0;

        for(int[] direction : directions) {
            int row = r + direction[0];
            int col = c + direction[1];

            if(row > -1 && row < n && col > -1 && col < n
                    && grid[row][col] == '?') {
                count += 1;
            }
        }

        return count == num;
    }
    
    public static void main(String[] args) {
        n = input.nextInt();
        grid = new char[n][n];

        // Get all input
        for(int i = 0; i < n; i++) {
            String line = input.next();

            for(int j = 0; j < n; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                char cell = grid[row][col];

                if(cell == '?') {
                    if(!light(row, col)) {
                        System.out.println(0);
                        return;
                    }
                }

                if (Character.isDigit(cell)) {
                    if(!checkLight(row, col)) {
                        System.out.println(0);
                        return;
                    }
                }
            }
        }

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '.') {
                    System.out.println(0);
                    return;
                }
            }
        }

        System.out.println(1);
        return;
    }
}