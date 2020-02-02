
import java.util.*;
import java.security.*;
import java.security.spec.*;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

import org.apache.commons.lang3.ArrayUtils;

public class Keys {
	PrivateKey prK;
	PublicKey pubK;
	
	Keys() throws NoSuchAlgorithmException{
		KeyPairGenerator kpairg = KeyPairGenerator.getInstance("RSA");
		kpairg.initialize(2048);
		KeyPair kpair = kpairg.genKeyPair();
		pubK = kpair.getPublic();
		prK = kpair.getPrivate();
	}
	PublicKey getKeyFromBytes(byte[] tab) throws NoSuchAlgorithmException{
		KeyFactory kfac = KeyFactory.getInstance("RSA");
		//Building public key from the byte-array
		X509EncodedKeySpec ksp = new X509EncodedKeySpec(tab);
		try {
			return kfac.generatePublic(ksp);
		} catch (InvalidKeySpecException e) {
			e.printStackTrace();
			return null;
		}
	}
	byte[] encode(byte[] tab, PublicKey publicKey) throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException{
		Cipher cipherEncode = Cipher.getInstance("RSA/ECB/PKCS1Padding");
		cipherEncode.init(Cipher.ENCRYPT_MODE, publicKey);
		byte[] msg = new byte[0];
		while(tab.length > 245){
			byte[] tmp = Arrays.copyOf(tab, 245);
			try {
				tmp = cipherEncode.doFinal(tab);
				msg = ArrayUtils.addAll(msg, tmp);
				tab = Arrays.copyOfRange(tab, 245, tab.length);
			} catch (IllegalBlockSizeException |BadPaddingException e) {
				e.printStackTrace();
				return null;
			} 		
			
		}
		try {
			msg = ArrayUtils.addAll(msg, cipherEncode.doFinal(tab));
			tab = Arrays.copyOfRange(tab, 245, tab.length);
		} catch (IllegalBlockSizeException |BadPaddingException e) {
			e.printStackTrace();
			return null;
		}
		return msg;
	}
	byte[] decode(byte[] tab) throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException{
		Cipher cipherDecode = Cipher.getInstance("RSA/ECB/PKCS1Padding");
		cipherDecode.init(Cipher.DECRYPT_MODE, prK);
		byte[] msg = new byte[0];
		while(tab.length > 256){
			byte[] tmp = Arrays.copyOf(tab, 256);
			try {
				tmp = cipherDecode.doFinal(tab);
				msg = ArrayUtils.addAll(msg, tmp);
				tab = Arrays.copyOfRange(tab, 256, tab.length);
			} catch (IllegalBlockSizeException |BadPaddingException e) {
				e.printStackTrace();
				return null;
			} 		
		}
		try {
			msg = ArrayUtils.addAll(msg, cipherDecode.doFinal(tab));
			tab = Arrays.copyOfRange(tab, 256, tab.length);
		} catch (IllegalBlockSizeException |BadPaddingException e) {
			e.printStackTrace();
			return null;
		}
		return msg;
	}
}