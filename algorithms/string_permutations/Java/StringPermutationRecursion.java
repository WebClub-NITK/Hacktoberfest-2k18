import java.util.*;
public class printNumber {

	
	  public static void main(String args[])
	  {
	      System.out.println("Enter the string:");
	    Scanner scanner = new Scanner(System.in);
	    String str = scanner.nextLine(); 
	    printNumber permutation = new printNumber();
	    String[] temp=permutation.permute(str);
	    int size = temp.length;
        for (int i=0; i<size; i++)
        {
            System.out.println(temp[i]);
        }
    }
	  public String[] permute(String input){
		  if(input.length()==0) {
			  String output[]= {""};
			  return output;
		  }
		  String[] smallerOutput=permute(input.substring(1)); 
		  String output[]=new String[input.length()*smallerOutput.length];
		  int k=0;
		  for(int i=0;i<smallerOutput.length;i++) {
			  String currentString=smallerOutput[i];
			  for(int j=0;j<=currentString.length();j++) {
				  output[k]=currentString.substring(0,j)+input.charAt(0)+currentString.substring(j);
				  k++;
			  }
		  }
		  return output;
	  }
}

