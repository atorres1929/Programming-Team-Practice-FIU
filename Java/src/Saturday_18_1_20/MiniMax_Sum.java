import java.util.Arrays;
import java.util.Scanner;

public class MiniMax_Sum {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long[] longs = new long[5];

        for (int i = 0; i < 5; i++) {
            longs[i] = scanner.nextLong();
        }

        Arrays.sort(longs);

        long min = 0;
        for (int i = 0; i < longs.length - 1; i++) {
            min += longs[i];
        }

        long max = 0;
        for (int i = 1; i < longs.length; i++) {
            max += longs[i];
        }

        System.out.println(min + " " + max);
        scanner.close();
    }
}
