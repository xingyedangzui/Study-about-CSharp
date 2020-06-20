using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> a = new List<int>();
            for(int i =0;i<10;++i)
            {
                a.Add(i);
            }

            List<int> b = new List<int>();

            b.AddRange(a);

            foreach(var i in a)
            {
                Console.Write(i);
            }

            Console.WriteLine();

            foreach(var i in b)
            {
                Console.Write(i);
            }
        }
    }
}
