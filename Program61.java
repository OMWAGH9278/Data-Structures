import java.util.*;

class Sorting
{
    public int arr[];
    public Sorting(int size)
    {
        arr = new int[size];
    }

    public void accept()
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the elements :");
        for(int i = 0; i < arr.length; ++i)
        {
            arr[i] = sobj.nextInt();
        }
    }

    public void display()
    {
        System.out.println("Elements of array are :");
        for(int i = 0; i < arr.length; ++i)
        {
            System.out.print(arr[i]+"  ");
        }
    }
}

class Program61
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the size of array :");
        int size = sobj.nextInt();

        Sorting obj = new Sorting(size);
        obj.accept();
        obj.display();
    }
}