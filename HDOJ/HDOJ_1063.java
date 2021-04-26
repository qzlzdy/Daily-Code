//============================================================================
// Name        : HDOJ_1063.java
// Author      : Qzlzdy
// Version     : Java
// Description : Exponentiation
//============================================================================
import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
    
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        while(kb.hasNext()) {
            BigDecimal R = kb.nextBigDecimal();
            int n = kb.nextInt();
            R = R.pow(n);
            String result = R.stripTrailingZeros().toPlainString();
            if(result.charAt(0) == '0')
                result = result.substring(1);
            System.out.println(result);
        }
        kb.close();
    }

}

