package hw26_10_28;

public class Chinese extends People {
    void showBodyMess() {
        System.out.printf("身高:%5dcm\t体重:%3.2fkg\n",height,weight);
    }
    void speakChinese() {
        System.out.println("我是中国人");
    }
}