public class T2 {
    public static void main(String[] args) {
        double s1=0.19;
        double s2=0.26;
        double s3=0.31;
        double s4=0.24;

        double[][] myArray = new double[4][4];

        myArray[0][0]=0.98;
        myArray[0][1]=0.01;
        myArray[0][2]=0.01;
        myArray[0][3]=0;

        myArray[1][0]=0.02;
        myArray[1][1]=0.97;
        myArray[1][2]=0;
        myArray[1][3]=0.01;

        myArray[2][0]=0.;
        myArray[2][1]=0.01;
        myArray[2][2]=0.99;
        myArray[2][3]=0;

        myArray[3][0]=0;
        myArray[3][1]=0.01;
        myArray[3][2]=0;
        myArray[3][3]=0.99;

        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                System.out.print(myArray[i][j] + " ");
            }
            System.out.println();
        }






    }
}
