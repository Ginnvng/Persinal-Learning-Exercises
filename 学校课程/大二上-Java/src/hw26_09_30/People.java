package hw26_09_30;

public class People {
    double computerArea(Circle c) {   // 重载：参数类型不同
        double area = c.getArea();
        return area;
    }

    double computerArea(Tixing t) {
        double area = t.getArea();
        return area;
    }
}
