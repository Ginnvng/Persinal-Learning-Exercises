package hw26_10_28;

class Shape {
    void draw() {
        System.out.println("画一个图形");
    }
}

class Circle extends Shape {
    double radius = 2.0;

    void draw() {               //重写父类的draw()
        System.out.println("画一个半径为" + radius + "的圆");
    }

    double calculateArea() {    //子类特有的方法
        return Math.PI * radius * radius;
    }
}

public class question3 {
    public static void main(String[] args) {
        Shape s = new Circle();     //上转型对象
        s.draw();                   //正常执行，调用的是Circle的draw()

        //s.calculateArea();        //编译报错：Shape里找不到calculateArea()

        if (s instanceof Circle) {          //先确认s真的是Circle再转
            Circle c = (Circle) s;          //向下转型
            System.out.printf("圆的面积: %.2f\n", c.calculateArea());
        }
    }
}