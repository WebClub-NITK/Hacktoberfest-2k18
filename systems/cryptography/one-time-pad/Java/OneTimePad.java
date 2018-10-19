import java.util.Scanner;

/**
 * @author Kshitij Mhatre
 * 
 */
public class OneTimePad {

	//this method calculates the character's index from ascii values
	public static int charNum(char c) {
		return (int)c-97; 
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
	
		System.out.println("Input plain text and OTP key on seperate lines");
		char[] text = sc.nextLine().toLowerCase().toCharArray();
		char[] key = sc.nextLine().toLowerCase().toCharArray();
	
		
		if(key.length <text.length) {
			System.out.println("In One Time Pad Encryption, Length of One Time Pad should be equal or more than length of Plain text");
		    System.out.println("For more info, read article at https://en.wikibooks.org/wiki/Cryptography/One_time_pads");		    
		    System.exit(0);
		}
		
		System.out.println("One time padded cipher text:\n");
		//this loop calculates cipher text as (sum of index mod 26) and outputs corresponding char
		for(int i=0;i<text.length;i++) {
			System.out.print((char)((charNum(text[i])+charNum(key[i]))%26+97));
		}
		
		}
}
