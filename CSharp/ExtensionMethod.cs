using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    class ExtensionMethod
    {
        public static void Test()
        {
            string A = "Preved Medved!!";

            int Counter = A.WordCountEE('e');

            Console.WriteLine($"Str = {A}, Counter = {Counter}");
        }
    }

    public static class StringExtensionRRR
    {
        public static int WordCountEE(this string str, char c)
        {
            int Counter = 0;

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == c)
                {
                    Counter++;
                }
            }

            return Counter;
        }
    }
}
