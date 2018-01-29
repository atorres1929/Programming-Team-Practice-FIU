package Jan_20_Practice;

import java.util.Scanner;

public class Staircase {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();

        int numHash = 1;
        int numSpace = size - 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < numSpace; j++) {
                System.out.print(" ");
            }
            for (int k = 0; k < numHash; k++) {
                System.out.print("#");
            }
            System.out.println();
            numSpace--;
            numHash++;
        }

        scanner.close();
    }

}
