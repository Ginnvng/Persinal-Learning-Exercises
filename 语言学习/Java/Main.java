public class Main {
    // 像 C 函数一样的静态方法：不依赖对象实例
    static int add(int a, int b) {
        return a + b;
    }

    // Java 程序入口，签名固定：public static void main(String[] args)
    public static void main(String[] args) {
        int result = add(3, 4);
        System.out.println("Result: " + result);
    }
}
