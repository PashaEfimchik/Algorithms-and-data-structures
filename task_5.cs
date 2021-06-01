using System;
using System.Collections.Generic;
using System.Linq;

namespace task_3_C_sharp
{
    class Program
    {
        static long vx = 100000000000000;
        static int vm = -1;
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine()), y = int.Parse(Console.ReadLine()), p, q, t;
            List<List<Tuple<int, int>>> vt = new List<List<Tuple<int, int>>>();
            bool[] f = new bool[x];     long[] rr = new long[x];
            for (int e = 0; e < x; e++)     {  f[e] = false;     rr[e] = vx;    vt.Add(new List<Tuple<int, int>>());    }
            int[] seq;
            for(int v = 0; v < y; v++)      {
                seq = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
                p = seq[0];     q = seq[1];     t = seq[2];
                vt[p - 1].Add(Tuple.Create(q - 1, t));
                vt[q - 1].Add(Tuple.Create(p - 1, t));   }
            int a = int.Parse(Console.ReadLine());  int b = int.Parse(Console.ReadLine());      a--; b--;
            rr[a] = 0;
            for(int o = 0; o < x; o++)  {   int mv = vm;
                for(int w = 0; w < x; w++)  {
                    if (!f[w] && (mv == vm || rr[w] < rr[mv]))  {    mv = w;    }   }
                for(int c = 0; c < vt[mv].Count; c++)   {
                    int v = vt[mv][c].Item1;  int w = vt[mv][c].Item2;
                    if (rr[mv] + w < rr[v])   {     rr[v] = rr[mv] + w;   }     }
                f[mv] = true;   }
            Console.WriteLine(rr[b]);
            Console.ReadKey();
        }
        static string[] input(string str) { int i, li = 0; List<string> str_ = new List<string>(); while ((i = str.IndexOf(' ', li)) != -1) { str_.Add(str.Substring(li, i - li)); li = i + 1; } str_.Add(str.Substring(li)); return str_.ToArray(); }
    }
}
