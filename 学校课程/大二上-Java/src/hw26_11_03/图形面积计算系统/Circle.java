package hw26_11_03.图形面积计算系统;

public class Circle implements Shape {
    double r;
    Circle(double r){
        this.r = r;
    }

    public double calculateArea(){
        return 3.14 * r * r;
    }
}
