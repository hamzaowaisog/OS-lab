public class run implements Runnable {
    int [][] arr1;
    int [][] arr2;
    int [][] arr3;
    int i;
    public run (int [][] arr1,int [][] arr2,int [][] arr3,int i){
        this.arr1 = arr1;
        this.arr2 = arr2;
        this.arr3 = arr3;
        this.i = i;
    }

    @Override
    public void run() {
        int k=0 ;
        while (k< arr2[0].length){
            arr3[i][k] = matrixmul(arr1, arr2, i, k);
            k++;
        }

    }

    public int matrixmul(int [][]arr1, int [][]arr2 , int i , int j) {
        int row=0 , col=0 , sum=0;
        while(row<arr1.length && col<arr2.length){
            sum = sum + arr1[row][i]*arr2[j][col];
            row++;
            col++;
        }
            return sum;
    }
}

