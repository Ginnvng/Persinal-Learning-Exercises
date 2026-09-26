package hw26_09_15;

public class Example3_5 {
    public static void main(String[] args){
        char 字母 = 'a';
        for(int i = 0; i < 26; i++)
        {
            if(!(字母 == 'a' || 字母 == 'm' || 字母 == 'z'))
            {
                System.out.printf("%c",字母);
            }
            字母 += 1;
        }
        System.out.println(' ');

        int n = 1;
        long sum = 1931918;
        while(true)
        {
            sum -= n;
            if(sum <= n)
            {
                System.out.println("满足1+2+…+n<=1931918的最大整数n为" + n);
                break;
            }
            n++;
        }
    }
}
