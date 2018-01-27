package Saturday_18_1_27;

import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Scanner;

public class Primal_Representation {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int subject = scanner.nextInt();
            String output;
            if (subject < 0) {
                subject *= -1;
                output = "-1 ";
            } else {
                output = "";
            }

            Hashtable<Integer, Integer> primeNumberMultiples = new Hashtable<>();

            if (subject == 1) {
                System.out.println(1);
            } else if (subject == -1) {
                System.out.println(-1);
            } else {
                for (int i = subject; i >= 0; i--) {

                    int primeNumber;
                    if (isPrime(i)) {
                        primeNumber = i;

                        if (subject == 1) {
                            break;
                        }

                        boolean canDivide = true;
                        int numTimesRepeated = 0;
                        while (canDivide) {
                            if (subject % primeNumber == 0) {
                                subject /= primeNumber;
                                numTimesRepeated++;
                            } else {
                                canDivide = false;
                            }
                        }

                        if (numTimesRepeated > 0) {
                            primeNumberMultiples.put(primeNumber, numTimesRepeated);
                        }
                    }
                }

                Enumeration<Integer> keys = primeNumberMultiples.keys();
                while (keys.hasMoreElements()) {
                    int multiple = keys.nextElement();
                    int exponent = primeNumberMultiples.get(multiple);
                    if (exponent > 1) {
                        output += multiple + "^" + exponent + " ";
                    } else {
                        output += multiple + " ";
                    }
                }
                System.out.println(output.trim());
            }
        }
    }

    private static boolean isPrime(int num) {
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }

}
