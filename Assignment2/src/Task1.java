import java.util.Random;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the last two digit of your roll no ");
        int a = sc.nextInt();
        int n = a%10;
        a = a/10;
        n = n + a;
        int [][] arr1 = new int[n][n];
        int [][] arr2 = new int[n][n];
        int [][] arr3 = new int[n][n];

        Random rn = new Random();
        for(int i=0 ; i<n ;i++){
            for (int j=0 ; j<n ; j++){
                arr1[i][j] = rn.nextInt(10);
                arr2[i][j] = rn.nextInt(10);
                arr3[i][j] = 0;
            }
        }
        System.out.println("ARRAY 1");
        printarr(arr1);
        System.out.println();
        System.out.println("ARRAY 2");
        printarr(arr2);

        Thread [] mythread = new Thread[n];
        for(int i=0; i <n ; i++){
            mythread[i] = new Thread(new run(arr1, arr2, arr3, i));
        }
        for(int i=0 ; i<n ; i++){
            mythread[i].start();
            mythread[i].join();
        }
        System.out.println();
        System.out.println("ARRAY 3");
        printarr(arr3);

    }
    public static void printarr(int [][] arr){
        for(int i=0 ; i<arr[0].length;i++){
            for(int j=0; j<arr[0].length;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}
