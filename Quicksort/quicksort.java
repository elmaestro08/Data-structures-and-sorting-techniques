import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
public class quicksort {
	static int[] A = {5,4,3,2,1};
	public static void main(String[] args)
	{
		for(int a:A)
		{
			System.out.print("\t"+a);
		}
		System.out.println();
		quicksort q = new quicksort();
		q.qsort(0, 5);
		for(int a:A)
		{
			System.out.print("\t"+a);
		}
	}
	public void qsort(int start, int end) 
	{
		if(start>=(end-1))
		{
			return;
		}
		int p = partition(start, end);
		qsort(start, p);
		qsort((p+1), end);
		
	}
	public int partition(int l,int r)
	{
		int pivot = A[l];
		int i = l+1;
		for(int j = l+1;j<r;j++)
		{
			if(A[j]<pivot)
			{
				swap(i,j);
				i = i+1;
			}
		}
		swap((i-1),l);
		return (i-1);
	}
	public void swap(int a, int b)
	{
		int temp;
		temp = A[a];
		A[a] = A[b];
		A[b] = temp;
	}
}