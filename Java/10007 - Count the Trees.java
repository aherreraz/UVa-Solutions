import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main
{
	public static BigInteger []nCatalanes = new BigInteger[310];
	public static void cata()
	{
		nCatalanes[1] = new BigInteger ("1");
		for (int i = 2; i <= 301; i++)
		{
			int j = i - 1;
			BigInteger num = new BigInteger (String.valueOf (2 * (2 * j + 1)));
			BigInteger deno = new BigInteger (String.valueOf(j + 2));
			nCatalanes[i] = nCatalanes[j].multiply (new BigInteger (String.valueOf (i))).multiply (num).divide (deno);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		cata();
		while (true)
		{
			String cadena = sc.readLine();
			if(cadena == null || cadena.equals (""))
				break;
			int n = Integer.parseInt (cadena);
			if(n == 0)
				break;
			System.out.println (nCatalanes[n].toString());
		}
	}
}