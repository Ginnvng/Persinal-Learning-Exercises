package hw26_09_30;

public class Student {
    int number;

    Student(int n) {
        number = n;
    }

    void speak() {
        System.out.println("Student类的包名是hw26_09_30,我的学号:" + number);
    }
}
