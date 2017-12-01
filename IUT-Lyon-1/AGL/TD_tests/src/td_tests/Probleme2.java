package td_tests;

/**
 * Second problem
 * @author Martin BOLOT - Fanny ROTTEE
 */
public class Probleme2 {
    /**
    *   Method to remove "a" letter in the fist two letters of a string
    *   @param originalString the original string
    *   @return newString - the newly formed string
    */
    public static String removeA(String originalString){
        String newString;
        
        if(originalString.length() >= 2){
            if(originalString.charAt(0) == 'a' && originalString.charAt(1) == 'a'){
                newString = originalString.substring(2);
            }else if(originalString.charAt(0) == 'a'){
                newString = originalString.substring(1);
            }else if(originalString.charAt(1) == 'a'){
                newString = String.valueOf(originalString.charAt(0)) + originalString.substring(2);
            }else{
                newString = originalString;
            }
        }else{
            if(originalString.equals("a")){
                newString = "";
            }else{
                newString = originalString;
            }
        }
        return newString;
    }
}
