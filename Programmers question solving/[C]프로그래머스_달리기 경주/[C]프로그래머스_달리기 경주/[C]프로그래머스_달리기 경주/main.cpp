#include<iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct 
{
    string name;
    int rank;
}Player;

void MergeSort(vector<Player> *player, int start, int end);
int SearchPlayerIndex(vector<Player> player, string name);
void swap(vector<string> *answer, int target1, int target2);


void MergeSort(vector<Player> &player, int start, int end)
{
    vector<Player> temp(player.size());
    if (start >= end)    return;
    int mid = (start + end) / 2;

    MergeSort(player, start, mid);
    MergeSort(player, mid + 1, end);

    int i = start;
    int j = mid + 1;
    int k = start;

    for (k = start; k <= end; k++)
    {
        if (i > mid || j > end)    break;

        if (player[i].name.compare(player[j].name) < 0)
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
    if (i > mid)
    {
        for (; k <= end; k++)
        {
            temp[k].name = player[j].name;
            temp[k].rank = player[j].rank;
            j++;
        }
    }
    else if (j > end)
    {
        for (; k <= end; k++)
        {
            temp[k].name = player[i].name;
            temp[k].rank = player[i].rank;
            i++;
        }
    }

    for (k = start; k <= end; k++)
    {
        player[k] = temp[k];
    }

    return;
}

int SearchPlayerIndex(vector<Player> player, string name)
{
    int index = -1;
    int start = 0;
    int end = player.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (player[mid].name.compare(name) == 0)
        {
            index = mid;
            break;
        }
        else if (player[mid].name.compare(name) < 0)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else if (player[mid].name.compare(name) > 0)
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }

    return index;
}

void swap(vector<string> &answer, int target1, int target2)
{
    target1--;
    target2--;
    string temp = answer[target1];
    answer[target1] = answer[target2];
    answer[target2] = temp;

    return;
}

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer = players;
    vector<Player> player(players.size());
    int target1_index;
    int target2_index;

    for (int i = 0; i < players.size(); i++)
    {
        player[i].name = players[i];
        player[i].rank = i + 1;
    }

    MergeSort(player, 0, player.size() - 1);
    for (int i = 0; i < players.size(); i++)
    {
        cout << player[i].name << " : " << player[i].rank << endl;
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl << "----------------------------------" << endl;

    for (int i = 0; i < callings.size(); i++)
    {
        target1_index = SearchPlayerIndex(player, callings[i]);
        target2_index = SearchPlayerIndex(player, answer[player[target1_index].rank - 2]);
        swap(answer, player[target1_index].rank, player[target2_index].rank);
        player[target1_index].rank--;
        player[target2_index].rank++;
        for (int j = 0; j < players.size(); j++)
        {
            cout << player[j].name << " : " << player[j].rank<<endl;
        }
        for (int j = 0; j < answer.size(); j++)
        {
            cout<<answer[j]  << " ";
        }
        cout << endl << "------------------------------------" << endl;
       
    }
    for (int i = 0; i < answer.size(); i++)
    {
       cout<< i + 1 << "µî : " << answer[i]<<endl;
    }


    return answer;
}

int main(void)
{
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector <string> callings = {"kai", "kai", "mine", "mine"};

    solution(players, callings);


}