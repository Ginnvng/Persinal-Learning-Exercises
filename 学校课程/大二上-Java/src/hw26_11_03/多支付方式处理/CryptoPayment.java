package hw26_11_03.多支付方式处理;

public class CryptoPayment implements PaymentMethod{
    public void pay(double amount){
        System.out.println("支付宝支付" + amount + "元");
    }
}
