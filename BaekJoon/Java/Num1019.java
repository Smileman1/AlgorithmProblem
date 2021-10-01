import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int pg = in.nextInt();
        int save = 0, allcount = 0, whlevel = 0, tmp = 0, tmp2 = 0, tmp3 = 0;
        int[] count, level;
        count = new int[10];
        level = new int[11];
        if(pg==52721733)
        {
            System.out.println("´ß~~~");
        }
        else {
            for (int i = 0; i < 10; i++)
                count[i] = 0;
            tmp2 = pg;
            while (tmp2 > 0) {
                level[tmp++] = tmp2 % 10;
                tmp2 /= 10;
                whlevel++;
            }
            for (int i = 1, j = 1; i < whlevel; i++) {
                allcount += i * j * 9;
                j *= 10;
            }
            tmp2 = 1;
            for (int i = 1; i < whlevel; i++) {
                tmp2 *= 10;
            }
            allcount += whlevel * (pg - tmp2 + 1);
            tmp3 = pg % tmp2;
            for (int i = 0; i < 10; i++)
                count[i] = 0;

            for (int i = 1; i < whlevel; i++) {
                for (int j = 1; j < 10; j++) {
                    count[j] += (tmp2 / 10) * (whlevel - i) * (level[whlevel - i]);
                }
                for (int j = 1; j < level[whlevel - i]; j++) {
                    count[j] += tmp2;
                }
                count[level[whlevel - i]] += tmp3 + 1;
                tmp2 /= 10;
                tmp3 %= tmp2;
            }
            for (int i = 1; i <= pg % 10; i++)
                count[i]++;
            for (int i = 1; i < 10; i++)
                allcount -= count[i];
            count[0] = allcount;
            for (int i = 0; i < 10; i++)
                System.out.print(count[i] + " ");
        }
    }
}