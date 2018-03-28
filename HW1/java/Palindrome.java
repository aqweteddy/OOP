import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Palindrome{

    private static boolean check(String str){
        for(int i=0, j=str.length()-1; i<j; i++, j--){
            if(str.charAt(i)!=str.charAt(j)){
                return false;
            }
        }
        return true;
    }

	public static void main(String[] args){
        String inp=new String(args[0]);
		
        inp=inp.toLowerCase();
        inp=Pattern.compile("[^a-z]").matcher(inp).replaceAll("");
		
        System.out.println(check(inp) ? "Yes" : "No");
	}
}
