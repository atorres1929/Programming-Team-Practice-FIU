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
            int[] possibleHearts = new int[country.length];


            //Fills up possibleHearts
            for (int c = 0; c < possibleHearts.length; c++) {

                int sum = country[c][0];
                for (int i = 2; i < country[c].length; i++) {
                    sum += country[country[c][i]][0];
                }

                possibleHearts[c] = sum;
            }


            //Finds the heart of the country
            int max = 0;
            int index = -1;
            for (int i = 0; i < possibleHearts.length; i++){
                if (possibleHearts[i] > max) {
                    max = possibleHearts[i];
                    index = i;
                }
            }

            int connections = country[index][1]; //fetches the connections from the proper index


            //plus one because it includes the city and all it's connections
            System.out.println(connections+1 + " " + max);
        }
    }
}

//Time 46