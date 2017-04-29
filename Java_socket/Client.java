import java.io.*;
import java.net.*;
import java.util.Scanner;


public class Client
{
	public static void main(String args[]) throws Exception
	{
		Client FirstClient = new Client();
		FirstClient.run();
	}

	public void run() throws Exception
	{
		Scanner scan = new Scanner(System.in);	

		String a = scan.next();
		String reverse = new StringBuffer(a).reverse().toString();	
		
		Socket Sock = new Socket("192.168.1.140",444); // set Ip that is in the sama network as your server
		PrintStream PS = new PrintStream(Sock.getOutputStream());
		PS.println(reverse);

		InputStreamReader IR = new InputStreamReader(Sock.getInputStream());
		BufferedReader BR = new BufferedReader(IR);

		String msg = BR.readLine();
		System.out.println(msg);
	
	}
}
