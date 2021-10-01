import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        String num;
        int N=in.nextInt();
        BigInteger [] count;
        BigInteger tmp,max;
        tmp=new BigInteger("0");
        max= new BigInteger("0");
        count=new BigInteger[36];
        char[] alpabet={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int[] result;
        result=new int[60];
        if(N==0)
        {
            N=in.nextInt();
            System.out.println("0");
        }
        else {
            for (int i = 0; i < 36; i++)
                count[i] = new BigInteger("0");
            for (int i = 0; i < N; i++) {
                tmp = new BigInteger("1");
                num = in.next();
                for (int j = num.length() - 1; j >= 0; j--) {
                    if (num.charAt(j) < 60)
                        count[num.charAt(j) - 48] = count[num.charAt(j) - 48].add(tmp);
                    else
                        count[num.charAt(j) - 55] = count[num.charAt(j) - 55].add(tmp);
                    tmp = tmp.multiply(new BigInteger("36"));
                }
            }
            N = in.nextInt();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < 36; j++) {
                    if (count[j].multiply(new BigInteger("35")).subtract(count[j].multiply(new BigInteger(String.valueOf(j)))).compareTo(max) >= 0) {
                        max = count[j].multiply(new BigInteger("35")).subtract(count[j].multiply(new BigInteger(String.valueOf(j))));
                        tmp = new BigInteger(String.valueOf(j));
                    }
                }
                if (tmp.intValue() != 35) {
                    count[35] = count[35].add(count[tmp.intValue()]);
                    count[tmp.intValue()] = new BigInteger("0");
                }
                max = new BigInteger("0");
            }
            tmp = new BigInteger("0");
            for (int i = 0; i < 36; i++)
                tmp = tmp.add(count[i].multiply(new BigInteger(String.valueOf(i))));
            N = 0;
            while (tmp.compareTo(new BigInteger("0")) > 0) {
                result[N++] = tmp.remainder(new BigInteger("36")).intValue();
                tmp = tmp.divide(new BigInteger("36"));
            }
            if(N==0)
                System.out.println(0);
            else {
                for (int i = N - 1; i >= 0; i--)
                    System.out.print(alpabet[result[i]]);
            }
        }
    }
}