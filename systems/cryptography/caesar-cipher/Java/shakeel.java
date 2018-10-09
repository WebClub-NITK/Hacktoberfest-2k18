/**
 * @author: shakeelsamsu
 * https://github.com/shakeelsamsu
 * Oct 6 18 4:49:02 PM
 * An implementation of the Caesar Cipher
 * Input: A String of lower case letters, followed by
 * an Integer between 0-25 denoting the required shift.
 * Output: The encrypted message
 */

import java.io.*;
import java.util.*;

public class shakeel {
    public static void main(String[] args) throws IOException  {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());

        ArrayList<Character> letters = new ArrayList<Character>();
        for(int i = 0; i < 26; i++) letters.add((char) (i + 97));
        String input = st.nextToken();
        char[] arr = input.toCharArray();
        int shift = Integer.parseInt(st.nextToken());
        for(int j = 0; j < arr.length; j++) {
            char originalChar = arr[j];
            int shiftedNum = letters.indexOf(originalChar) + shift; 
            if(shiftedNum >= 26) shiftedNum %= 26;
            char newChar = letters.get(shiftedNum);
            out.print(newChar);
        }
        out.close();
    }
}
