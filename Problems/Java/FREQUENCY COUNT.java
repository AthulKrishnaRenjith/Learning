import java.util.Scanner;

class FREQUENCY_COUNT
{
    public static void main(String args[])
    {
        String str;
        char character;
        int count = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string");
        str = sc.nextLine().toLowerCase();
        System.out.println("Enter a character");
        character = sc.next().charAt(0);
        for(int i = 0; i < str.length(); i++)
        {
            if(str.charAt(i) == character)
            {
                count++;
            }
        }
        System.out.println("The frequency of " + character + " is " + count);
    }
}