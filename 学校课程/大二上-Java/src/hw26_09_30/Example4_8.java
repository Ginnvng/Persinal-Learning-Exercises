package hw26_09_30;

public class Example4_8 {
    public static void main(String[] args) {
        Circle circle = new Circle();
        circle.setRadius(29);
        Circular circular = new Circular();
        circular.setBottom(circle);
        circular.setHeight(128.76);
        System.out.println("圆锥底圆的半径:" + circular.getBottomRadius());
        System.out.printf("圆锥的体积(保留3位小数):%.3f%n", circular.getVolume());

        circle.setRadius(208);   // 改的是 circle，圆锥的底也跟着变，因为它们是同一个对象
        System.out.println("圆锥底圆的半径:" + circular.getBottomRadius());
        System.out.printf("圆锥的体积(保留3位小数):%.3f%n", circular.getVolume());
    }
}
