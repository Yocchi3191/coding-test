public class Program
{
    // in : command s
    // command : string, compless or decompless
    // s : string
    // (1) complessの場合、sは AAacDCCC といった大文字・小文字のアルファベットからなる文字列として与えられる
    // out : sを 2A-2acD3C などといった文字列に変換して出力する
    //(2) decomplessの場合、sは 2A-2acD3C などといった、正負の数字・大文字・小文字のアルファベットからなる文字列として与えられる
    // out : s を AAacDCCC などといった文字列に変換して出力する

    static public void Main(string[] args)
    {
        Console.WriteLine("このファイルは実行されています");
        var temp = Console.ReadLine();
        var line = temp.Split(" "); //commandとsを分離
        string s = line[1]; // 与えられた文字列
        // 切り取った文字列と、その連続状態
        List<(string splitS, bool mode)> complessPair = new List<(string splitS, bool mode)>();

        // 0文字目の処理
        int checkPoint = 0; // 文字列の判定開始位置
        char preChar = s[0]; // 直前の文字
        char curChar = s[1]; // 現在いる文字
        bool isContinue; // 今判定している文字列が連続か不連続か

        if (preChar == curChar)
        {
            isContinue = true;
        }
        else
        {
            isContinue = false;
        }

        //1文字目 ~ ラストまでの処理
        for (int i = 2; i < s.Length - 1; i++)
        {
            preChar = curChar;
            curChar = s[i];
            //もし連続モードかつpreCharとcurCharが異なる文字であるか、不連続モードかつpreCharとcurCharが同じ文字なら
            if ((isContinue && preChar != curChar) ||
               (!isContinue && preChar == curChar))
            {

                var newPair = (s[checkPoint..i], isContinue);
                complessPair.Add(newPair);
                isContinue = !isContinue;
                checkPoint = i;
            }
        }

        foreach (var pair in complessPair)
        {
            Console.WriteLine("{0} : {1}", pair.splitS, pair.mode);
        }
    }
    static private string[] GetStdin()
    {
        var list = new List<string>();
        string line;
        while ((line = Console.ReadLine()) != null)
        {
            list.Add(line);
        }
        return list.ToArray();
    }
}