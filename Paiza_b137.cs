using System;
using System.Collections.Generic;

class Program
{
    public void check(int n, int m, int row, int col, string[][] blocks, List<List<int>> mirrors)
    {
        if (1 < n && blocks[n][m] == blocks[n - 1][m])
        {
            mirrors[n][m] = 1;
            mirrors[n - 1][m] = 1;
        }
        if (n < row && blocks[n][m] == blocks[n + 1][m])
        {
            mirrors[n][m] = 1;
            mirrors[n + 1][m] = 1;
        }
        if (1 < m && blocks[n][m] == blocks[n][m - 1])
        {
            mirrors[n][m] = 1;
            mirrors[n][m - 1] = 1;
        }
        if (m < col && blocks[n][m] == blocks[n][m + 1])
        {
            mirrors[n][m] = 1;
            mirrors[n][m + 1] = 1;
        }
    }

    public static void Main()
    {
        // 自分の得意な言語で
        // Let's チャレンジ！！
        var line = Console.ReadLine();
        string[] heads = line.Split(' ');
        int row = int.Parse(heads[0]);
        int col = int.Parse(heads[1]);

        string[][] blocks = new string[row][];
        for (int i = 0; i < row; i++)
        {
            var input = Console.ReadLine();
            blocks[i] = input.Split(' ');
        }

        List<List<int>> mirrors = new List<List<int>>();
        for (int i = 0; i < row; i++)
        {
            List<int> list = new List<int>();
            for (int j = 0; j < col; j++)
            {
                list.Add(0);
            }
            mirrors.Add(list);
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                check(i, j, row, col, blocks, mirrors);
            }
        }

    }

}