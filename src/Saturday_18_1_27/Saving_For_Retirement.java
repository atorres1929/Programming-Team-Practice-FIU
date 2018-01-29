package Saturday_18_1_27;

import java.util.Scanner;

public class Saving_For_Retirement {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int bobAge = scanner.nextInt();
        int bobRetireAge = scanner.nextInt();
        int bobSavingRate = scanner.nextInt();
        int aliceAge = scanner.nextInt();
        int aliceSaveRate = scanner.nextInt();


        int bobWorkAge = bobRetireAge - bobAge;
        int bobSavings = bobWorkAge * bobSavingRate;

        int aliceWorkAge = (bobSavings / aliceSaveRate) + 1;

        System.out.println(aliceAge + aliceWorkAge);
    }

}
