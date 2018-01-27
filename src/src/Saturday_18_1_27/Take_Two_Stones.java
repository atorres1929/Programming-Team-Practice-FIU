package Saturday_18_1_27;

import java.util.Scanner;

public class Take_Two_Stones {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numStones = scanner.nextInt();
        boolean turnAlice = true;
        boolean turnBob = false;

        while (numStones > 1) {
            if (turnAlice) {
                numStones -= 2;
                turnAlice = false;
                turnBob = true;
            }
            else if (turnBob) {
                numStones -= 2;
                turnBob = false;
                turnAlice = true;
            }
        }
        if (numStones % 2 == 1) {
            System.out.println("Alice");
        }
        else {
            System.out.println("Bob");
        }
    }
}
