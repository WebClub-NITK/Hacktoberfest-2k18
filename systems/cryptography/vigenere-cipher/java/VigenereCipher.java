import java.io.BufferedReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class VigenereCipher {
  public static void main(String... args) throws IOException{
    final String[] ALPHABET = "abcdefghijklmnopqrstuvwxyz".split("");
    final Map<String, Integer> alphabetToIndex = new HashMap<>();

    IntStream.range(0, ALPHABET.length)
      .forEach(i -> {
        alphabetToIndex.put(ALPHABET[i], i);
      });
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.print("Plain text:");
    final String[] plainText = br.readLine().toLowerCase()
      .replace(" ", "")
      .split("");
    System.out.print("Keyword:");
    final String[] keyword = br.readLine().toLowerCase()
      .replace(" ", "")
      .split("");

    final String encoded = IntStream.range(0, plainText.length)
      .mapToObj(i -> {
        final Integer e = (alphabetToIndex.get(plainText[i]) + alphabetToIndex.get(keyword[i%keyword.length])) % 26;
        return ALPHABET[e];
      }).collect(Collectors.joining());


    System.out.print("Cipher Tex:");
    System.out.println(encoded);


  }
}