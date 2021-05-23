//============================================================================
// Name        : HDOJ_1753.java
// Author      : Qzlzdy
// Version     : Java
// Description : 大明A+B
//============================================================================
import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
    
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        BigDecimal A, B;
        while(kb.hasNext()) {
            A = kb.nextBigDecimal();
            B = kb.nextBigDecimal();
            System.out.println(A.add(B).stripTrailingZeros().toPlainString());
        }
        kb.close();
    }

}