package hw26_09_30;

public class Computer {
    public int getSum(int... x) {   // x 是可变参数，本质是 int 数组
        int sum = 0;
        for (int i = 0; i < x.length; i++) {
            sum = sum + x[i];
        }
        return sum;
    }
}
