using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_4_c_sharp
{
    class Program
    {
        static int rr = -1, N, M, i, j;
        static Queue<int[]> ll = new Queue<int[]>();
        static void Main(string[] args)
        {
            ll.Enqueue(new int[] { 0, 0, 0 });       
			int[] nm = Console.ReadLine().Split().Select(Int32.Parse).ToArray();   N = --nm[0];   M = --nm[1];    i = --nm[2];	j = --nm[3]; bool[][] se = new bool[N+1][];
			for (int i = 0; i <= N; i++) se[i] = new bool[M + 1];
            while (ll.Count != 0)	{
                int[] rk = ll.Dequeue();
                if (se[rk[0]][rk[1]]) continue;
                se[rk[0]][rk[1]] = true;
                func(rk, se);
                if (rr != -1) break;
            }
            if (rr != -1) Console.WriteLine(rr);     else Console.WriteLine("NEVAR");
            Console.ReadKey();
        }
        static void func(int[] a, bool[][] se)
        {
            if (a[0] == i && a[1] == j)  {      rr = a[2];    return;    }
            if (a[0] + 1 <= N && a[1] + 2 <= M && a[0] + 1 >= 0 && a[1] + 2 >= 0) {   if (!se[a[0] + 1][a[1] + 2])      ll.Enqueue(new int[] { a[0] + 1, a[1] + 2, a[2] + 1 });}
            if (a[0] - 1 <= N && a[1] + 2 <= M && a[0] - 1 >= 0 && a[1] + 2 >= 0) {  if (!se[a[0] - 1][a[1] + 2])   ll.Enqueue(new int[] { a[0] - 1, a[1] + 2, a[2] + 1 });     }
            if (a[0] + 1 <= N && a[1] - 2 <= M && a[0] + 1 >= 0 && a[1] - 2 >= 0)  {if (!se[a[0] + 1][a[1] - 2])         ll.Enqueue(new int[] { a[0] + 1, a[1] - 2, a[2] + 1 });  }
            if (a[0] - 1 <= N && a[1] - 2 <= M && a[0] - 1 >= 0 && a[1] - 2 >= 0){    if (!se[a[0] - 1][a[1] - 2])    ll.Enqueue(new int[] { a[0] - 1, a[1] - 2, a[2] + 1 });  }
            if (a[0] + 2 <= N && a[1] + 1 <= M && a[0] + 2 >= 0 && a[1] + 1 >= 0) {    if (!se[a[0] + 2][a[1] + 1])     ll.Enqueue(new int[] { a[0] + 2, a[1] + 1, a[2] + 1 });  }
			if (a[0] + 2 <= N && a[1] - 1 <= M && a[0] + 2 >= 0 && a[1] - 1 >= 0) { if (!se[a[0] + 2][ a[1] - 1]) ll.Enqueue(new int[] { a[0] + 2, a[1] - 1, a[2] + 1 }); }
            if (a[0] - 2 <= N && a[1] + 1 <= M && a[0] - 2 >= 0 && a[1] + 1 >= 0)  { if (!se[a[0] - 2][a[1] + 1])  ll.Enqueue(new int[] { a[0] - 2, a[1] + 1, a[2] + 1 }); }
            if (a[0] - 2 <= N && a[1] - 1 <= M && a[0] - 2 >= 0 && a[1] - 1 >= 0)   {   if (!se[a[0] - 2][a[1] - 1]) ll.Enqueue(new int[] { a[0] - 2, a[1] - 1, a[2] + 1 });   }
        }
    }
}
