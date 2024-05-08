import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner; 
public class Battleship{
    public static void main(String[] args) throws IOException {
        boolean close_console=true, setting=false, close_setting;
        int i, j, arr_count, score, corect_count, bot_count, false_count, rows_and_columns=5, x, y, k, first_random, seccond_random, count=0, first_coordinates, seccond_coordinates, x_attack, y_attack, seccond_count=0, third_count=0;
        char[][] field = new char[9999][9999/2];
        char[][] enemy = new char[9999][9999/2];
        char[][] true_enemy = new char[9999][9999/2];
        String[] arr_name = new String[9999];
        int[] arr_score = new int[9999];
        String close, your_name;
        
        arr_count=0;
        while (close_console) {
            instructions(); 

            Scanner print = new Scanner(System.in);
            int first_action = print.nextInt();

            clear_screen();

            switch (first_action) {
                case 1: {
                    //Check if the player has adjusted the settings or not
                    if (!setting) {
                        adjust();
                        close = print.next();
                        clear_screen ();
                        break;
                    }
                    else {
                        name();
                        your_name = print.next();

                        clear_screen();  

                        corect_count=0;
                        false_count=0;
                        bot_count=0;
                        long start = System.currentTimeMillis();
                        while (true) {  
                            long finish = System.currentTimeMillis();
                            long timeElapsed = (finish - start)/1000;

                            score=corect_count+(rows_and_columns/(false_count+1))+(rows_and_columns-bot_count);

                            //Displaying the battlefield
                            for (i=0;i<rows_and_columns;i++) 
                            for (j=0;j<rows_and_columns/2;j++) { 
                                System.out.print(field[i][j]+" ");
                                if (j==(rows_and_columns/2)-1) {
                                    System.out.print("| ");
                                    for (k=0;k<rows_and_columns/2;k++)
                                    System.out.print(enemy[i][k]+" ");
                                    System.out.print("\n");  
                                    if (i+1==rows_and_columns && j+1==rows_and_columns/2) {
                                        System.out.print("\n");
                                        System.out.println("Score:"+(score)+" | Elapsed Time:"+timeElapsed+"s");
                                        System.out.print("\n");
                                        shoot();
                                    }
                                } 
                            }

                            //Receiving the coordinates of shooting
                            first_coordinates = print.nextInt();
                            seccond_coordinates = print.nextInt();
                            if (true_enemy[rows_and_columns-seccond_coordinates][first_coordinates-1]=='*') {
                                enemy[rows_and_columns-seccond_coordinates][first_coordinates-1]='1';
                                corect_count++;
                                }
                            if (true_enemy[rows_and_columns-seccond_coordinates][first_coordinates-1]=='#') {
                                enemy[rows_and_columns-seccond_coordinates][first_coordinates-1]='0';
                                false_count++;
                            }
                            
                            clear_screen();

                            //Counting wrecked ships of enemy
                            seccond_count=0;
                            for (i=0;i<rows_and_columns;i++) 
                            for (j=0;j<rows_and_columns/2;j++) {
                                if (enemy[i][j]=='1') 
                                seccond_count++;
                            }

                            //Check if the player has won
                            if (seccond_count==rows_and_columns) {
                                System.out.print("YOU WON!"+"\n"+"\n");
                                exit();

                                //Storing the winners record
                                arr_name[arr_count]=your_name;
                                arr_score[arr_count]=score;
                                arr_count++;
                                File myObj = new File("filename.txt");
                                FileWriter myWriter = new FileWriter("filename.txt");
                                myWriter.write("Name"+"\t"+"|"+"    Score"+"\n");
                                for (i=0;i<arr_count;i++)
                                myWriter.write(arr_name[i]+"\t"+"|    "+arr_score[i]+"\n");
                                myWriter.close();

                                close = print.next();
                                clear_screen ();
                                setting=false;
                                break;
                            }

                            //Shooting the player ships with random coordinates
                            for (i=0;;i++) {
                                x_attack=random_number(1, rows_and_columns/2);
                                y_attack=random_number(1, rows_and_columns);

                                if (field[rows_and_columns-y_attack][x_attack-1]=='*') {
                                    field[rows_and_columns-y_attack][x_attack-1]='1';
                                    bot_count++;
                                    break;
                                }
                                if (field[rows_and_columns-y_attack][x_attack-1]=='#') {
                                    field[rows_and_columns-y_attack][x_attack-1]='0';
                                    break;
                                }                                 
                            }

                            //Counting wrecked ships of player
                            third_count=0;
                            for (i=0;i<rows_and_columns;i++) 
                            for (j=0;j<rows_and_columns/2;j++) {
                                if (field[i][j]=='1') 
                                third_count++;
                            }

                            //Check if the player has lost
                            if (third_count==rows_and_columns && third_count!=0) {
                                System.out.print("GAME OVER!"+"\n"+"\n");
                                exit();
                                close = print.next();
                                clear_screen ();
                                setting=false;
                                break;
                            }
                        }
                    }                   
                }
                break;
                case 2: {
                    settings (); 

                    //Receiving number of rows and columns
                    close_setting=true;
                    while (close_setting) {
                        rows_and_columns = print.nextInt();
                        if (rows_and_columns%2==0 || rows_and_columns<5 || rows_and_columns>20) {
                            System.out.println("Please pay attention to the description...");
                        }
                        else
                        close_setting=false;
                    }

                    //Making the battlefield
                    for (i=0;i<rows_and_columns;i++)
                    for (j=0;j<rows_and_columns/2;j++) {
                        field[i][j]='#';  
                        enemy[i][j]='#';  
                        true_enemy[i][j]='#';
                    }

                    //Putting ships of enemy in random coordinates
                    count=0;
                    for (i=0;;i++) {
                        first_random= random_number(0, (rows_and_columns-1));
                        seccond_random=random_number(0, ((rows_and_columns/2)-1));
                        if (true_enemy[first_random][seccond_random]=='#') {
                            true_enemy[first_random][seccond_random]='*';
                            count++;
                        }
                        if (count==rows_and_columns)
                        break;
                    }

                    //Receiving the coordinates of the player's ships
                    ships();
                    i=0;
                    while (true) {
                        x = print.nextInt();
                        y = print.nextInt();
                        if (field[rows_and_columns-y][x-1]=='#') {
                            field[rows_and_columns-y][x-1]='*';
                            i++;
                        }
                        if (i==rows_and_columns)
                        break;
                    }

                    clear_screen ();

                    setting=true;
                }
                break;
                case 3: { 
                    //Displaying the winners record
                    File myObj = new File("filename.txt");
                    Scanner myReader = new Scanner(myObj);
                    while (myReader.hasNextLine()) {
                      String data = myReader.nextLine();
                      System.out.println(data);
                    }
                    System.out.print("\n");
                    myReader.close();
                    exit();
                    close = print.next();
                    clear_screen ();
                }
                break;
                case 4: close_console=false;
                break;
            }
        }
    }

    static void settings() {
        System.out.println("Please enter the size of the rows and columns of battlefield (they should be equal, odd and between five and twenty):"+"\n"+"Input: ");
    }

    static void instructions() {
        System.out.print("1. Start Game"+"\n"+"2. Settings"+"\n"+"3. Records"+"\n"+"4. Exit"+"\n"+"Input: ");
    }

    static void clear_screen() {
        System.out.print("\033[H\033[2J");
    }

    static void ships() {
        System.out.println("Please enter the coordinates of the ships:");
    }

    static void adjust() {
    System.out.print("Please adjust the settings first"+"\n"+"\n"+"Press any key to exit... ");
    }

    static void name() {
    System.out.print("Enter your name please: ");
    }

    static int random_number(int min, int max) {
        return (int)Math.floor(Math.random()*(max-min+1)+min);
    }

    static void shoot() {
        System.out.println("Please enter the shooting coordinates:");
    }

    static void exit() {
        System.out.print("Press any key to exit... ");
    }
}