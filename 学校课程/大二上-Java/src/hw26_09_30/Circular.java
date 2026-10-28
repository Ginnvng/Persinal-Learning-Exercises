package hw26_09_30;

public class Circular {
    Circle bottom;   // 圆锥的底是一个 Circle 对象
    double height;

    void setBottom(Circle c) {   // 把 circle 的引用传给成员变量 bottom
        bottom = c;
    }

    void setHeight(double h) {
        height = h;
    }

    double getVolume() {
        if (bottom == null)
            return -1;
        else
            return bottom.getArea() * height / 3.0;
    }

    double getBottomRadius() {
        return bottom.getRadius();
    }

    public void setBottomRadius(double r) {
        bottom.setRadius(r);
    }
}
