package td_tests;

/**
 * First problem
 * @author Martin BOLOT - Fanny ROTTEE
 */
public class Probleme1 {
    
    /**
    *   Method to invert two last letters
    *   @param originalString the original string
    *   @return newString - the newly formed string
    */
    public static String invertLastTwoLetters(String originalString){
        int length = originalString.length();
        int lastPos = length-1;
        String newString,revertedEnd;
        
        if(length >= 2){
            revertedEnd = String.valueOf(originalString.charAt(lastPos)) + String.valueOf(originalString.charAt(lastPos-1));
            if(length == 2){
                newString = revertedEnd;
            }else{
                newString = originalString.substring(0,lastPos-1) + revertedEnd;
            }
        }else{
            newString = originalString;
        }
        
        return newString;
    }
}
