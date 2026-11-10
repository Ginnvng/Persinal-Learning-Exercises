package hw26_11_03.图形面积计算系统;

public class AreaCalculator {
    public static void main(String[] args){
        Rectangle Rect1 = new Rectangle(3,4);
        System.out.println("矩形1的面积为："+ Rect1.calculateArea());
        Circle circle1 = new Circle(3);
        System.out.println("圆形1的面积是：" + circle1.calculateArea());
        Triangle triangle1 = new Triangle(4,5);
        System.out.println("三角形1的面积是：" + triangle1.calculateArea());
    }
}
