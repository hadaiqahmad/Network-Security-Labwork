\\add the Task.java here
import java.util.Scanner;

public class Task {

	static Scanner us;
	
	public static void main(String[]arfs){
		
		int userChoice = 0;
		String plainText,cipherText,initialKey = "";
		us = new Scanner(System.in);
		System.out.println("Choose: " + "\n" + "1- Encryption" + "\n"+ "2- Decryption");
		userChoice = sc.nextInt();
		us = new Scanner(System.in);
		
		if(userChoice == 1){
			System.out.println("Enter Plain Text in 8-bytes form: ");
			plainText = sc.nextLine();
			System.out.println(plainText);
			DESCipherTest.mode = "Encrypt";
			DESCipherTest.msg = plainText;
			new DESCipherTest();
		}
		if ( userChoice == 2){
			System.out.println("Enter Cipher Text in 8-bytes form: ");
			cipherText = sc.nextLine();
			System.out.println(cipherText);
			DESCipherTest.mode = "Decrypt";
			DESCipherTest.msg = cipherText;
			new DESCipherTest();
		}
		
		us = new Scanner(System.in);
		System.out.println("Enter the initial Key in 8-bytes form: ");
		String key = sc.nextLine();
		if (key.length() > 0){
			
			DESSubkeysTest.key = key;
			new DESSubkeysTest();
			
		}
		
		
	}
	
}
