package task2;
import javax.crypto.*;
import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.*;
import java.io.File;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
/**
 *
 * @author aliariz
 */
public class Task2 {
    private static KeyGenerator key;

    public static SecretKey GetRandomKey(){

        try {
            key = KeyGenerator.getInstance("AES");
            key.init(128);
            return key.generateKey();

        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void encrypt(SecretKey key)
            throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException,
            BadPaddingException, IllegalBlockSizeException, IOException {

        Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, key);

        File inputFile = new File("fish.png");
        BufferedImage img = ImageIO.read(inputFile);

        byte[] pixels = ((DataBufferByte) img.getRaster().getDataBuffer()).getData();

        byte[] encPixles = cipher.doFinal(pixels);
        DataBuffer buffer = new DataBufferByte(encPixles, encPixles.length);

        WritableRaster raster = Raster.createInterleavedRaster(buffer, img.getWidth(), img.getHeight(), 3 * img.getWidth(), 3, new int[]{0, 1, 2}, (Point) null);
        ColorModel cm = new ComponentColorModel(ColorModel.getRGBdefault().getColorSpace(), false, true, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
        BufferedImage image = new BufferedImage(cm, raster, true, null);

        ImageIO.write(image, "png", new File("hadaiq.png"));
        System.out.println("Done!");

    }

    public static void main(String[] args) throws IOException, NoSuchPaddingException, NoSuchAlgorithmException,
            IllegalBlockSizeException, BadPaddingException, InvalidKeyException {

        SecretKey key = GetRandomKey();
        encrypt(key);
    }
}
