using System;

namespace Programmers_RunningRace
{
    class mainApp
    {
        struct Player
        {
            public string name;
            public int rank;
        }

        static public void MergeSort(ref Player[] player)
        {


            return;
        }



        public string[] solution(string[] players, string[] callings)
        {
            string[] answer = new string[players.Length];
            Player[] player = new Player[players.Length];
            int rank;

            answer = players;

            for(int i = 0; i < players.Length; i++)
            {
                player[i].name = players[i];
                player[i].rank = i + 1;
            }

            MergeSort(ref player);

            for (int i = 0; i < callings.Length; i++)
            {
                rank = SearchPlayerRank(callings[i]);
                swap(ref answer, rank, rank - 1);
            }

            for(int i=0; i<answer.Length; i++)
            {
                Console.WriteLine(i + 1 + "등 : " + answer[i]);
            }


            return answer;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(string.Compare("Apple", "Bpple"));

        }
    }
}