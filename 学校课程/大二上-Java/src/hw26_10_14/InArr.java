package hw26_10_14;
import java.util.Scanner;

public class InArr {
    Scanner sc = new Scanner(System.in);

    void In(int[] arr) {
        System.out.printf("请输入 %d 个元素\n",arr.length);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
    }

    void In(int[][] arr) {
        int rows = arr.length;
        int cols = arr[0].length;

        System.out.printf("请输入 %d 个元素\n",rows * cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++){
                arr[i][j] = sc.nextInt();
            }
        }
    }
}
