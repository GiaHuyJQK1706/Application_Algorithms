//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    public static void main(String[] args) { 
        TreeMap<String, Integer> wordCount = new TreeMap<>();
        Scanner sc = new Scanner(System.in);

        String line;
        int cel = 0;

        while(sc.hasNextLine()){
            line = sc.nextLine();
            if (line.isEmpty()){
                cel++;
                if (cel > 0){
                    break;
                }
            } else {
                cel = 0;
                String[] word = line.split("\s+");
                for (String w : word){
                    w = w.replaceAll("[.,]","");
                    w = w.toLowerCase();
                    wordCount.put(w,wordCount.getOrDefault(w,0)+1);
                }
            }
        }
        
        for (String w : wordCount.keySet()){
            int curr = wordCount.get(w);
            System.out.println(w + " " + curr);
        }
    }
}
