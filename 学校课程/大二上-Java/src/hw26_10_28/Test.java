package hw26_10_28;

import java.util.Scanner;

public class Test {
    public static void makeprint(A a) {
        a.print();
    }
    public static A Birthobj(int i) {
        if (i == 0) return new B();
        else return new C();
    }
    public static void main(String[] args) {
        Scanner sr = new Scanner(System.in);
        System.out.println("input 0 or 1");
        int a = sr.nextInt();
        A pa = Birthobj(a);
        makeprint(pa);
    }
}
class A {
    public void print() {
        System.out.println("AAA");
    }
}
class B extends A {
    public void print() {
        System.out.println("BBB");
    }
}
class C extends B {
    public void print() {
        System.out.println("CCC");
    }
}