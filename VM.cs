using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4380_Project
{
    public class Virtual_Machine
    {
        public Assembler assembler;
        public Virtual_Machine(string filename)
        {
            Console.WriteLine("Now loading the Assembler for project 1");
            assembler = new Assembler(filename);
            Console.WriteLine("Assembler has finished, running virtual machine");
            Console.WriteLine(Assembler.PC);
            bool running = true;
            try
            {
                
                while (running)
                {
                    break;
                    
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }

        }

        
    }

}
