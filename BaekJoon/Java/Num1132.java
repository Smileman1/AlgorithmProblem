import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int num=in.nextInt();
        long []total;
        long eq=1,min,max,result=0;
        int lengh,tmp=0;
        char alpabet;
        boolean []cheak;
        total=new long[10];
        cheak=new boolean[10];
        for(int i=0;i<10;i++) {
            total[i] = 0;
            cheak[i]=true;
        }
        String a;
        for(int i=0;i<num;i++)
        {
            a=in.next();
            a=a.toLowerCase();
            lengh=a.length()-1;
            for(int j=lengh;j>=0;j--)
            {
                alpabet=a.charAt(j);
                tmp=alpabet-97;
                total[tmp]+=eq;
                eq*=10;
            }
            eq=1;
            alpabet=a.charAt(0);
            tmp=alpabet-97;
            cheak[tmp]=false;
        }
        min=-1;
        for(int i=0;i<10;i++)
        {
            if((min<0&&cheak[i]==true)||(min>total[i]&&cheak[i]==true)) {
                min = total[i];
                tmp=i;
            }
        }
        for(int i=0;i<10;i++)
            cheak[i]=true;
        cheak[tmp]=false;
        for(int i=9;i>0;i--)
        {
            max=0;
            for(int j=0;j<10;j++)
            {
                if(total[j]>max&&cheak[j]==true)
                {
                    max=total[j];
                    tmp=j;
                }
            }
            cheak[tmp]=false;
            result+=i*max;
        }
        System.out.println(result);
    }
}
