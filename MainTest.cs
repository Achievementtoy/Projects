using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _4380_Project
{
    class MainTest
    {
        private static string filename;
        public static void Main(string[] args)
        {
            Console.WriteLine("Please input your assembly file");
            var argument = Console.ReadLine();
            Virtual_Machine vm = new Virtual_Machine(argument);
            
        }
    }
}
