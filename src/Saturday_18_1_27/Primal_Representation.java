package Saturday_18_1_27;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.TreeMap;

public class Primal_Representation {

    public static void main(String[] args) {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        int sqrt = (int) Math.sqrt(Integer.MAX_VALUE);

        //create sieve of primes
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 3; i < sqrt; i += 2) {
            if (isPrime(i)) {
                primes.add(i);
            }
        }

        while (true) {
            int subject;
            try {
                subject = Integer.parseInt(scanner.readLine());
            } catch (Exception e) {
                break;
            }
            String output;
            if (subject < 0) {
                subject *= -1;
                output = "-1 ";
            } else {
                output = "";
            }

            TreeMap<Integer, Integer> primeNumberMultiples = new TreeMap<>();

            if (subject == 1) {
                if (output.length() == 0) {
                    output += "1";
                }
                System.out.println(output.trim());
            } else if (subject == 0) {
                System.out.println(0);
            } else {

                //Check for the only even prime number: 2
                int count = 0;
                while (subject % 2 == 0) {
                    subject /= 2;
                    count++;
                }

                if (count > 0) {
                    primeNumberMultiples.put(2, count);
                }

                int limit = subject / 2; //The maximum a prime multiple could be is half of the subject
                int prime = -1;
                //Check for every other prime number
                for (int i = 0; subject > 1 && i < primes.size() && prime < limit; i += 2) {

                    prime = primes.get(i);

                    //Count how many times the prime was used
                    int numTimesRepeated = 0;
                    while (subject % prime == 0) {
                        subject /= prime;
                        numTimesRepeated++;
                    }

                    //add the prime if it was used
                    if (numTimesRepeated > 0) {
                        primeNumberMultiples.put(prime, numTimesRepeated);
                    }

                }

                //If subject > 1 then it must be a prime number
                if (subject > 1) {
                    primeNumberMultiples.put(subject, 1);
                }


                //Print the primes
                for (Integer multiple : primeNumberMultiples.keySet()) {
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

        /* if i * i > num
         * then
         *      no point in checking further
         */
        int sqrt = (int) Math.sqrt(num);
        for (int i = 3; i <= sqrt; i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

}