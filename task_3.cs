using System;
using System.Collections.Generic;
using System.Linq;

namespace task_3_C_sharp
{
    class Program
    {
        static long vx = 1000000007;
        static long ans = 1;
        static void Main(string[] args)
        {
            int[] nk = input(Console.ReadLine()).Select(Int32.Parse).ToArray();     int n = nk[0], k = nk[1];
            List<long> seq = new List<long>();
            for(int t = 0; t < n; t++)  {     seq.Add(long.Parse(ReadSpace(true)));  }
            seq.Sort();
            if (seq[0] >= 0) {
                for(int t = 0; t < k; t++)    { ans *= seq[n - 1 - t];      ans %= vx;}       }
            else if (seq[n - 1] <= 0)    {
                if (k % 2 == 0)  {
                    for (int t = 0; t < k; t++) {    ans *= seq[t];      ans %= vx; }             }
                else   {
                    for(int t = 0; t < k; t++)  {   ans *= seq[n - 1 - t];    ans %= vx;  }            }
            }
            else  {   int p = 0, q = n - 1;
                while (k > 0)  {
                    if (k >= 2 && seq[p] * seq[p + 1] >= seq[q] * seq[q - 1])   {
                        ans *= (seq[p] * seq[p + 1]) % vx;          ans %= vx;          p += 2;                     k -= 2;}
                    else {      ans *= seq[q];      ans %= vx;    q--;    k--;  }
                }
            }
            Console.WriteLine((ans + vx) % vx);
            Console.ReadKey();
        }
        static string[] input(string str) { int i, li = 0; List<string> str_ = new List<string>(); while ((i = str.IndexOf(' ', li)) != -1) { str_.Add(str.Substring(li, i - li)); li = i + 1; } str_.Add(str.Substring(li)); return str_.ToArray(); }
        private static bool goodLastRead = false;
        public static bool LastReadWasGood {  get  { return goodLastRead; } }
        public static string ReadSpace(bool skipLeadingWhiteSpace)  {
            string input = ""; char nextChar;
            while (char.IsWhiteSpace(nextChar = (char)System.Console.Read())) {     if (!skipLeadingWhiteSpace)     input += nextChar;  }input += nextChar;
            while (!char.IsWhiteSpace(nextChar = (char)System.Console.Read())) {input += nextChar;  }
            goodLastRead = input.Length > 0;
            return input; }
    }
}
