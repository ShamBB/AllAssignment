import java.io.*;
import java.net.*;

public class Server
{
	public static void main(String args[]) throws Exception
	{
		Server FirstServer = new Server();
		FirstServer.run();
	}
	
	public void run() throws Exception
	{
		

		ServerSocket SvrSock = new ServerSocket(444);

		Socket Sock = SvrSock.accept(); 
		InputStreamReader IR = new InputStreamReader(Sock.getInputStream());
		BufferedReader BR = new BufferedReader(IR);

		String Msg = BR.readLine();
		System.out.println(Msg);


	}
	
}
