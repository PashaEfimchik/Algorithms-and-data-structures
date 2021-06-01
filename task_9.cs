using System;
using System.Collections.Generic;
using System.Linq;
namespace task_9
{
    class Program
    {
        static void Main(string[] args)
        {
            string ws = Console.ReadLine(); int[] nc = new int[ws.Length]; char[] rs = ws.ToArray();
            for (int i = 0; i < ws.Length; i++) { nc[i] = 0; }
            int x = int.Parse(Console.ReadLine());
            for (int i = 0; i < x; i++) {
                int[] lr = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
                int l = lr[0], r = lr[1]; if (r-1 < l-1) { int t = l; l = r; r = t; } nc[l - 1]++; if (r < ws.Length) { nc[r]++; } }
            for (int i = 1; i < ws.Length; i++) { nc[i] += nc[i - 1]; }
            for (int i = 0; i < nc.Length; i++) {
                if (nc[i] % 2 == 1) { if(rs[i] <= 90 && rs[i] >= 65) { rs[i] = Convert.ToChar(Convert.ToInt32(rs[i]) + 32); } else { rs[i] = Convert.ToChar(Convert.ToInt32(rs[i]) - 32); } } }
            Console.WriteLine(new string(rs));
            Console.ReadKey();
        }
        static string[] input(string str) { int i, li = 0; List<string> str_ = new List<string>(); while ((i = str.IndexOf(' ', li)) != -1) { str_.Add(str.Substring(li, i - li)); li = i + 1; } str_.Add(str.Substring(li)); return str_.ToArray(); }
    }
}
