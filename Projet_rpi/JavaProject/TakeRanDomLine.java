
/**
 * Write a description of class TakeRanDomLine here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;


public class TakeRanDomLine{ 
    public static String RamdonLine(){
        String test="";
        try{
            Random random = new Random();
            int randomInt = random.nextInt(10); // 112 is the number of line we have in the file
            FileReader fr = new FileReader("question/easyTrueQuestion.txt"); // Change adress of the file
            BufferedReader reader = new BufferedReader(fr);
            String line = reader.readLine();
            for (int i = 0; i < randomInt; i++) {
                line = reader.readLine();
            }
            
            test=line;
            
            //JOptionPane.showMessageDialog(null,line);
        }catch (IOException e){
            //JOptionPane.showMessageDialog(null,e.getMessage()+" for lol.txt","File Error",JOptionPane.ERROR_MESSAGE);
        }
        
        return test;
        
    }
    
    public static void main (String[]args){
        
        System.out.println("Youpi!");
    }
}
