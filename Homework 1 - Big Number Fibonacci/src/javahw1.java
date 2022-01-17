import java.util.Scanner;
import java.math.BigInteger;

public class javahw1 {
  public static void main(String[] args) {
    if (args.length != 1) {
      System.out.println("[usage]:java hw1 n");
      return;
    }
    int n = Integer.parseInt(args[0]);
    if (n < 1 || n > 99) {
      System.out.println("The integer argument should locate between 1 to 99");
      return;
    }
    System.out.printf("The input number is %d\n", n);
    BigInteger num = BigInteger.valueOf(n);
    System.out.printf("f(%d) = %d\n", n, f(num));
    return;
  }

  public static BigInteger f(BigInteger n) { //fibonacci function using loop
    if (n.compareTo(BigInteger.valueOf(1)) == 0 ||
     n.compareTo(BigInteger.valueOf(2)) == 0)
      return BigInteger.valueOf(1);
    BigInteger p1 = BigInteger.valueOf(1), p2 = BigInteger.valueOf(1);
    BigInteger ret = p1.add(p2);//f1 = 1, f2 = 1, f3 = 2 
    int i = 0;
    for (i = 3; n.compareTo(BigInteger.valueOf(i)) > 0; i++) {
      p1 = p2;
      p2 = ret;
      ret = p1.add(p2);
    }
    return ret;
  }
}
