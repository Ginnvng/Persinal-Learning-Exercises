package hw26_09_30;

public class Lader {
    double above, height;   // 实例变量：每个对象各有一份
    static double bottom;   // 类变量：所有对象共享一份

    void setAbove(double a) {
        above = a;
    }

    void setBottom(double b) {
        bottom = b;
    }

    double getAbove() {
        return above;
    }

    double getBottom() {
        return bottom;
    }
}
