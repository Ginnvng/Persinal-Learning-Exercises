package hw26_10_28;

class Animal {
    String name;

    Animal(String name) {   //只有带参构造方法，Java不再提供默认无参构造
        this.name = name;
        System.out.println("Animal: " + name);
    }
}

class Dog extends Animal {
    String breed;

    Dog(String name, String breed) {
        super(name);        //第3步：先删掉这行编译一次，看报错，再加回来
        this.breed = breed;
        System.out.println("Dog: " + name + "，品种: " + breed);
    }
}

public class question2 {
    public static void main(String[] args) {
        Dog d = new Dog("旺财", "柯基");
    }
}