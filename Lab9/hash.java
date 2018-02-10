package hash;

import javax.xml.bind.DatatypeConverter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class Hash {
       
    public static void calculateTextHash(String text){

        byte[] plainText = new byte[0];
        try {
            plainText = text.getBytes("UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        MessageDigest messageDigest = null;
        try {
            messageDigest = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        MessageDigest messageDigest1 = null;
        try {
            messageDigest1 = MessageDigest.getInstance("SHA-1");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        messageDigest.update( plainText);
        messageDigest1.update( plainText);

        System.out.println( "\nDigest: MD5" );
        byte a[] = messageDigest.digest();
        String s = DatatypeConverter.printHexBinary(a);
        System.out.println(s);

        System.out.println( "\nDigest: SHA-1" );
        byte b[]  = messageDigest1.digest();
        s = DatatypeConverter.printHexBinary(b);
        System.out.println(s);
    }
    public static void calculateFileHash(String filename){

        byte[] plainText = new byte[0];

        MessageDigest messageDigest = null;
        try {
            messageDigest = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        MessageDigest messageDigest1 = null;
        try {
            messageDigest1 = MessageDigest.getInstance("SHA-1");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }

        System.out.println( "Please Enter the File Name: " );

        String cont = null;
        try {
            cont = new String(Files.readAllBytes(Paths.get(filename)));
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            plainText = cont.getBytes("UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        messageDigest.update( plainText);
        messageDigest1.update( plainText);

        System.out.println( "\nDigest: MD5" );
        byte c[] = messageDigest.digest();

        String s = DatatypeConverter.printHexBinary(c);
        System.out.println(s);

        System.out.println( "\nDigest: SHA-1" );
        byte d[]  = messageDigest1.digest();
        s = DatatypeConverter.printHexBinary(d);
        System.out.println(s);
    }
}

Lab_task.java:
package hash;

import javax.xml.bind.DatatypeConverter;
import java.io.UnsupportedEncodingException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class lab_task {

    public static void main(String [] args)
    {
        Scanner inputSc = new Scanner(System.in);
        System.out.println( "Enter the Text: " );
        String text = inputSc.nextLine();

        Hash.calculateTextHash(text);

        Scanner inputScF = new Scanner(System.in);
        System.out.println( "Enter Filename: " );
        String filename = inputSc.nextLine();
        Hash.calculateFileHash(filename);
    }
}

