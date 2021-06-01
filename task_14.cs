using System;
using System.Collections.Generic;
using System.Linq;

namespace task_14_c_sharp
{
	class Program
	{
		static public long m_ = 1000000007;
		static public int N, M;
		
		static void Main(string[] args)
		{
			int[] nm = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
			N = nm[0];
			M = nm[1];
			long[,] sx = new long[N, N];
			for (int nx = 0; nx < N; nx++)
			{
				for (int ny = 0; ny < N; ny++)
				{
					sx[nx, ny] = 0;
				}
			}
			int[] uvl = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
			int u = uvl[0], v = uvl[1], l = uvl[2];

			for (int g = 0; g < M; g++)
            {
				int[] ab = input(Console.ReadLine()).Select(Int32.Parse).ToArray();
				int a = ab[0], b = ab[1];
				sx[a - 1, b - 1]++;
				sx[b - 1, a - 1]++;
			}
			sx = f1(sx, l,N);
			Console.WriteLine(sx[u - 1, v - 1] % m_);
			Console.ReadKey();
		}

		static public long[,] arm(long[,] arr, long[,] zrr, int n)
		{
			long[,] qrr = new long[n,n];
			for (int nx = 0; nx < n; nx++)
			{
				for (int ny = 0; ny < n; ny++)
				{
					qrr[nx, ny] = 0;
				}
			}
			for (int a = 0; a < n; a++)
			{
				for (int b = 0; b < n; b++)
				{
					for (int c = 0; c < n; c++)
					{
						qrr[a, b] += (arr[a, c] * zrr[c, b]) % m_;
						qrr[a, b] %= m_;
					}
				}
			}
			return qrr;
		}

		static public long[,] f1(long[,] arr, int d, int n)
        {
            if (d == 0)
            {
				long[,] mtr = new long[n, n];
				for (int nx = 0; nx < n; nx++)
				{
					for (int ny = 0; ny < n; ny++)
					{
						if (nx == ny)
                        {
							mtr[nx, ny] = 1;
                        }
                        else
                        {
							mtr[nx, ny] = 0;
						}
					}
				}
				return mtr;
			}
			else if (d % 2 == 1)
            {
				return arm(f1(arr, d - 1, n), arr, n);
            }
            else
            {
				long[,] z = f1(arr, d / 2, n);
				return arm(z, z, n);
            }
        }
		
		static string[] input(string str) { int i, li = 0; List<string> str_ = new List<string>(); while ((i = str.IndexOf(' ', li)) != -1) { str_.Add(str.Substring(li, i - li)); li = i + 1; } str_.Add(str.Substring(li)); return str_.ToArray(); }
	}
}
