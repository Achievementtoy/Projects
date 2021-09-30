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
            var ProgramCounter = Assembler.PC;
            bool running = true;
            try
            {
                
                while (running)
                {
                    var iropcode = Assembler.list[ProgramCounter];
                    var irop1 = Assembler.list[ProgramCounter + 4];
                    var irop2 = Assembler.list[ProgramCounter + 8];

                    ProgramCounter += 12;

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
