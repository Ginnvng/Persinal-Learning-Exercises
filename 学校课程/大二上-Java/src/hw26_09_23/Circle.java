package hw26_09_23;

public class Circle {
    double radius, area;
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        }
    }
    double getRadius() {
        return radius;
    }
    double getArea() {
        area = 3.14 * radius * radius;
        return area;
    }
}