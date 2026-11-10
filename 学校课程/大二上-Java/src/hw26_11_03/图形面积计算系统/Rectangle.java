package hw26_11_03.图形面积计算系统;

public class Rectangle implements Shape {
    double width,height;
    Rectangle(double width,double height){
        this.width = width;
        this.height = height;
    };
    public double calculateArea(){
        return width * height;
    }
}
