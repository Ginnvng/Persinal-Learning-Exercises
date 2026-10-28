package hw26_10_14;
import java.util.Scanner;

public class question4 {
    public static void main(String[] args){
        int[] arr = new int[15];
        InArr A = new InArr();
        A.In(arr);
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        //二分查找 先整一个mid 比较arr[mid]与目标值
        //如果arr[mid] > num，则 right = mid，反则 left = mid
        //然后通过 right 和 left 判断一个新的 mid，循环
        int mid,left = 0,right = arr.length;
        while(true) {
            mid = (right + left)/2;
            if(left > right || mid == arr.length){
                System.out.printf("该值下标为 %d\n",-1);
                break;
            }else if(arr[mid] == num){
                System.out.printf("该值下标为 %d\n",mid);
                break;
            }else if(arr[mid] > num){
                right = mid-1;
            }else if(arr[mid] < num){
                left = mid+1;
            }
        }
    }
}
