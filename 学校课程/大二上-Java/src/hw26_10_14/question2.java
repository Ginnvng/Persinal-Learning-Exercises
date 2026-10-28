package hw26_10_14;

public class question2 {
    public static void main(String[] args){
        //新建一个整数数组并用方法初始化
        int[] arr1 = new int[14];
        InArr A = new InArr();
        A.In(arr1);
        //算法思想：快慢指针 只保留不为0的元素
        int k = 0,i; //k表示新数组的长度，和下一个元素的插入位置，i是快指针，从前往后扫描不等于0的元素
        for (i = 0; i < arr1.length; i++)
        {
            if(arr1[i] != 0)
            {
                arr1[k] = arr1[i];
                k++;
            }
        }
        //将修改完成的数组转移到新数组中,并输出
        int []arr2 = new int[k];
        for (i = 0;i <arr2.length;i++ ){
            arr2[i] = arr1[i];
            System.out.printf("%d ",arr2[i]);
        }
        System.out.println();

    }
}
