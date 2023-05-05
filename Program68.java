import java.util.*;

interface Marvellous
{
    public void bubbleSort();
    public void selectionSort();
    public void insertionSort();
}

class Sorting implements Marvellous
{
    private int arr[];
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
        System.out.println();
    }

    public void bubbleSort()
    {
        int i = 0, j = 0, temp = 0, count = 0;
        boolean flag = false;

        for(i = 0; i < arr.length; ++i) 
        {
            flag = false;

            for(j = 0; j < arr.length - i - 1; ++j)
            {
                count++;
                if(arr[j] < arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    flag = true;
                }
                if(flag == false)
                {
                    break;
                }
            }
        }
        System.out.println(count);
    }

    public void selectionSort()
    {
        int i = 0, j = 0, min_index = 0, temp = 0;

        for(i = 0; i < arr.length - 1; ++i) 
        {
            min_index = i;
            for(j = i+1; j < arr.length; ++j)
            {
                if(arr[j] < arr[min_index])
                {
                    min_index = j;
                }
                temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
    }

    public void insertionSort()
    {
        
    }
}

class Program68
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the size of array :");
        int size = sobj.nextInt();

        Sorting obj = new Sorting(size);
        obj.accept();
        obj.display();

        obj.bubbleSort();
        obj.display();

        obj.selectionSort();
        obj.display();
    }
}