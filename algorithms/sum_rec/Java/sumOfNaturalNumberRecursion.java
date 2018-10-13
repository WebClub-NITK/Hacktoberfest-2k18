import java.util.Scanner;
public class sumOfnaturalNumber {

	public static void main(String args[]) {
		System.out.println("Enter Number:");
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sum(a);
		System.out.println("Sum :"+b);
	}
	
	public static int sum(int num) {
		if(num<=1) {
			return num;
		}
		return num+sum(num-1);
	}
}
