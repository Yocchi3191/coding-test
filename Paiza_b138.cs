using System;
class Program
{
    static void Main()
    {
        var firstLine = Console.ReadLine().Trim().Split(' '); //H, Wを取得
        int h = int.Parse(firstLine[0]);
        int w = int.Parse(firstLine[1]);

        char[,] map = new char[h, w]; // 地上絵の配列を用意

        for (int i = 0; i < h; i++)
        {
            var mapLine = Console.ReadLine(); //地上絵を一列ごとに取得
            for (int j = 0; j < w; j++)
            {
                map[i, j] = mapLine[j];
            }
        }

        int count = 0;
        //mapの外周から1マス分内側を探索
        for (int i = 1; i < h - 1; i++)
        {
            for (int j = 1; j < w - 1; j++)
            {
                //今いるマスが . なら
                if (map[i, j] == '.')
                {
                    // #チェックを通った回数
                    // チャックを完全にクリアした場合 8 になる
                    int hashCount = 0;
                    // 周囲8マスを探索
                    for (int k = i - 1; k <= i + 1; k++)
                    {
                        for (int l = j - 1; l <= j + 1; l++)
                        {
                            //もし探索場所が自分のマスの場合、スキップ
                            if (k == i && l == j)
                            {
                                continue;
                            }
                            // 当該マスが # じゃない場合チェック不合格
                            // map[i, j]についての判定を終了
                            if (map[k, l] == '#')
                            {
                                hashCount++;
                            }
                        }
                    }
                    if (hashCount == 8)
                    {
                        count++;
                    }
                }
            }
        }

        Console.WriteLine(count);
    }
}