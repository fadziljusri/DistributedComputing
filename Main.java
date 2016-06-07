import java.util.regex.*;

public class Main
{
  public static void main (String[] args)
  {
     String example = "United Arab Emirates Dirham (fadzil) (jusri)";
     Matcher m = Pattern.compile("\\(([^)]+)\\)").matcher(example);
     while(m.find()) {
       System.out.println(m.group(1));    
     }
  }
}