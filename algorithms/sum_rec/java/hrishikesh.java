import java.util.*;
public class hrishikesh
{
	public int input()
	{
		System.out.println("Please enter a number");
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.close();
		return n;
	}
	public int sum(int n,int s)
	{
		if(n==0)
			return s;
		else 
			s = s+n;
			return sum(n-1,s);
	}
	public static void main(String[] args)
	{
		hrishikesh obj = new hrishikesh();
		int n = obj.input();
		int sum = obj.sum(n,0);
		System.out.println("Sum = "+sum);
	}
}	
		
