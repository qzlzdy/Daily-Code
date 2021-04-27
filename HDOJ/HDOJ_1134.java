//============================================================================
// Name        : HDOJ_1134.java
// Author      : Qzlzdy
// Version     : Java
// Description : Game of Connections
//============================================================================
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        while(kb.hasNext()) {
            int n = kb.nextInt();
            if(n == -1)
                break;
            BigInteger big = BigInteger.ONE;
            for(int i = 1; i <= n; i++) {
                big = big.multiply(new BigInteger(Integer.toString(4 * i - 2)));
                big = big.divide(new BigInteger(Integer.toString(i + 1)));
            }
            System.out.println(big.toString());
        }
        kb.close();
    }

}
