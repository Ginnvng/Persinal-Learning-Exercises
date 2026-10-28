package hw26_10_14;

public class question1 {
    public static void main(String[] args)
    {
        int[] arr = new int[10];
        InArr A = new InArr();
        A.In(arr);
        //单次遍历，找出第二大的数字
        int Fmax = arr[0],Smax = -1; //记录第一大和第二大的数值
        int Findex = 0,Sindex = -1; //记录下标
        for(int i = 0;i < arr.length;i++){
            if(arr[i] > Fmax){
                Smax = Fmax;
                Sindex = Findex;
                Fmax = arr[i];
                Findex = i;
            }else if(arr[i] < Fmax && arr[i] > Smax){
                Smax = arr[i];
                Sindex = i;
            }
        }
        System.out.printf("第二大的数为：%d , 其下标为：%d",Smax,Sindex);
    }
}
