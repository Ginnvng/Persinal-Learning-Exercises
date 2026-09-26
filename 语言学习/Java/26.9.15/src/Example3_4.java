public class Example3_4 {
    public static void main(String[] args){
        int n = 1;
        double undersum = 1;
        double  sum = 0;
        while(n <= 20)
        {
            undersum *= n;
            sum += (1 / undersum);
            n++;
        }
        System.out.println(sum);
    }
}
