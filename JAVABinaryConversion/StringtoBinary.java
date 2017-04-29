import java.io.UnsupportedEncodingException;
import java.io.IOException;
import java.io.File;
import java.io.FileOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
public class StringtoBinary
{
	public static void main(String[] args) throws UnsupportedEncodingException
	{
	
      
		BufferedReader br = null;
		File file = new File("/root/lab1/filename.bin");
		FileOutputStream fop=null;
		String line;
		try{
			br = new BufferedReader(new FileReader("alphabet.txt"));
			fop = new FileOutputStream(file);
   
				
		
			while((line = br.readLine())!= null){

			byte infoBin[] = null;
			infoBin = line.getBytes("UTF-8");
				if(!file.exists())
					{	
						file.createNewFile();
						

					}	
					
				for(byte a:infoBin)
				{	
					fop.write(a);
					
					
				}	
							
			
		
		}fop.close();
		br.close();
		}catch(IOException e){
			e.printStackTrace();
			}

	}

}
