package HeartOfCountry;

import java.util.Scanner;

/**
 * Created by Adam Torres on 1/16/2018
 */
public class HeartOfCountry {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true){
            int numCities = scanner.nextInt();
            int numTroops = scanner.nextInt();

            if (numCities == 0 && numTroops == 0){
                break;
            }

            /*
             * Data is entered into the array by rows
             * 0 = troops
             * 1 = highways
             * 2... = city connections
             */
            int[][] country = new int[numCities][];

            for (int c = 0; c < numCities; c++){
                int troops = scanner.nextInt();
                int highways = scanner.nextInt();

                //2 by default because troops and highways must also be stored
                country[c] = new int[2+highways];

                country[c][0] = troops;
                country[c][1] = highways;

                for (int h = 0, i =  2; h < highways; h++, i++){
                    int city = scanner.nextInt();
                    country[c][i] = city;
                }
            }

            //Values that will determine the heart of the city
            int[] cities = new int[country.length];

            for (int c = 0; c < cities.length; c++) {

                int max = Integer.MIN_VALUE;
                int index = -1;
                for (int i = 0; i < country.length; i++) {
                    int troops = country[i][0];
                    if (max < troops) {
                        max = troops;
                        index = i;
                    }
                }

                int sum = country[index][0];
                for (int i = 2; i < country[index].length; i++) {
                    sum += country[country[index][i]][0];
                }

                cities[c] = sum;
            }

            int max = 0;
            int index = -1;
            for (int i = 0; i < cities.length; i++){
                if (cities[i] > max) {
                    max = cities[i];
                    index = i;
                }
            }

            int connections = country[index][1];

            System.out.println(connections+1 + " " + max);
        }
    }
}

//Time 46