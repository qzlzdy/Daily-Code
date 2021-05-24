//============================================================================
// Name        : HDOJ_2054.cpp
// Author      : Qzlzdy
// Version     : Java
// Description : A == B ?
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
            if(A.compareTo(B) == 0)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
        kb.close();
    }

}