package hw26_10_28;

class Employee {
    String name;
    double baseSalary;

    Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
        System.out.println("Employee构造方法被调用");
    }
}

class Manager extends Employee {
    double bonus;

    Manager(String name, double baseSalary, double bonus) {
        super(name, baseSalary);    //把name和baseSalary交给父类处理
        this.bonus = bonus;         //子类只管自己新增的bonus
        System.out.println("Manager构造方法被调用");
    }
}

public class question4 {
    //参数类型是Employee，所以任何Employee的子类对象都能传进来
    static void printSalary(Employee e) {
        System.out.printf("%s的基础薪资: %.2f元\n", e.name, e.baseSalary);
        //System.out.println(e.bonus);    //编译报错：e是Employee类型，看不到bonus
    }

    public static void main(String[] args) {
        Manager m = new Manager("张三", 8000, 3000);
        printSalary(m);     //传参时自动上转型：相当于 Employee e = m;
    }
}