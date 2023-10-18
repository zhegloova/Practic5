#include <iostream>
using namespace std;


struct tnode {
    double field;           // поле данных
    struct tnode* l;  // левый потомок
    struct tnode* r; // правый потомок
};
struct tnode* addnode(double x, tnode* tree) {
    if (tree == NULL) { // Если дерева нет, то формируем корень
        tree = new tnode; // память под узел
        tree->field = x;   // поле данных
        tree->l = NULL;
        tree->r = NULL; // ветви инициализируем пустотой
    }
    else  if (x < tree->field)   // условие добавление левого потомка
        tree->l = addnode(x, tree->l);
    else    // условие добавление правого потомка
        tree->r = addnode(x, tree->r);
    return(tree);
}
void printTree(tnode* tree, int u) {
    if (tree == NULL) return; //если дерева нет, то выход
    else {
        printTree(tree->l, ++u); //вызов функции печати узлов левого дерева
        for (int i = 0; i < u; ++i) cout << "|";
        cout << tree->field << endl; //вывод узлов дерава
        u--;
    }
    printTree(tree->r, ++u); // вызов функции печати узлов правого дерева
}
void travTree(tnode* tree) { // функция симметричного объода
    if (tree != NULL) { //пока есть дерево
        travTree(tree->l); //вызов функции обхода левого дерава
        cout << tree->field << " "; // вывод узла
        travTree(tree->r); //вызов функции обхода правого дерева
    }
}
void leafSum(tnode* root, double* sum) { //сумма листьев
    if (!root) //если нет дерева, то выход
        return;
    if (!root->l && !root->r) { //если узел - лист
        *sum += root->field; // увеличение суммы
        cout << root->field << " "; //вывод листа
    }

    leafSum(root->l, sum); //вызов функции для левого дерево
    leafSum(root->r, sum); //вызов функции для правого дерева

}


double average(tnode* tree) { //функция для поиска среднего арифм.
    static double sum = 0; //сумма
    static double count = 0; //количество узлов
    if (tree) { //если есть дерево
        average(tree->l); //вызов функции для левого дерева
        sum += tree->field; // увеличение суммы
        count++; //увеличение количества
        average(tree->r); // вызов функции для правого дерева
    }
    return sum / count; //нахождение среднего арифм.
}
int main()
{
    tnode* tree = NULL;
    cout << "Enter 10 nodes" << endl;
    for (int i = 0; i < 10; i++) { //ввод 10 узлов
        double x;
        cin >> x;
        tree = addnode(x, tree);
    }
    int f;
    do { //вызовы функций с помощью меню
        cout << "1 - add new node" << endl;
        cout << "2 - print tree" << endl;
        cout << "3 - traversal tree" << endl;
        cout << "4 - count average value" << endl;
        cout << "5 - count leaf sum" << endl;
        cout << "0 - exit" << endl;
        cin >> f;
        switch (f) {
        case 1: {
            cout << "Enter new node value" << endl;
            double x;
            cin >> x;
            tree = addnode(x, tree);
            break;
        }
        case 2: {
            printTree(tree, 0);
            cout << endl;
            break;
        }
        case 3: {
            travTree(tree);
            cout << endl;
            break;
        }
        case 4: {
            cout << "Average value is: " << average(tree) << endl;
            break;
        }

        case 5: {
            double sum = 0;
            leafSum(tree, &sum);
            cout << "Leaf sum is: " << sum << endl;
            break;
        }

        default:
        {
            cout << "Reenter function number" << endl;
            break;
        }

        }

    } while (f != 0);




}
