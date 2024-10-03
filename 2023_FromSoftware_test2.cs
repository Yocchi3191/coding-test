using System;
using System.IO;
using System.Collections.Generic;

public class MainApp
{

    static public void Main(string[] args)
    {
        var lines = GetStdin(); //祝日数と店舗情報を取得
        lines = lines[0].Split(" ");
        int shopCount = int.Parse(lines[1]);

        List<Restaurant> system = new List<Restaurant>();

        //レストランの生成
        for (int i = 0; i < shopCount; i++)
        {
            var restaurantLines = GetStdin()[0].Split(" "); //レストラン情報を取得
            var restaurant = new Restaurant(restaurantLines[0], int.Parse(restaurantLines[1]), int.Parse(restaurantLines[2]));
            system.Add(restaurant);
        }

        //Orderの生成と出力
        while () (scanf("%d", &x) != EOF)
        {
            lines = GetStdin()[0].Split(" "); //注文情報を取得
            var order = new Order(lines[0], lines[1], lines[2], int.Parse(lines[3]), int.Parse(lines[4]), int.Parse(lines[5]));
            var deliveryCost = getDeliveryCost(system())
        }
    }

    public class Restaurant
    {
        public string id;
        public int[] pos;

        public Restaurant(string i, int x, int y)
        {
            id = i;
            pos = new int[] { x, y };
        }

    }

    public class Order
    {
        public string date;
        public string time;
        public string shopId;
        public int payment;
        public int[] userPos;

        public Order(string d, string t, string id, int pay, int x, int y)
        {
            date = d;
            time = t;
            shopId = id;
            payment = pay;
            userPos = new int[] { x, y };
        }
    }

    /// <summary>
    /// レストランとユーザーの位置を渡して、かかる送料を返す
    /// </summary>
    /// <param name="restaurantPos"></param>
    /// <param name="userPos"></param>
    /// <returns>送料(int)</returns>
    static private int getDeliveryCost(int restaurantX, int restaurantY, int userX, int userY)
    {
        int deliveryCost = 0;
        double distance = Math.Sqrt(Math.Pow(restaurantX - userX, 2) + Math.Pow(restaurantY - userY, 2));

        if (distance <= 100)
        {
            deliveryCost = 300;
            return deliveryCost;
        }
        else if (deliveryCost <= 1000)
        {
            deliveryCost = 600;
            return deliveryCost;
        }
        else if (distance <= 10000)
        {
            deliveryCost = 900;
            return deliveryCost;
        }
        else
        {
            deliveryCost = 1200;
            return deliveryCost;
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
