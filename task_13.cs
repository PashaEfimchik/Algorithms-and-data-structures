using System;
using System.Collections.Generic;
using System.Linq;

namespace task_3_c_sharp
{
	class Program
	{
		public static int m_ = 10001;
		public static List<int>[] arr = seq.INIT<List<int>>(m_);

		static void Main(string[] args)
		{
			int res = 0, ct = 0;
			int[] nm = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
			int N = nm[0], M = nm[1];
			for (int k = 0; k < N; k++)	arr[k] = new List<int>();
			bool[] e = new bool[N];
			for (int j = 0; j < M; j++)
			{
				int[] uv = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
				int u = uv[0], v = uv[1]; u--; v--;
				arr[u].Add(v); arr[v].Add(u);
			}
			for (int q = 0; q < N; q++) { if (!e[q]) { rc(q, e, arr); res++; } }
			if(res-1 == 0 && M-N+1 >= 0) { Console.WriteLine(M - N + 1); } else { Console.WriteLine(-1); } 
			Console.ReadKey();
		}
		public static void rc(int ind, bool[] flag, List<int>[] nc) { flag[ind] = true;			foreach (int it in nc[ind]) { if (!flag[it]) { rc(it, flag, nc); } } }

		static string[] input(string str) { int i, li = 0; List<string> str_ = new List<string>();				while ((i = str.IndexOf(' ', li)) != -1) { str_.Add(str.Substring(li, i - li)); li = i + 1; } str_.Add(str.Substring(li)); return str_.ToArray(); }
	}
}

internal static class seq
{
	public static b[] INIT<b>(int length) where b : new() { b[] array = new b[length]; for (int i = 0; i < length; i++) { array[i] = new b(); } return array; }
}
