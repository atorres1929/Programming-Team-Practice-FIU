import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class SnakesLadders {

    static int quickestWayUp(int[][] ladders, int[][] snakes) {
        int smallest = findSmallest(ladders);
        int position = 1;
        for (int i = 0; i < ladders.length; i++) {
            int addition = 6;
            if (position + addition < smallest) {
                boolean snakePath = true;
                while (snakePath) {
                    if (checkSnakeStartingPoint(snakes, position + addition)) {
                        position += 6;
                        snakePath = false;
                    } else {
                        addition--;
                        if (addition == 0) {

                        }
                    }
                }
            }
        }
        return -1;
    }

    static int findLargestSnakeEnd(int[][] snakes, int nextPosition, ArrayList<Integer> bannedIndexes) {
        int largest = Integer.MIN_VALUE;
        int index = 0;
        for (int i = 0; i < snakes.length; i++) {
            if (!bannedIndexes.contains(i)) {
                if (snakes[i][1] > largest) {
                    index = i;
                    largest = snakes[i][1];
                }
            }
        }
        if (snakes[index][0] != nextPosition) {
            bannedIndexes.add(index);
            if (bannedIndexes.size() == snakes.length) {
                bannedIndexes.clear();
                findLargestSnakeEnd(snakes, nextPosition - 1, bannedIndexes);
            }
            else {
                findLargestSnakeEnd(snakes, nextPosition, bannedIndexes);
            }
        }
        return index;
    }

    static boolean checkSnakeStartingPoint(int[][] snakes, int position) {
        for (int i = 0; i < snakes.length; i++) {
            if (snakes[i][0] == position) {
                return true;
            }
        }
        return false;
    }

    static int findSmallest(int[][] ladders) {
        int smallest = Integer.MAX_VALUE;
        int index = 0;
        for (int i = 0; i < ladders.length; i++) {
            if (ladders[i][0] < smallest) {
                index = i;
                smallest = ladders[i][0];
            }
        }
        ladders[index][0] = Integer.MAX_VALUE;
        return index;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            int n = in.nextInt();
            int[][] ladders = new int[n][2];
            for (int ladders_i = 0; ladders_i < n; ladders_i++) {
                for (int ladders_j = 0; ladders_j < 2; ladders_j++) {
                    ladders[ladders_i][ladders_j] = in.nextInt();
                }
            }
            int m = in.nextInt();
            int[][] snakes = new int[m][2];
            for (int snakes_i = 0; snakes_i < m; snakes_i++) {
                for (int snakes_j = 0; snakes_j < 2; snakes_j++) {
                    snakes[snakes_i][snakes_j] = in.nextInt();
                }
            }
            int result = quickestWayUp(ladders, snakes);
            System.out.println(result);
        }
        in.close();
    }
}
