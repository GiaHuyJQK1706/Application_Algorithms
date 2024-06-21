//JAVA 
import java.util.*; 

@SuppressWarnings({"unchecked", "deprecation"})
public class Main { 
    public static void main(String[] args) { 
        Queue<Integer> q = new LinkedList<>();
        int[] rs = new int[10000];

        int k=0;

        Scanner sc = new Scanner(System.in);

        while(true){
            String cmd = sc.next();
            if (cmd.equals("#")){
                break;
            } else if (cmd.equals("PUSH")){
                int curr = sc.nextInt();
                q.offer(curr);
            } else if (cmd.equals("POP")){
                if (!q.isEmpty()){
                    int tmp = q.peek();
                    rs[k] = tmp;
                    q.poll();
                }
                k++;
            }
        }

        for (int i=0;i<k;i++){
            if (rs[i] != 0){
                System.out.println(rs[i]);
            } else {
                System.out.println("NULL");
            }
        }
        
    }
}
