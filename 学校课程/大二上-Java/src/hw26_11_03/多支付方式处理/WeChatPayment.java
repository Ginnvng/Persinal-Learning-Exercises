package hw26_11_03.多支付方式处理;

public class WeChatPayment implements PaymentMethod{
    public void pay(double amount){
        System.out.println("微信支付" + amount + "元");
    }
}
