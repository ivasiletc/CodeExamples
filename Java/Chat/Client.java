import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.SocketException;
import java.security.NoSuchAlgorithmException;
import java.util.LinkedHashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Client {
	DatagramSocket socket;
	DatagramPacket packet;
	
	Keys keyManager;
	
	String name;
	byte input[];
	byte output[];
	
	Scanner scn;
	LinkedHashMap<String, User> map;
	
	public static void main(String[] args) throws SocketException, NoSuchAlgorithmException{
		new Client();
	}
	
	Client() throws SocketException, NoSuchAlgorithmException{
		keyManager = new Keys();
		socket = new DatagramSocket((int) (Math.random() * 64000) + 1000);
		scn = new Scanner(System.in);
		input = new byte[1024];
		output = new byte[1024];
		packet = new DatagramPacket(input, input.length);
		map = new LinkedHashMap<>();
//		System.out.println("Write your name pls... ");
//		name = scn.nextLine();
		send();
		receive();
		
	}
	void send(){
		
		new Thread(new Runnable(){
			String s;
			DatagramPacket packs;
			public void run() {
				while(true){
					s = scn.nextLine();
					output = s.getBytes();
					try {						
						if(s.startsWith("m ")){
							output = s.getBytes();
							System.out.println(map.get(s.split(" ")[1]).address);
							socket.send(new DatagramPacket(output, output.length, map.get(s.split(" ")[1]).address));
						} else {
							if(s.startsWith("c "))
								name = s.split(" ")[1];
							socket.send(new DatagramPacket(output, output.length, InetAddress.getByName("localhost"), 3228));
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
		}).start();
	}
	void receive(){
		new Thread(new Runnable(){
			@Override
			public void run() {
				while(true){
					try {
						socket.receive(packet);
						String s = new String(input, 0, packet.getLength());
						System.out.println(s);
						if(s.charAt(0) == 'p'){
							s = s.substring(1);
							String name = s.split(" ")[0];
							String addr = s.split(" ")[1];
							InetSocketAddress isa = new InetSocketAddress(addr.split(":")[0].substring(1), Integer.parseInt(addr.split(":")[1]));
							map.put(name, new User(isa, null));
							System.out.println("Name: " + name);
							System.out.println("Address: "  + map.get(name).address.toString());
						} else if(s.charAt(0) == 'm'){
							String name = getName(packet.getSocketAddress());	
							if(!name.equals("")){
								System.out.println(name + ": " + s.split("\\^")[1]);
							}
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
		}).start();
	}
	String getName(SocketAddress sa){
		for(Entry<String, User> tmp : map.entrySet()){
			if(sa.equals(tmp.getValue().address)){
				return tmp.getKey();
			}
		}
		return "";
	}
}
