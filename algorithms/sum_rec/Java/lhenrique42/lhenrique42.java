package lhenrique42;

public class lhenrique42 {

    public static void main(String args[]) 
    { 
    	//tests
        int n = 100; 
        System.out.println("Sum of "+n+" natural numbers: "+sum_nat_using_recursion(n));
        n = 5; 
        System.out.println("\nSum of "+n+" natural numbers: "+sum_nat_using_recursion(n));
    } 

    public static int sum_nat_using_recursion(int n) 
    { 
    	// Natural numbers [0,1,2,3,4....]
        if (n <= 1)
            return n;
        return n + sum_nat_using_recursion(n - 1); 
    }

}
