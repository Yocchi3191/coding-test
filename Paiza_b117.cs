using System;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var line = Console.ReadLine();
        int quantity = int.Parse(line);

        List<int> orders = new List<int>();
        for (int i = 0; i < quantity; i++)
        {
            var _line = Console.ReadLine();
            int order = int.Parse(_line);
            orders.Add(order);
        }

        int[] rot_counts = new int[quantity];
        for (int i = 0; i < quantity; i++)
        {
            rot_counts[i] = 0;
        }

        // --------------------

        for (int i = 1; i < orders.Length; i++)
        {
            if(orders[i] > orders[i-1])
            {
                for(int j=i; j<rot_counts)
            }
        }
    }
}