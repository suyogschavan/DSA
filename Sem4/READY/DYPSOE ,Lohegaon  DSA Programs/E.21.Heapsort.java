import java.io.*;
import java.util.*;

class heapsort
{
	public int[] marks;
	
	public heapsort(int MAX)
	{
		marks = new int[MAX];			
	}
	
	public void makeheap(int n)
	{
		int val, j, f;
		for(int i= 1;i<n;i++)
		{
			val = marks[i];
			j=i;
			f = (j-1)/2;
			while(j>0 && marks[f]<val)   //create max heap
			{
				marks[j]=marks[f];
				j = f;
				f = (j-1)/2;
			}
			marks[j]=val;
	}

}
	void sort(int n)
	{
		for(int i = n-1;i>0;i--)
		{
			int temp = marks[i];
			marks[i] = marks[0];
			int k = 0;
			int j;
			if(i==1)
				j=-1;
			else
				j=1;
			if(i>2 && marks[2] > marks[1])
				j=2;
			while(j>=0 && temp < marks[j])
			{
				marks[k] = marks[j];
				k = j;
				j = 2*k+1;
				if(j+1<=i-1 && marks[j] < marks[j+1])
					j++;
				if(j>i-1)
					j = -1;
			}
			marks[k] = temp;
		}
	}
	public void display(int n)
	{
		for(int i=0;i<n;i++)
			System.out.println(marks[i]);
	}
}

public class heap {
	 public static void main(String args[])throws IOException
	 {
		 heapsort obj = new heapsort(10);
		 int n;
		 Scanner s=new Scanner(System.in);
		 System.out.println("\n Enter the range of elements to be sorted::");
		 n = s.nextInt();
		 System.out.println("\n Enter the elements::");
		 for (int i=0;i<n;i++)
			 obj.marks[i]= s.nextInt();
		 System.out.println("\n Display the elements::");
		 obj.display(n);
		 obj.makeheap(n);
		 System.out.println("\n Heapified::");
		 obj.display(n);
		 obj.sort(n);
		 System.out.println("\n Display the sorted elements::");
		 obj.display(n);
		 
		 
	 }
	
}
