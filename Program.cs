using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.CompilerServices;
using System.Text;

namespace _4380_Project
{
    public partial class Program
    {
        private static Hashtable Ltable;
        private static int index;
        private static ushort length;
        private static bool end;
        private static ushort execution;
        private static string Source;
        private static int address;
        private static string[] final;
        private static TextReader input;
        private static BinaryWriter output;
        private static int PC;
        private static List<byte> list;
        private static Encoding u32;
        private enum Registers
        {
            R1 = 1,
            R2 = 2,
            R3 = 3,
            R4 = 4,
            R5 = 5,
            R6 = 6,
            R7 = 7,
            R8 = 8,
            R9 = 9,
            R10 = 10,
            R11 = 11,
            R12 = 12,
            R13 = 13,
            R14 = 14,
            R15 = 15,
            PC,
        }

        private enum Instructions
        {
            ADD, SUB, DIV, MUL, LDR, TRP, LDB, MOV,
        }

        

        static void Main(string[] args)
        {
            Ltable = new Hashtable(50);
            index = 0;
            length = 0;
            execution = 0;
            end = false;
            address = 0;
            list = new List<byte>();
            u32 = Encoding.Unicode;
            var fs = new FileStream("myfile.txt", FileMode.OpenOrCreate, FileAccess.ReadWrite);
            
            FirstPass();
            SecondPass();
            //okay
            foreach (var i in list)
            {
                Console.WriteLine(i);
                fs.WriteByte(i);
            }
            fs.Close();
        }

        private static void SecondPass()
        {
            byte[] b;
            bool isOp = false;
            

            foreach (var i in File.ReadLines("Project1.asm"))
            {
                var x = i.Replace(",", " ");
                foreach (var s in x.Split())
                {
                    if (s == ".BYT" || s == ".INT" || s == "START" || s == "END")
                    {
                        continue;
                    }
                    switch (s)
                    {
                        case "R1":
                            b = BitConverter.GetBytes(1);
                            list.AddRange(b);
                            break;
                        case "R2":
                            b = BitConverter.GetBytes(2);
                            list.AddRange(b);
                            break;
                        case "R3":
                            b = BitConverter.GetBytes(3);
                            list.AddRange(b);
                            break;
                        case "R4":
                            b = BitConverter.GetBytes(4);
                            list.AddRange(b);
                            break;
                        case "R5":
                            b = BitConverter.GetBytes(5);
                            list.AddRange(b);
                            break;
                        case "R6":
                            b = BitConverter.GetBytes(6);
                            list.AddRange(b);
                            break;
                        case "R7":
                            b = BitConverter.GetBytes(7);
                            list.AddRange(b);
                            break;
                        case "R8":
                            b = BitConverter.GetBytes(8);
                            list.AddRange(b);
                            break;
                        case "R9":
                            b = BitConverter.GetBytes(9);
                            list.AddRange(b);
                            break;
                        case "R10":
                            b = BitConverter.GetBytes(10);
                            list.AddRange(b);
                            break;
                        case "R11":
                            b = BitConverter.GetBytes(11);
                            list.AddRange(b);
                            break;
                        case "R12":
                            b = BitConverter.GetBytes(12);
                            list.AddRange(b);
                            break;
                        case "R13":
                            b = BitConverter.GetBytes(13);
                            list.AddRange(b);
                            break;
                        case "R14":
                            b = BitConverter.GetBytes(14);
                            list.AddRange(b);
                            break;
                        case "R15":
                            b = BitConverter.GetBytes(15);
                            list.AddRange(b);
                            break;
                        case "ADD":
                            b = BitConverter.GetBytes(13);
                            list.AddRange(b);
                            isOp = true;
                            break;
                        case "SUB":
                            b = BitConverter.GetBytes(15);
                            isOp = true;
                            list.AddRange(b);
                            break;
                        case "MUL":
                            b = BitConverter.GetBytes(16);
                            isOp = true;
                            list.AddRange(b);
                            break;
                        case "DIV":
                            b = BitConverter.GetBytes(17);
                            isOp = true;
                            list.AddRange(b);
                            break;
                        case "MOV":
                            b = BitConverter.GetBytes(7);
                            isOp = true;
                            list.AddRange(b);
                            break;
                        case "LDR":
                            b = BitConverter.GetBytes(10);
                            isOp = true;
                            list.AddRange(b);
                            break;
                        case "LDB":
                            b = BitConverter.GetBytes(12);
                            isOp = true;
                            list.AddRange(b);
                            break;
                        case "TRP":
                            b = BitConverter.GetBytes(13);
                            isOp = true;
                            list.AddRange(b);
                            break;
                    }
                    //This is a value from the directives
                    if (isOp == false && !Enum.IsDefined(typeof(Instructions), s) && !Ltable.Contains(s) && int.TryParse(s, out int t))
                    {
                       
                        int a = int.Parse(s);
                        b = BitConverter.GetBytes(a);
                        list.AddRange(b);
                    }
                    //This converts the char to the ascii value.
                    if (isOp == false && !Enum.IsDefined(typeof(Instructions), s) && !Ltable.Contains(s) && !int.TryParse(s, out int u))
                    {
                        foreach (var c in s)
                        {
                            if (Char.IsLetter(c))
                            {
                                var ascii = ((int)c);
                                var Ascii = BitConverter.GetBytes(ascii)[0];
                                list.Add(Ascii);
                                break;
                            }
                            
                        }
                        

                    }
                    if (s == "")
                    {
                        continue;
                    }

                    if (s == ";")
                    {
                        break;
                    }

                }

            }

        }

        private static void FirstPass()
        {

            
            foreach (var i in File.ReadLines("Project1.asm"))
            {
                foreach (var s in i.Split())
                {
                    if (s == "START")
                    {
                        PC = address;
                        continue;
                    }
                    if (s == ".INT" || s == ".BYT" || s == "ADD" || s == "SUB" || s == "DIV" || s == "MUL" || s == "LDR" || s == "TRP" || s == "MOV" || s =="LDB" )
                    {
                        switch (s)
                        {
                           
                            case ".INT":
                                address += 4;
                                break;
                            case ".BYT":
                                address += 1;
                                break;
                            default:
                                address += 12;
                                break;

                        }


                        break;
                    }

                    if (s == "")
                    {
                        continue;
                    }
                    if (s == ";")
                    {
                        break;
                    }

                    Ltable.Add(s, address);
                }
                
            }
            
        //    if (char.IsLetter(Source[index]))
        //    {
                
        //        Ltable.Add(GetLabel(),address);
                
        //        while (Source[index] != '\n')
        //        {
        //            if (Source[index] == '.')
        //            {
        //                index++;
        //                switch (GetLabel())
        //                {
        //                    case "INT":
        //                        address += 4;
        //                        continue;
        //                    case "BYT":
        //                        address += 1;
        //                        continue;

        //                }

                        

        //            }
        //            index++;
        //        }

        //    }

        //    index++;


        }


        private void WhiteSpace()
        {
            while (char.IsWhiteSpace(Source[index]))
            {
                index++;
            }
        }

        private static string GetLabel()
        {
            string lblname = "";
            while (char.IsLetterOrDigit(Source[index]))
            {
                if (Source[index] == ' ' || Source[index] == '\t')
                {
                    index++;
                    break;
                }

                lblname += Source[index];
                index++;
            }

            if (lblname == "END")
            {
                end = true;
            }
            return lblname.ToUpper();
        }
    }
}
