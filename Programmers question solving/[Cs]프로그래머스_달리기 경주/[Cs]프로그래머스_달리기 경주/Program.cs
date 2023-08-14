using System;
using System.ComponentModel.Design;

namespace Programmers_RunningRace
{
    public struct Player
    {
        public string name;
        public int rank;
    }

    class mainApp
    {
        static public int a = 0;

        static public void MergeSort(ref Player[] player, int start, int end)
        {
            if (start >= end) return;
            a++;
            Player[] temp = new Player[player.Length];
            int mid = (start + end) / 2;

            MergeSort(ref player, start, mid);
            MergeSort(ref player, mid + 1, end);

            int i = start;
            int j = mid + 1;
            int k = start;

            for (k = start; k <= end; k++)
            {
                if (i > mid || j > end) break;

                if (string.Compare(player[i].name, player[j].name) < 0)
                {
                    temp[k].name = player[i].name;
                    temp[k].rank = player[i].rank;
                    i++;
                }
                else
                {
                    temp[k].name = player[j].name;
                    temp[k].rank = player[j].rank;
                    j++;
                }
            }
            if(i > mid)
            {
                for(; k<=end; k++)
                {
                    temp[k].name = player[j].name;
                    temp[k].rank = player[j].rank;
                    j++;
                }
            }
            else if(j > end)
            {
                for (; k <= end; k++)
                {
                    temp[k].name = player[i].name;
                    temp[k].rank = player[i].rank;
                    i++;
                }
            }

            for(k = start; k<=end; k++)
            {
                player[k] = temp[k];
            }

            return;
        }
        static public int SearchPlayerIndex(ref Player[] player, string name)
        {
            int index = -1;
            int start = 0;
            int end = player.Length - 1;
            int mid = (start + end) / 2;
            int count = 0;

            while (start <= end)
            {
                Console.WriteLine(player[mid].name + ", " + name + "비교");
                count++;
                if (string.Compare(player[mid].name, name) == 0)
                {
                    index = mid;
                    break;
                }
                else if (string.Compare(player[mid].name, name) > 0)
                {
                    end = mid - 1;
                    mid = (start + end) / 2;
                }
                else if (string.Compare(player[mid].name, name) < 0)
                {
                    start = mid + 1;
                    mid = (start + end) / 2;
                }
            }
            if(index == -1)
            {
                Console.WriteLine("Binary Search Error");
            }
            else
            {
                Console.WriteLine("Binary Search Clear : " + index + ", 실행 횟수 : " + count);
            }

            return index;
        }
        static public void swap(ref string[] answer, int target1, int target2)
        {
            target1--;
            target2--;
            string temp = answer[target1];
            answer[target1] = answer[target2];
            answer[target2] = temp;
        }

        static public string[] solution(string[] players, string[] callings)
        {
            string[] answer = new string[players.Length];
            Player[] player = new Player[players.Length];
            int target1_index;
            int target2_index;

            answer = players;

            for(int i = 0; i < players.Length; i++)
            {
                player[i].name = players[i];
                player[i].rank = i + 1;
            }

            MergeSort(ref player, 0, player.Length - 1);

            for (int i = 0; i < players.Length; i++)
            {
                Console.WriteLine(player[i].name + " : " + player[i].rank);
            }
            for (int j = 0; j < answer.Length; j++)
            {
                Console.Write(answer[j] + " ");
            }
            Console.WriteLine();
            Console.WriteLine("------------------------------------");

            for (int i = 0; i < callings.Length; i++)
            {
                target1_index = SearchPlayerIndex(ref player, callings[i]);
                target2_index = SearchPlayerIndex(ref player, answer[player[target1_index].rank - 2]);
                swap(ref answer, player[target1_index].rank, player[target2_index].rank);
                player[target1_index].rank--;
                player[target2_index].rank++;
                for (int j = 0; j < players.Length; j++)
                {
                    Console.WriteLine(player[j].name + " : " + player[j].rank);
                }
                for (int j = 0; j < answer.Length; j++)
                {
                    Console.Write(answer[j] + " ");
                }
                Console.WriteLine();
                Console.WriteLine("------------------------------------");
            }

            for(int i=0; i<answer.Length; i++)
            {
                Console.WriteLine(i + 1 + "등 : " + answer[i]);
            }

            Console.WriteLine(a);


            return answer;
        }

        static void Main(string[] args)
        {

            string[] players = { "mumu", "soe", "poe", "kai", "mine" };
            string[] callings = { "kai", "kai", "mine", "mine" };

            solution(players, callings);

        }
    }
}