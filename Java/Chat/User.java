import java.io.FileOutputStream;
import java.net.SocketAddress;
import java.security.Key;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;

public class User {
	SocketAddress address;
	Key pubKey;
	Key privKey;
	static String name;
	
	User(SocketAddress sk, String name){
		System.out.println("smth");
		address = sk;
		this.name = name;
		KeyPairGenerator kpairg;
		try {
			kpairg = KeyPairGenerator.getInstance("RSA");
			kpairg.initialize(2048);
		   KeyPair kpair = kpairg.genKeyPair();
		   pubKey = kpair.getPublic();
		   privKey = kpair.getPrivate();
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		writePubKey(pubKey);
	}
	
	public static void writePubKey(Key key) {
		  byte[] publicKeyBytes = key.getEncoded();
		  try {
			  
			  //FileOutputStream fos = new FileOutputStream(name + " publicKey");
			  FileOutputStream fos = new FileOutputStream("D://Eclips//SKJ");
			  System.out.println(fos);
			  fos.write(publicKeyBytes);
			  fos.close();
		  	} catch (Exception e) {
		  		e.printStackTrace();
		  }
	}
	
	public static void getName(){}
}
