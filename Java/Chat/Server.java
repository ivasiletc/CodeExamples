import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketAddress;
import java.net.SocketException;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map.Entry;

import org.apache.commons.lang3.ArrayUtils;

public class Server {
	DatagramSocket	socket;
	DatagramPacket packet;
	
	Keys keyManager;
	
	byte input[];
	byte output[];
	
	
	HashMap<String, User> map;
	
	public static void main(String[] args) throws SocketException, NoSuchAlgorithmException{
		new Server();
	}
	
	
	Server() throws SocketException, NoSuchAlgorithmException{
		keyManager = new Keys();
		socket = new DatagramSocket(3228);
		input = new byte[1024];
		output = new byte[1024];
		packet = new DatagramPacket(input, input.length);
		map = new HashMap<>();
		startL();
	}
	void startL(){
		new Thread(new Runnable(){
			@Override
			public void run() {
				while(true){
					try {
						socket.receive(packet);
						String s = new String(input, 0, packet.getLength());
						cmd(s);
						System.out.println(s);
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
		}).start();
	}
	
	
	
	/*	c nickname - connect server
	 *  p your destination (name) - private chat ()
	 *  r oldName newName - rename
	 *  l - users list
	 *  m to msg - send message to "to"
	 *  k - send our key to server
	 */
	
	
	
	public void cmd(String s) throws IOException{
		char c = s.charAt(0);
		if(s.length() > 1){
			s = s.substring(2);
		}
		String response;
		switch(c){
			case 'c':
				s = s.replaceAll("\\s", "");
				if(!map.containsKey(s)){
					output = "porno".getBytes();
					socket.send(new DatagramPacket(output, output.length, packet.getSocketAddress()));
					map.put(s, new User( packet.getSocketAddress(), s));
				}
				response = "Hello, " + s;
				output = response.getBytes();
				socket.send(new DatagramPacket(output, output.length, map.get(s).address));
				
				break;
			case 'p':
				String first = s.split(" ")[0];
				String sec = s.split(" ")[1];
				if(map.containsKey(sec)){
					//Отправили тому, кто хочет
					response = "p"+ sec + " " + map.get(sec).address.toString();
					output = response.getBytes();
					socket.send(new DatagramPacket(output, output.length, map.get(first).address));
					//Отправляем тому, кого хотят
					response = "p"+ first + " " + map.get(first).address.toString();
					output = response.getBytes();
					socket.send(new DatagramPacket(output, output.length, map.get(sec).address));
					
				} else	{
					response = "User not found.";
					output = response.getBytes();
					socket.send(new DatagramPacket(output, output.length, packet.getSocketAddress()));
				}
				break;
			case 'r':	
				String oldName = s.split(" ")[0];
				String newName = s.split(" ")[1];
				if(map.containsKey(oldName) && !map.containsKey(newName) && map.get(oldName).address.equals(packet.getSocketAddress())){
					
					map.put(newName, map.get(oldName));
					map.remove(oldName);
				} else {
					output = "You can't change name".getBytes();
					socket.send(new DatagramPacket(output, output.length, packet.getSocketAddress()));

				}
				break;
			case 'l':
				response = map.keySet().toString();
				output = response.getBytes();
				socket.send(new DatagramPacket(output, output.length, packet.getSocketAddress()));

				break;
			case 'k':
				
				break;
		}
	    
	}
	User getUser(SocketAddress sa){
		for(Entry<String, User> tmp : map.entrySet()){
			if(sa.equals(tmp.getValue().address)){
				return tmp.getValue();
			}
		}
		return null;
	}
}
