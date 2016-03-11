
/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.util.Scanner;


public class Main
{
    //contains the only main method, is to be launched with launch.sh
    
    public static void main(String args[]){ 
        System.out.println("Welcome In The Wrong Button. \n Press Enter to Start");
        
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        System.out.println("You pressed enter ! congratulations");
        
        //Game newGameInstance = new Game("easy");
        Question q1 = new Question("Is Arthur a cool guy ?",true,1);
        q1.displayQuestion();
        
        
        
       
    }
    
}
