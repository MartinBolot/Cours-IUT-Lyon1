
/**
 * Write a description of class Game here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.util.Scanner;

public class Game
{
   public Game(){currentscore=0;maxScore=0;}
   //getters
   
   //setters
   public void addQuestion(Question newQuestion){}
   
   //methods
   public int resetGame(){currentscore=0;remainingLives=3;}
   
   public static boolean getAnswer(Question question){
       /* standby -- test cancelling nextLine
       question.displayQuestion();
       boolean userAnswer=false;
       Scanner sc = new Scanner(System.in);
       String input = sc.nextLine();
       
       userAnswer=true;
       return qAnswer;
       */
    }
    
   //array ? not array ?
   //private Question[][] questions = new Question[3][100];
   private int currentScore;
   private static int maxScore;
   private int remainingLives=3;
}
