
/**
 * Write a description of class Question here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Question extends Main{
    //constructors
    public Question(){
        id=idMax++;
        sentence="";
        rightAnswer=true;
        difficulty=1;
        used=false;
    }
    public Question(String _sentence,boolean _rightAnswer,int _difficulty){
        id=idMax++;
        used=false;
        
        sentence=_sentence;
        if(_difficulty <= 3 && _difficulty >= 1){
            difficulty=_difficulty;
        }else{throw new Error("error : diffculty out of range");}
        rightAnswer=_rightAnswer;
    }
    
    //getters
    public static int getIdMax(){
        return idMax;
    }
    public int getId(){
        return id;
    }
    public String getSentence(){
        return sentence;
    }
    public boolean getRightAnswer(){
        return rightAnswer;
    }
    public int getDifficulty(){
        return difficulty;
    }
    public boolean getUsed(){
        return used;
    }
    //setters
    public void setSentence(String _sentence){
        sentence = _sentence;
    }
    public void setRightAnswer(boolean _rightAnswer){
        rightAnswer = _rightAnswer;
    }
    public void setDifficulty(int _difficulty){
        if(_difficulty <= 3 &&_difficulty >= 1){
            difficulty=_difficulty;
        }else{throw new Error("error : diffculty out of range");}
    }
    public void setUsed ( boolean _use){
        used=_use;
    }
    //methods
    @Override public String toString(){
        return "Question : "+sentence+"\n"+" righteousness : "+(rightAnswer?"true":"false")+"\n difficulty : "+difficulty;
    }
    public void displayQuestion(){
        System.out.println(sentence);
    }
    
    private static int idMax;
    private int id;
    private String sentence;
    private boolean rightAnswer;
    private int difficulty; //int between 1 and 3 => 1 : easy, 2 : medium, 3 : hard
    private boolean used;
}
