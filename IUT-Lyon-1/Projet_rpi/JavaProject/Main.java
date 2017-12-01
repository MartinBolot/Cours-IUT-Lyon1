
/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.util.Scanner;
import java.io.*;

public class Main
{
    //contains the only main method, is to be launched with launch.sh
    
    public static void main(String args[]){ 
        
       Game newGameInstance = new Game(/*"easy"*/);
       newGameInstance.init();
        
    }
    
}
