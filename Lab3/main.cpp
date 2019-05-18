
#include <iostream>
#include <queue>

using namespace std;

const int n = 6;    //размер матрицы смежности
const int GM[n][n] =    //матрица смежности графа
        {
                {0,1,1,0,0,0},
                {1,0,1,1,0,0},
                {1,1,0,1,1,1},
                {0,1,1,0,1,0},
                {0,0,1,1,0,1},
                {0,0,1,0,1,0}
        };
/*1- 2,3;  2- 1,3,4; 3- 1,2,3,4,5,6; 4- 2,3,5; 5- 3,4,6; 6- 3,5*/

int main()
{
    bool doesExist = false;
    int len[n];         //расстояние от начальной вершины до других
    int start,length;   //стартовая вершина и шаг поиска
    cout << "Start position >> ";
    cin >> start;
    --start;
    cout << "Step >> ";
    cin >> length;
    cout << "Matrix: " << endl;
    for(const auto & i : GM)    //вывод матрицы в консоль
    {
        for(int j : i)
        {
            cout << " " << j;
        }
        cout << endl;
    }
    for(auto &it : len)        //т.к. мы не знаем расстояние, будем считать его за -1
    {
        it = -1;
    }
    len[start] = 0;     //расстояние до начальной вершины
    std::queue<unsigned> q;     //очередь посещения вершин
    q.push(start);

    while(!q.empty())
    {
        unsigned cur = q.front();   //берем текущую позицию
        q.pop();
        //посетить ее соседей, которых ранее не посещали
        for(unsigned i = 0; i < n; i++)
        {
            if((GM[cur][i] == 1) && (len[i] == -1))
            {
                len[i] = len[cur] + 1;  //расстояние до тех соседей, что не посетили, на 1 больше
                q.push(i);  //добавляем соседа в очередь
            }
        }
    }

    cout << endl;
    for(unsigned i = 0; i <= n; i++)    //выводим в консоль номера вершин для которых расстояние совпадает
    {
        if(len[i] == length)
        {
            cout << i + 1 << " ";
            doesExist = true;
        }
    }
    cout << endl;
    if(!doesExist)  //проверка. есть ли хоть 1 вершина
    {
        cout << "Too large step" << endl;
        cout << "There are no vertices for this step" << endl;
    }
    return 0;
}