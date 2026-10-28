package hw26_10_14;

public class question3 {
    public static void main(String[] args){
        int Edge = 3;
        int[][] arr = new int[Edge][Edge];
        InArr A = new InArr();
        A.In(arr);
        //计算主对角线的元素总和
        int i = 0,j= 0,sum = 0;
        while(i < Edge && j < Edge){
            sum += arr[i][j];
            i++;
            j++;
        }
        System.out.println(sum);
    }
}
