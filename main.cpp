#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Node
{
    int num;
    vector<int> susedia;
    Node(int num): num(num){}
};

bool isBiparte(vector<Node> graf) {
    unordered_set<int> skupina1;
    unordered_set<int> skupina2;
    int aktualna_skupina = 0;

    for (const auto& node : graf) {
        if (skupina1.count(node.num)) {
            aktualna_skupina = 1;
        } else if (skupina2.count(node.num)) {
            aktualna_skupina = 2;
        } else {
            skupina1.insert(node.num);
            aktualna_skupina = 1;
        }

        for (const auto& sused : node.susedia) {
            if (aktualna_skupina == 1) {
                if (skupina1.count(sused)) {
                    return false;
                } else if (!skupina2.count(sused)) {
                    skupina2.insert(sused);
                }
            } else if (aktualna_skupina == 2) {
                if (skupina2.count(sused)) {
                    return false;
                } else if (!skupina1.count(sused)) {
                    skupina1.insert(sused);
                }
            }
        }
    }
    return true;
}

int main() {
    int pocet = 0;
    vector<Node> susednosti;

    fstream file("input.txt");
    string line;
    int string_index = 0;
    
    while(getline(file,line)) {
        if(string_index == 0){
            pocet = stoi(line);
            for (int i = 0; i < pocet; i++)
            {
                susednosti.push_back(Node(i));
            }
            string_index++;
        }
        else {
            for (int i = 0; i < line.length(); i++)
            {
                if(line[i] == '1') {
                    susednosti[string_index - 1].susedia.push_back(i);
                }
            }
            string_index++;
        }
    }

    if(isBiparte(susednosti)) {
        cout << "Graf je bipartny";
    } else {
        cout << "Graf nie je bipartny";
    }
    /*
    for (int i = 0; i < pocet; i++)
    {
        cout << susednosti[i].num << ": ";
        for (int j = 0; j < susednosti[i].susedia.size(); j++)
        {
            cout << susednosti[i].susedia[j] << " ";
        }
        cout << '\n';
    }
    */
}