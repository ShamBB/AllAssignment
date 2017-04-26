import java.io.UnsupportedEncodingException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileReader;
import java.io.File;
import java.io.PrintWriter;
public class ReverseOrder
{
	public static void main(String[] args) throws UnsupportedEncodingException
	{
		String line;
		BufferedReader br = null;
		File reverseOrder = new File("/root/lab1/alphabetReverse.text");
		try{
			br = new BufferedReader(new FileReader("/root/lab1/filename.bin"));
		
			
			//PrintWriter pw = new PrintWriter(file);
			if(!reverseOrder.exists()){
				reverseOrder.createNewFile();

			}
			
			PrintWriter pw = new PrintWriter(reverseOrder);			

			while((line = br.readLine())!= null){
			
			byte infoBin[] = null;
			infoBin = line.getBytes("UTF-8");
			String a = new String(infoBin,"UTF-8");
			
			
			for(int y=line.length()-1;y>=0;y--)
			{	
				//System.out.print(a.charAt(y));
				pw.print(a.charAt(y));
			}			
			System.out.print("\n");
					
			}
		br.close();
		pw.close();
		}catch(IOException e){
			e.printStackTrace();
			}

	}

}
