import java.io.IOException;
import java.math.BigInteger;

public class Main
{
    public static BigInteger[][] C = new BigInteger[1000][1000];
    public static BigInteger comb(int n, int k)
    {
        if (k == 0 || k == n)
                return C[n][k] = BigInteger.ONE;
        if (!C[n][k].equals(BigInteger.ZERO))
                return C[n][k];
        return C[n][k] = comb (n - 1, k - 1).add(comb (n - 1, k));
    }

    public static void main(String[] args) throws IOException
    {
        boolean keepPrinting = true;
        for (int i = 0; i < 1000; i++)
            for (int j = 0; j < 1000; j++)
                C[i][j] = BigInteger.ZERO;

        for (int i = 0; keepPrinting; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                String s = comb(i, j).toString();
                if (s.length() == 61)
                    keepPrinting = false;
                if (j == 0)
                    System.out.printf("%s", s);
                else
                    System.out.printf(" %s", s);
            }
            System.out.println();
        }
    }
}