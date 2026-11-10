package hw26_10_28;

class Vehicle {
    String type;

    Vehicle(String type) {
        this.type = type;
        System.out.println("Vehicle构造方法被调用");
    }

    void show() {
        System.out.println("这是一辆" + type);
    }
}

class Car extends Vehicle {
    int doors;

    Car(String type, int doors) {
        super(type);    //显式调用父类构造方法，必须放在第一行
        this.doors = doors;
        System.out.println("Car构造方法被调用");
    }

    void show() {       //重写父类的show()
        System.out.println("这是一辆" + type + "，有" + doors + "扇门");
    }
}

public class question1 {
    public static void main(String[] args) {
        Vehicle v = new Car("轿车", 4);   //v是Car对象的上转型对象
        v.show();                         //执行的是Car重写的show()
    }
}