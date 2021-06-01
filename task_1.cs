using System;
using System.Collections.Generic;
using System.Linq;

namespace task_3_c_sharp
{
	class Program
	{
		public static int m_ = 10001;
		public static List<int>[] arr = Arrays.INITi<List<int>>(m_);
		
		static void Main(string[] args)
		{
			int res = 0;
			int[] nm = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
			int N = nm[0], M = nm[1];
			for (int k = 0; k < N; k++)
            	arr[k] = new List<int>();
         
			bool[] flag = new bool[N];
			for (int j = 0; j < M; j++)
			{
				int[] uv = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
				int u = uv[0], v = uv[1];
				u--; v--;
				arr[u].Add(v); arr[v].Add(u);
			}

			for (int ind = 0; ind < N; ind++)
            {if (!flag[ind]){ rec(ind, flag, arr); res++; } }
			Console.WriteLine(res - 1); Console.ReadKey();
		}

		public static void rec(int ind, bool[] flag, List<int>[] gr) { flag[ind] = true; foreach(int it in gr[ind]) { if (!flag[it]) {rec(it, flag, gr); } }}

		static string[] input(string str) { int i, li = 0; List<string> str_ = new List<string>(); while((i = str.IndexOf(' ', li)) != -1) {str_.Add(str.Substring(li, i - li)); li = i + 1; } str_.Add(str.Substring(li)); return str_.ToArray(); }
	}
}

internal static class Arrays
{
	public static b[] INITi<b>(int length) where b : new() { b[] array = new b[length]; for (int i = 0; i < length; i++) { array[i] = new b(); } return array; }
}
