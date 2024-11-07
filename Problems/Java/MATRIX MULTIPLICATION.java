import java.util.Scanner;

class MATRIX_MULTIPLICATION {
    int a[][] = new int[30][30];
    int b[][] = new int[30][30];
    int c[][] = new int[30][30];
    int m, n, p, q;
    public void read()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows and columns of first matrix");
        m = sc.nextInt();
        n = sc.nextInt();
        System.out.println("Enter the number of rows and columns of second matrix");
        p = sc.nextInt();
        q = sc.nextInt();
        if(n != p)
        {
            System.out.println("Matrix multiplication is not possible");
            System.exit(0);
        }
        System.out.println("Enter the elements of first matrix");
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                a[i][j] = sc.nextInt();
        }
        System.out.println("Enter the elements of second matrix");
        for(int i = 0; i < p; i++)
        {
            for(int j = 0; j < q; j++)
                b[i][j] = sc.nextInt();
        }
    }
    public void multiply()
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for(int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    public void display()
    {
        System.out.println("The resultant matrix is");
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < q; j++)
                System.out.print(c[i][j] + "\t");
            System.out.println();
        }
    }
}

class MATRIXMULTIPLICATION 
{
    public static void main(String[] args)
    {
        MATRIX_MULTIPLICATION obj = new MATRIX_MULTIPLICATION();
        obj.read();
        obj.multiply();
        obj.display();
    }
}