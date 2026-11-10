package hw26_11_03.图形面积计算系统;

public class Triangle implements Shape{
    double width,height;
    Triangle(double width , double height){
        this.width = width;
        this.height = height;
    }
    public double calculateArea(){
        return (width * height)/2;
    }
}
