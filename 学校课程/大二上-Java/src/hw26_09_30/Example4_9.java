package hw26_09_30;

public class Example4_9 {
    public static void main(String[] args) {
        Lader.bottom = 100;   // 通过类名直接访问类变量
        Lader laderOne = new Lader();
        Lader laderTwo = new Lader();
        laderOne.setAbove(28);
        laderTwo.setAbove(66);
        System.out.println("laderOne的上底:" + laderOne.getAbove());
        System.out.println("laderOne的下底:" + laderOne.getBottom());
        System.out.println("laderTwo的上底:" + laderTwo.getAbove());
        System.out.println("laderTwo的下底:" + laderTwo.getBottom());
    }
}
