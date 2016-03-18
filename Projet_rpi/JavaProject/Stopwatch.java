
/**
 * Write a description of class Stopwatch here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;
public class Stopwatch
{
    static int interval;
    static Timer timer;
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Input seconds: ");
        String secs = sc.nextLine();
        
        
        int period=1000;
        int delay=1000;
        String ans="";
        boolean qanswer = true;
        
        Scanner sc2 = new Scanner(System.in);
        timer= new Timer();
        interval = Integer.parseInt(secs);
        System.out.println(secs);
        timer.scheduleAtFixedRate(new TimerTask() {
           
            public void run() {
                System.out.println(setInterval());
                ans = sc2.nextLine();
                //sc2.close();
                
                
            }
            
            
        }, delay, period);
        
        
        System.out.println("Answer: ");
        if (ans!="") qanswer=false;
        
        
        
        System.out.println("answer: " +qanswer);
        
        return;
    }

    private static final int setInterval() {
    
        if (interval == 1){
            System.out.println("Too late");
            timer.cancel();
        }
        return --interval;
    }
    
}
    
    
