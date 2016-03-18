
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
        do{
        TakeRanDomLine takeRanDomLine = new TakeRanDomLine();
        String test = takeRanDomLine.RamdonLine();
    
         Question ques = new Question();
         ques.setSentence(test);
        
         ques.setUsed(true);
         
         ques.displayQuestion();
         System.out.println(ques.getUsed());
         System.out.println("Press enter for another question");
          input = sc.nextLine();
        }while (input.equals(""));
        
    }
    
}
