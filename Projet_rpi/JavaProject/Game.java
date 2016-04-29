
/**
 * Write a description of class Game here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;

public class Game
{
   public Game(){
       currentScore=0;
       maxScore=0;
       
       //todo => add a if to test the level of difficulty
       //loop that creates true questions
        try{
            FileReader fr = new FileReader("question/easyTrueQuestion.txt"); // Change adress of the file
            BufferedReader reader = new BufferedReader(fr);
            String line;
            while((line = reader.readLine())!=null){
                Question newQuestion = new Question(line,true,1);
                questions.add(newQuestion);
            }
        }catch (IOException e){ e.getMessage(); }
        
    }
   //getters
   
   //setters
   public void addQuestion(Question newQuestion){}
   
   //methods
   public void init(){
        //this.displayAllQuestions();
        
        System.out.println("Welcome In The Wrong Button. \n Press Enter to Start");
        
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        System.out.println("You pressed enter ! congratulations");
        do{
            Question currentQuestion = this.askRandomQuestion();
            try {
            BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
            String line = "test";
                while (line.equalsIgnoreCase("") == false) {
                    line = in.readLine();
                }
                
                in.close();
            }catch (IOException e){ e.getMessage(); }
            System.out.println(currentQuestion.getRightAnswer());
                
             //continue
             System.out.println("Press enter for another question, type 'exit' to quit");
             input = sc.nextLine();
        }while (!(input.equals("")));
   }
   
   public void displayAllQuestions(){
       for(Question iter : questions){
           System.out.println(iter);
        }
   }
   
   public Question askRandomQuestion(){
       Question currentQuestion;
       do {
           Random random = new Random();
           int randomInt = random.nextInt(questions.size());
           currentQuestion = questions.get(randomInt);
        }while ( currentQuestion.getUsed() == true);
        
        currentQuestion.displayQuestion();
        currentQuestion.setUsed(true);
        
        return currentQuestion;
        
        // here we need to listen to a keypress
        // here we need to display a timer
        // here we need to display the answer
   }
   public void playQuestion(Question q)
   {
       q.displayQuestion();
       
    }
   public void resetGame(){currentScore=0;remainingLives=3;}
   
   /* public static boolean getAnswer(Question question){
       standby -- test cancelling nextLine
       question.displayQuestion();
       boolean userAnswer=false;
       Scanner sc = new Scanner(System.in);
       String input = sc.nextLine();
       
       userAnswer=true;
       return qAnswer;
       
    }*/
    
   private ArrayList<Question> questions = new ArrayList<Question>();
   private int currentScore;
   private static int maxScore;
   private static boolean questionsAllUsed=false;
   private int remainingLives=3;
}
