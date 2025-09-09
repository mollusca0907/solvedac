using System;
using System.Collections.Specialized;
using System.Linq;
using System.Runtime.InteropServices;

namespace CSharpTest
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string buf = Console.ReadLine();

            int len = buf.Length;

            int[] arr = new int[len];

            for (int i = 0; i < len; i++)
            {
                arr[i] = buf[i] - '0';
            }

            Array.Sort(arr, (a,b)=>b.CompareTo(a));

            for (int i = 0; i < len; i++)
            {
                Console.Write(arr[i]);
            }

        }
    }
}
