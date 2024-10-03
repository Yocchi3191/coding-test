using System;
using System.IO;
using System.Collections.Generic;

public class MainApp
{

    static public void Main(string[] args)
    {
        var lines = GetStdin();

        lines = lines[0].Split(' '); //commandとsを分割
        var s = lines[1]; // sのみを取得
        s = SplitString(s);
        string[] splitedS = s.Split(" ");

    }

    public class SplitedString
    {
      public string str;
      public bool isContinue;
    }

    static public string SplitString(string s)
    {
      char prevS = s[0];
      bool isContinue = (s[1] == prevS);
      for(int i= 1; i < s.Length - 1; i++)
      {
        //もし連続状態が変化したら
        if(isContinue != (s[i] == prevS))
        {
          //それまでの文字列を空白で区切る
          s.Insert(i+1, " ");
        }
        prevS = s[i];
      }
      return s;
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

// 文字列が連続した場合、連続した文字数を頭につけて、連続した1文字を出力
// 文字列が不連続な場合、-(連続していない文字数)を頭につけ、不連続な文字列を出力
