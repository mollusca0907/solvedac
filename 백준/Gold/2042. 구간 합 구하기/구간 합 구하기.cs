using System;
using System.Runtime.InteropServices;
using ll = System.Int64;

namespace CSharpTest
{
    internal class Program
    {

        static ll[] tree = new ll[1000000 * 4 + 16];

        static void Update(ll idx, ll left, ll right, ll cidx, ll cval)
        {
            if (cidx < left || right < cidx)
            { 
                return;
            }
            if (left == right)
            {
                tree[idx] = cval;
                return;
            }
            ll mid = (left + right) / 2;
            Update(idx * 2, left, mid, cidx, cval);
            Update(idx * 2 + 1, mid + 1, right, cidx, cval);
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
            return;
        }
        static ll Query(ll idx, ll left, ll right, ll qleft, ll qright)
        {
            if (qright < left || right < qleft)
            {
                return 0;
            }
            if (qleft <= left && right <= qright)
            {
                return tree[idx];
            }
            ll mid = (left + right) / 2;
            return Query(idx * 2, left, mid, qleft, qright) + Query(idx * 2 + 1, mid + 1, right, qleft, qright);
        }

        static void Main(string[] args)
        {
            ll n, m, k;
            string[] buf1 = Console.ReadLine().Split();
            n = ll.Parse(buf1[0]);
            m = ll.Parse(buf1[1]);
            k = ll.Parse(buf1[2]);

            for (int i = 1; i <= n; i++)
            {
                ll x = ll.Parse(Console.ReadLine());
                Update(1, 1, n, i, x);
            }

            for(int i= 1; i <= m+k; i++)
            {
                string[] buf2 = Console.ReadLine().Split();
                ll a = ll.Parse(buf2[0]);
                ll b = ll.Parse(buf2[1]);
                ll c = ll.Parse(buf2[2]);
                if (a == 1)
                {
                    Update(1, 1, n, b, c);
                } else
                {
                    Console.WriteLine(Query(1,1,n,b,c));
                }
            }

        }
    }
}
