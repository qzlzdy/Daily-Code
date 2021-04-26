//============================================================================
// Name        : HDOJ_1023.java
// Author      : Qzlzdy
// Version     : Java
// Description : Train Problem II
//============================================================================
import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    private static ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
    
    static {
        arr.add(new BigInteger("1"));
    }
    
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        int N;
        while(kb.hasNext()) {
            N = kb.nextInt();
            for(int i = arr.size(); i < N; i++) {
                BigInteger tmp = arr.get(i - 1);
                tmp = tmp.multiply(new BigInteger(String.valueOf(4 * i + 2)));
                tmp = tmp.divide(new BigInteger(String.valueOf(i + 2)));
                arr.add(tmp);
            }
            System.out.println(arr.get(N - 1));
        }
        kb.close();
    }

}
