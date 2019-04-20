#include <iostream>
#include <conio.h>

using namespace std;


struct node
{
    int info;
    node *l, *r;
};

node *tree = NULL;                      //Объявляем переменную, тип которой структура Дерево


void push(int a, node **t)              //Запись в дерево
{
    if ((*t) == NULL)                   //Если дерева не существует
    {
        (*t) = new node;                //Выделяем память
        (*t)->info = a;                 //Кладем в выделенное место аргумент a
        (*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
        return;                         //Заложили семечко, выходим
    }
       //Дерево есть
        if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
        else push(a, &(*t)->l);         //Иначе кладем его влево
}

void print (node *t, int u)
{
    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
    else
    {
        print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        for (int i=0; i<u; ++i) cout << "  ";
        cout << t->info << endl;            //И показываем элемент
        u--;
    }
    print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
}

int minDepth(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + min(minDepth(root->l), minDepth(root->r));
}

int main ()
{
    int n;                              //Количество элементов
    int s;                              //Число, передаваемое в дерево
    cout << "write number of elements  ";
    cin >> n;                           //Вводим количество элементов

    for (int i=0; i<n; ++i)
    {
        cout << "write element ";
        cin >> s;                       //Считываем элемент за элементом

        push(s, &tree);                 //И каждый кладем в дерево
    }
    cout << "your tree\n";
    print(tree, 0);
    int i = minDepth(tree);
    cout << " min tree depth = " << i;
    cin.ignore().get();
}