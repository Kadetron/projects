import java.util.*;
public class ceaser
{
        public static void main(String args[])
        {
                Scanner sc=new Scanner(System.in);
                System.out.print("1.Encrypt\n2.Decrypt\nEnter the choice: ");
                int x=sc.nextInt();
                switch(x)
                {
                        case 1:
                                encrypt();
                                break;
                        case 2:
                                decrypt();
                                break;
                        default:
                                System.out.println("Wrong choice");
                }
        }
        public static void encrypt()
        {
                Scanner sc=new Scanner(System.in);
                int i,n;
                System.out.print("Enter the plaintext: ");
                String s=sc.nextLine();
                char c[]=s.toCharArray();
                for(i=0;i<c.length;i++)
                {
                        n=(int)c[i];
                        if(n>=65&&n<=90)
                        {
                                if(n!=32)
                                 n=(((n+3)-65)%26)+65;
                        }
                        if(n>=97&&n<=122)
                        {
                                if(n!=32)
                                 n=(((n+3)-97)%26)+97;
                        }
                        System.out.print((char)n);
                }
                System.out.println();
        }
        public static void decrypt()
        {
                Scanner sc=new Scanner(System.in);
                int i,n;
                System.out.print("Enter the ciphertext: ");
                String s=sc.nextLine();
                char c[]=s.toCharArray();
                for(i=0;i<c.length;i++)
                {
                        n=(int)c[i];
                        if(n>=65&&n<=90)
                        {
                                if(n!=32)
                                 n=(((n-3)-65)%26)+65;
                        }
                        if(n>=97&&n<=122)
                        {
                                if(n!=32)
                                 n=(((n-3)-97)%26)+97;
                        }
                        System.out.print((char)n);
                }
                System.out.println();
        }
}
