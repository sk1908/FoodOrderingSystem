#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <unistd.h>
#include <windows.h>

using namespace std;

class java
{
private:
    int total;
    string id;

    struct item
    {
        string name, ID;
        int price;
    } item[100];

public:
    java()
    {
        total = 0;
    }
    void choice();
    void perData();
    void show();
    void update();
    void search();
    void del();
};
void java::choice()
{
    char ch;

    while (1)
    {
        cout << "\t\t----------------------------------------------------------------\n";
        cout << "\t\t----------------------------------------------------------------\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \t\tOwner portal  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 1> Add new item \t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 2> View items in shop  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 3> update existing items \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 4> Check the details of an existing items \t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 5> Remove existing items  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 6> Exit  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t----------------------------------------------------------------\n";
        cout << "\t\t----------------------------------------------------------------\n";
        ch = getch();
        system("CLS");

        switch (ch)
        {

        case '1':
            java::perData();
            break;

        case '2':
            if (total == 0)
            {
                cout << "No data is entered" << endl;
            }
            else
            {
                java::show();
            }
            break;

        case '3':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                java::update();
            break;

        case '4':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                java::search();
            break;

        case '5':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                java::del();
            break;

        case '6':
            exit(0);
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}

void java::perData()
{
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \tEnter data of item  \t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Enter name  \t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3-->";
    cin >> item[total].name;
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Enter ID  \t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3-->";
    cin >> item[total].ID;
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Enter price  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3-->";
    cin >> item[total].price;
    total++;
}

void java::show()
{
    for (int i = 0; i < total; i++)
    {
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \tData of item  \t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Name:" << item[i].name << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 ID:" << item[i].ID << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Price:" << item[i].price << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t****************************************************************\n";
    }
}

void java::update()
{
    string id;
    int i;
    bool flag = false;
    cout << "\t\tEnter the ID of the item you want to update: ";
    cin >> id;

    for (i = 0; i < total; i++)
    {
        if (item[i].ID == id)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \tcurrent Data of item  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Name:" << item[i].name << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 ID:" << item[i].ID << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Price:" << item[i].price << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t****************************************************************\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \tEnter updated data of item  \t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Enter name  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3-->";
        cin >> item[i].name;
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Enter ID  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3-->";
        cin >> item[i].ID;
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Enter price  \t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3-->";
        cin >> item[i].price;
        cout << "\n\t\tData updated successfully\n";
    }
    else
    {
        cout << "\t\tItem with ID " << id << " not found\n";
    }
}

void java::search()
{
    cout << "Enter id of item whose data you want to search" << endl;
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (id == item[i].ID)
        {
            cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Name:" << item[i].name << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
            cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 ID:" << item[i].ID << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
            cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 Price:" << item[i].price << "  \t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
            cout << "\t\t****************************************************************\n";
            break;
        }
        if (i == total - 1)
        {
            cout << "No such record found" << endl;
        }
    }
}

void java::del()
{
    char ch;
    cout << "Press 1 to remove specific record" << endl;
    cout << "Press 2 to remove full record" << endl;
    ch = getch();

    switch (ch)
    {

    case '1':
        cout << "Enter id of item whose data you want to remove" << endl;
        cin >> id;
        for (int i = 0; i < total; i++)
        {
            if (id == item[i].ID)
            {
                for (int j = i; j < total; j++)
                {
                    item[j].name = item[j + 1].name;
                    item[j].ID = item[j + 1].ID;
                    item[j].price = item[j + 1].price;
                    total--;
                    cout << "Your required data is deleted" << endl;
                    break;
                }
            }
            if (i = total - 1)
            {
                cout << "No such record found" << endl;
            }
        }
        break;

    case '2':
        total = 0;
        cout << "All records are deleted" << endl;
        break;

    default:
        cout << "Invalid Input" << endl;
        break;
    }
}

class one
{

public:
    void menu1();
};
void one::menu1(){
    cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB\t  ================== WELCOME TO FOOD ORDERING SYSTEM ==================\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB\t  =========================ENTER THE SHOP No===========================\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB\t  [1] YURISH\t\t[2] EMO PIZZA\t\t[3] SUBWAY              \t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB\t  [4] BLISS\t\t[5] CAKE CASTLE\t\t[6] BUTTY'S             \t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB\t  [7] ANDHRA TIFFINS\t[8] AMUL PARLOUR\t[9] LATHA SUPER MARKET  \t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB\t  =====================================================================\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
}
class two : public one{
protected:
    int shop, ch, www, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s = 0;
    string y, ye;
public:
    void menu2(){
    a:
    b:
    c:
        cout << "\n\n\tSELECT YOUR DESIRED SHOP (one SHOP at a time): ";
        cin >> ch;
        cout << "\n\n\tDO YOU WANT TO CHANGE YOUR DECISION (y/n) :";
        cin >> ye;
        if (ye == "y" || ye == "Y"){
            goto b;
        }
        else{
            if (ch == 1){
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================== please select the items from the menu ======================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Apple juice(Rs.40) \t[2] Mango juice(Rs.45) \t\t[3] Lemon juice(Rs.35)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Watermelon juice Rs.52)\t[5] Mixed Fruits(Rs.55) \t[6] Coconut water(Rs.43) \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Kitkat Shake (Rs.60)\t[8] Chocolate Shake(Rs.50) \t[9] Oreo Shake (Rs.48)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================================================================================= \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int juice, order, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, s1 = 0;
                string y1, ye1;
                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a1:
            b1:
            c1:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye1;

                if (ye1 == "y" || ye1 == "Y")
                {
                    goto b1;
                }
                else
                {
                    switch (order)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        a1 = 40;
                        s1 = s1 + a1 * juice;
                        write << "you ordered Apple juice :40";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Apple juice" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        b1 = 45;
                        s1 = s1 + b1 * juice;
                        write << "you ordered Mango juice :45";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Mango juice" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        c1 = 35;
                        s1 = s1 + c1 * juice;
                        write << "you ordered Lemon juice :35";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Lemon juice" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        d1 = 52;
                        s1 = s1 + d1 * juice;
                        write << "you ordered Watermelon juice :52";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Watermelon juice" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        e1 = 55;
                        s1 = s1 + e1 * juice;
                        write << "you ordered Mixed fruits :55";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Mixed fruits" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        f1 = 43;
                        s1 = s1 + f1 * juice;
                        write << "you ordered Coconut water :43";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Coconut water" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        g1 = 60;
                        s1 = s1 + g1 * juice;
                        write << "you ordered Kitkat Shake :60";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Kitkat Shake" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        h1 = 50;
                        s1 = s1 + h1 * juice;
                        write << "you ordered Chocolate Shake:50";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chocolate Shake" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> juice;

                        i1 = 48;
                        s1 = s1 + i1 * juice;
                        write << "you ordered Oreo Shake :48";
                        write << "\n";
                        write << "Quantity:" << juice;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Oreo Shake" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c1;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y1;
                    if (y1 == "yes" || y1 == "YES")
                    {
                        goto a1;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a1 = 1; a1 < 8; a1++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  rishit" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s1 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s1;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }

            else if (ch == 2)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================== please select the items from the menu ======================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Veggie Supreme(Rs.480)    [2] Exotica Pizza(Rs.440)   [3] Chicken Sizzler(Rs.580)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Chrispy Chicken (Rs.520)  [5] Spaghetti (Rs.350)      [6] Country Feast (Rs.400)    \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Tetrazzini (Rs.420)       [8] Double Cheese (Rs.540)  [9] Makizushi (Rs.548)        \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================================================================================= \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int pizza, order1, a2, b2, c2, d2, e2, f2, g2, h2, i2, s2 = 0;
                string y2, ye2;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a2:
            b2:
            c2:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order1;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye2;

                if (ye2 == "y" || ye2 == "Y")
                {
                    goto b2;
                }
                else
                {
                    switch (order1)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        a2 = 480;
                        s2 = s2 + a2 * pizza;
                        write << "you ordered Veggie Supreme :480";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Veggie Supreme" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        b2 = 440;
                        s2 = s2 + b2 * pizza;
                        write << "you ordered Exotica Pizza :440";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Exotica Pizza" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        c2 = 580;
                        s2 = s2 + c2 * pizza;
                        write << "you ordered Chicken Sizzler :580";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Sizzler" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        d2 = 520;
                        s2 = s2 + d2 * pizza;
                        write << "you ordered Crispy Chicken :520";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Crispy Chicken" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        e2 = 350;
                        s2 = s2 + e2 * pizza;
                        write << "you ordered Spaghetti :350";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Spaghetti" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        f2 = 400;
                        s2 = s2 + f2 * pizza;
                        write << "you ordered Country Feast :400";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Country Feast" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        g2 = 420;
                        s2 = s2 + g2 * pizza;
                        write << "you ordered Tetrazzini :420";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Tetrazzini" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        h2 = 540;
                        s2 = s2 + h2 * pizza;
                        write << "you ordered Double Cheese:540";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Double Cheese" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> pizza;

                        i2 = 548;
                        s2 = s2 + i2 * pizza;
                        write << "you ordered Makizushi :548";
                        write << "\n";
                        write << "Quantity:" << pizza;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Makizushi" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c2;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y2;
                    if (y2 == "yes" || y2 == "YES")
                    {
                        goto a2;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a2 = 1; a2 < 8; a2++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  karthik" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s2 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s2;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }

            else if (ch == 3)
            {

                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================== please select the items from the menu ======================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Aloo Patty(Rs.160)        [2] Paneer Tikka(Rs.170)   [3] Chicken Tikka(Rs.175)      \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Chicken Tandoori(Rs.180)  [5] Turkey Breast(Rs.195)  [6] Chicken Tariyaki(Rs.200)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Veggie Delight(Rs.140)    [8] Tuna(Rs.210)           [9] Veggie Patty(Rs.148)       \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================================================================================= \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int wrap, order3, a3, b3, c3, d3, e3, f3, g3, h3, i3, s3 = 0;
                string y3, ye3;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a3:
            b3:
            c3:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order3;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye3;

                if (ye3 == "y" || ye3 == "Y")
                {
                    goto b3;
                }
                else
                {
                    switch (order3)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        a3 = 160;
                        s3 = s3 + a3 * wrap;
                        write << "you ordered Aloo Patty :160";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Aloo Patty" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        b3 = 170;
                        s3 = s3 + b3 * wrap;
                        write << "you ordered Paneer Tikka :170";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer Tikka" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        c3 = 175;
                        s3 = s3 + c3 * wrap;
                        write << "you ordered Chicken Tikka :175";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Tikka" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        d3 = 180;
                        s3 = s3 + d3 * wrap;
                        write << "you ordered Chicken Tandoori:180";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Tandoori" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        e3 = 195;
                        s3 = s3 + e3 * wrap;
                        write << "you ordered Turkey Breast :195";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered turkey Breast" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        f3 = 200;
                        s3 = s3 + f3 * wrap;
                        write << "you ordered Chicken Tariyaki :200";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Tariyaki" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        g3 = 140;
                        s3 = s3 + g3 * wrap;
                        write << "you ordered Country Delight :140";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Country Delight" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        h3 = 210;
                        s3 = s3 + h3 * wrap;
                        write << "you ordered Tuna:210";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Tuna" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> wrap;

                        i3 = 148;
                        s3 = s3 + i3 * wrap;
                        write << "you ordered veg Patty :148";
                        write << "\n";
                        write << "Quantity:" << wrap;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Veg Patty" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c3;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y3;
                    if (y3 == "yes" || y3 == "YES")
                    {
                        goto a3;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a3 = 1; a3 < 8; a3++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  neeraj" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s3 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s3;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else if (ch == 4)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ============================== please select the items from the menu ============================ \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Chicken Dum Biriyani(Rs.120) [2] Chicken Lollipop Biriyani(Rs.120) [3] Veg Biriyani(Rs.70)    \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Paneer Biriyani(Rs.90)       [5] Chicken noodles(Rs.80)            [6] Paneer noodles(Rs.80)  \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Chicken 65(Rs.90)            [8] Gobi 65 (Rs.80)                   [9] Paneer 65(Rs.80)       \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ================================================================================================= \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";

                int bryn, order4, a4, b4, c4, d4, e4, f4, g4, h4, i4, s4 = 0;
                string y4, ye4;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a4:
            b4:
            c4:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order4;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye4;

                if (ye4 == "y" || ye4 == "Y")
                {
                    goto b4;
                }
                else
                {
                    switch (order4)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        a4 = 120;
                        s4 = s4 + a4 * bryn;
                        write << "you ordered Chicken Dum Biriyani :120";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Dum Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        b4 = 120;
                        s4 = s4 + b4 * bryn;
                        write << "you ordered Chicken Lollipop Biriyani :120";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Lollipop Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        c4 = 70;
                        s4 = s4 + c4 * bryn;
                        write << "you ordered Veg Biriyani :70";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Veg Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        d4 = 90;
                        s4 = s4 + d4 * bryn;
                        write << "you ordered Paneer Biriyani:90";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        e4 = 80;
                        s4 = s4 + e4 * bryn;
                        write << "you ordered Chicken noodles :80";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken noodles" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        f4 = 80;
                        s4 = s4 + f4 * bryn;
                        write << "you ordered Paneer noodles :80";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer noodles" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        g4 = 90;
                        s4 = s4 + g4 * bryn;
                        write << "you ordered Chicken 65 :90";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken 65" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        h4 = 80;
                        s4 = s4 + h4 * bryn;
                        write << "you ordered Gobi 65:80";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Gobi 65" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> bryn;

                        i4 = 80;
                        s4 = s4 + i4 * bryn;
                        write << "you ordered Paneer 65 :80";
                        write << "\n";
                        write << "Quantity:" << bryn;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer 65" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c4;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y4;
                    if (y4 == "yes" || y4 == "YES")
                    {
                        goto a4;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a4 = 1; a4 < 8; a4++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  neeraj" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s4 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s4;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else if (ch == 5)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ================================= please select the items from the menu =============================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Veg Puff(Rs.15)                [2] Chicken Puff(Rs.25)              [3] Black Forest PastryRs.55)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Cup Cake(Rs.55)                [5] Premium Red Velvet Pastry(Rs.75) [6] Rainbow Roll Pastry(Rs.50)  \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Brownie with ice cream(Rs.110) [8] White Forest Pastry(Rs.60)       [9] Choco Mousse Cup (Rs.50)    \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================================================================================================= \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";

                int ckcl, order5, a5, b5, c5, d5, e5, f5, g5, h5, i5, s5 = 0;
                string y5, ye5;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a5:
            b5:
            c5:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order5;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye5;

                if (ye5 == "y" || ye5 == "Y")
                {
                    goto b5;
                }
                else
                {
                    switch (order5)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        a5 = 15;
                        s5 = s5 + a5 * ckcl;
                        write << "you ordered Veg Puff :15";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Veg Puff" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        b5 = 25;
                        s5 = s5 + b5 * ckcl;
                        write << "you ordered Chicken Puff :25";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Puff" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        c5 = 55;
                        s5 = s5 + c5 * ckcl;
                        write << "you ordered Black Forest Pastry :55";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Black Forest Pastry" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        d5 = 55;
                        s5 = s5 + d5 * ckcl;
                        write << "you ordered Cup Cake:55";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Cup Cake" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        e5 = 75;
                        s5 = s5 + e5 * ckcl;
                        write << "you ordered Preemium Red Velvet Pastry :75";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Preemium Red Velvet Pastry" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        f5 = 50;
                        s5 = s5 + f5 * ckcl;
                        write << "you ordered Rainbow Roll Pastry :50";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Rainbow Roll Pastry" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        g5 = 110;
                        s5 = s5 + g5 * ckcl;
                        write << "you ordered Brownie with ice cream :110";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Brownie with ice cream" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        h5 = 60;
                        s5 = s5 + h5 * ckcl;
                        write << "you ordered White Forest Pastry:60";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered White Forest Pastry" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ckcl;

                        i5 = 50;
                        s5 = s5 + i5 * ckcl;
                        write << "you ordered Choco Mousse Cup :50";
                        write << "\n";
                        write << "Quantity:" << ckcl;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Choco Mousse Cup" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c5;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y5;
                    if (y5 == "yes" || y5 == "YES")
                    {
                        goto a5;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a5 = 1; a5 < 8; a5++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  Aniket" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s5 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s5;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else if (ch == 6)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ============================ please select the items from the menu ========================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Chicken Biriyani(Rs.100) [2] Chicken Lollipop Biriyani(Rs.130) [3] Veg Biriyani (Rs.80)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Paneer Biriyani(Rs.90)   [5] Chicken noodles(Rs.90)            [6] Paneer noodles(Rs.80)  \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Chicken Roll (Rs.60)     [8] Shawarma roll (Rs.90)             [9] Paneer roll (Rs.60)    \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ============================================================================================= \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int btt, order6, a6, b6, c6, d6, e6, f6, g6, h6, i6, s6 = 0;
                string y6, ye6;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a6:
            b6:
            c6:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order6;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye6;

                if (ye6 == "y" || ye6 == "Y")
                {
                    goto b6;
                }
                else
                {
                    switch (order6)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        a6 = 100;
                        s6 = s6 + a6 * btt;
                        write << "you ordered Chicken Biriyani :100";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        b6 = 130;
                        s6 = s6 + b6 * btt;
                        write << "you ordered Chicken Lollipop Biriyani :130";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Lollipop Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        c6 = 80;
                        s6 = s6 + c6 * btt;
                        write << "you ordered Veg Biriyani :80";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Veg Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        d6 = 90;
                        s6 = s6 + d6 * btt;
                        write << "you ordered Paneer Biriyani:90";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer Biriyani" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        e6 = 90;
                        s6 = s6 + e6 * btt;
                        write << "you ordered Chicken noodles :90";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken noodles" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        f6 = 80;
                        s6 = s6 + f6 * btt;
                        write << "you ordered Paneer noodles :80";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer noodles" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        g6 = 60;
                        s6 = s6 + g6 * btt;
                        write << "you ordered Chicken Roll :60";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Chicken Roll" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        h6 = 90;
                        s6 = s6 + h6 * btt;
                        write << "you ordered Shawarma roll:90";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Shawarma roll" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> btt;

                        i6 = 60;
                        s6 = s6 + i6 * btt;
                        write << "you ordered Paneer roll :60";
                        write << "\n";
                        write << "Quantity:" << btt;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Paneer roll" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c6;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y6;
                    if (y6 == "yes" || y6 == "YES")
                    {
                        goto a6;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a6 = 1; a6 < 8; a6++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  Karthik" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s6 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s6;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else if (ch == 7)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ======================= please select the items from the menu ===================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Plain Dosa(Rs.30)    [2] Karam Dosa(Rs.40)            [3] Egg Dosa(Rs.40)       \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Ghee Dosa(Rs.50)     [5] Special Chicken Dosa(Rs.60)  [6] Onion Uttapam(Rs.40)  \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Mirchi Bajji(Rs.30)  [8] Egg Bajji(Rs.30)             [9] Onion Bajji(Rs.30)    \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB =================================================================================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int ant, order7, a7, b7, c7, d7, e7, f7, g7, h7, i7, s7 = 0;
                string y7, ye7;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a7:
            b7:
            c7:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order7;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye7;

                if (ye7 == "y" || ye7 == "Y")
                {
                    goto b7;
                }
                else
                {
                    switch (order7)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        a7 = 30;
                        s7 = s7 + a7 * ant;
                        write << "you ordered Plain Dosa :30";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Plain Dosa" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        b7 = 40;
                        s7 = s7 + b7 * ant;
                        write << "you ordered Karam Dosa :40";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Karam Dosa" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        c7 = 40;
                        s7 = s7 + c7 * ant;
                        write << "you ordered Egg Dosa :40";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Egg Dosa" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        d7 = 50;
                        s7 = s7 + d7 * ant;
                        write << "you ordered Ghee Dosa:50";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Ghee Dosa" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        e7 = 60;
                        s7 = s7 + e7 * ant;
                        write << "you ordered Special Chicken Dosa :60";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Special Chicken Dosa" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        f7 = 40;
                        s7 = s7 + f7 * ant;
                        write << "you ordered Onion Uttapam :40";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Onion Uttapam" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        g7 = 30;
                        s7 = s7 + g7 * ant;
                        write << "you ordered Mirchi Bajji :30";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Mirchi Bajji" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        h7 = 30;
                        s7 = s7 + h7 * ant;
                        write << "you ordered Egg Bajji:30";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Egg Bajji" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> ant;

                        i7 = 30;
                        s7 = s7 + i7 * ant;
                        write << "you ordered Onion Bajji :30";
                        write << "\n";
                        write << "Quantity:" << ant;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Onion Bajji" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c7;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y7;
                    if (y7 == "yes" || y7 == "YES")
                    {
                        goto a7;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a7 = 1; a7 < 8; a7++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  neeraj" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s7 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s7;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else if (ch == 8)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ================================ please select the items from the menu ============================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Coffee(Rs.15)             [2] Tea(Rs.15)                   [3] Lemon tea(Rs.10)                   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Boost(Rs.20)              [5] Badam Milk(Rs.20)            [6] Cookies and Cream Icecream(Rs.50)  \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Chocochip IceCream(Rs.40) [8] Afgan Almond IceCream(Rs.60) [9] Pudding Cake(Rs.25)                \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ===================================================================================================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int amp, order8, a8, b8, c8, d8, e8, f8, g8, h8, i8, s8 = 0;
                string y8, ye8;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a8:
            b8:
            c8:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order8;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye8;

                if (ye8 == "y" || ye8 == "Y")
                {
                    goto b8;
                }
                else
                {
                    switch (order8)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        a8 = 15;
                        s8 = s8 + a8 * amp;
                        write << "you ordered Coffee :15";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Coffee" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        b8 = 15;
                        s8 = s8 + b8 * amp;
                        write << "you ordered Tea :15";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Tea" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        c8 = 10;
                        s8 = s8 + c8 * amp;
                        write << "you ordered Lemon tea :10";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Lemon tea" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        d8 = 20;
                        s8 = s8 + d8 * amp;
                        write << "you ordered Boost:20";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Boost" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        e8 = 20;
                        s8 = s8 + e8 * amp;
                        write << "you ordered Badam Milk :20";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Badam Milk" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        f8 = 50;
                        s8 = s8 + f8 * amp;
                        write << "you ordered Cookies and Cream Ice cream :50";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Cookies and Cream Ice cream" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        g8 = 40;
                        s8 = s8 + g8 * amp;
                        write << "you ordered Choco chip Ice Cream :40";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Choco chip Ice Cream" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        h8 = 60;
                        s8 = s8 + h8 * amp;
                        write << "you ordered Afgan Almond Ice Cream:60";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Afgan Almond Ice Cream" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> amp;

                        i8 = 25;
                        s8 = s8 + i8 * amp;
                        write << "you ordered Pudding Cake :25";
                        write << "\n";
                        write << "Quantity:" << amp;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Pudding Cake" << endl
                             << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c8;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y8;
                    if (y8 == "yes" || y8 == "YES")
                    {
                        goto a8;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a8 = 1; a8 < 8; a8++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  hehehe" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s8 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s8;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else if (ch == 9)
            {
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB ==================== please select the items from the menu ==================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [1] Pepsi(Rs.20)            [2] Milk Biki's(Rs.10)      [3] Lays (Rs.20)        \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [4] Britannia cake(Rs.20)   [5] Max Protein(Rs.150)     [6] Munch Max (Rs.20)   \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB [7] Diary Milk Silk(Rs.50)  [8] Oreo ice cream (Rs.70)  [9] Orbit (Rs.5)        \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                cout << "\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB =============================================================================== \xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
                int lsm, order9, a9, b9, c9, d9, e9, f9, g9, h9, i9, s9 = 0;
                string y9, ye9;

                ofstream write;
                write.open("order.text");
                if (!write)
                {
                    cout << "file can not open" << endl;
                    exit(-1);
                }

            a9:
            b9:
            c9:
                cout << "\n\n\t ENTER YOUR ORDER (one ORDER at a time):";
                cin >> order9;

                cout << "\n\n\t Do you want to change your order (y/n):";

                cin >> ye9;

                if (ye9 == "y" || ye9 == "Y")
                {
                    goto b9;
                }
                else
                {
                    switch (order9)
                    {
                    case 1:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        a9 = 20;
                        s9 = s9 + a9 * lsm;
                        write << "you ordered Pepsi :20";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Pepsi" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 2:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        b9 = 10;
                        s9 = s9 + b9 * lsm;
                        write << "you ordered Milk Biki's :10";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Milk Biki's" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 3:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        c9 = 20;
                        s9 = s9 + c9 * lsm;
                        write << "you ordered Lays :20";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Lays" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 4:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        d9 = 20;
                        s9 = s9 + d9 * lsm;
                        write << "you ordered Britannia cake:20";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Britannia cake" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 5:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        e9 = 150;
                        s9 = s9 + e9 * lsm;
                        write << "you ordered Max Protein :150";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Max Protein" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 6:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        f9 = 20;
                        s9 = s9 + f9 * lsm;
                        write << "you ordered Munch Max :20";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Munch Max" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 7:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        g9 = 50;
                        s9 = s9 + g9 * lsm;
                        write << "you ordered Diary Milk Silk :50";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Choco chip Ice Cream" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 8:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        h9 = 70;
                        s9 = s9 + h9 * lsm;
                        write << "you ordered Oreo ice cream:70";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Oreo ice cream" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 9:
                        cout << "\n\n\t Enter the Quantity:";
                        cin >> lsm;

                        i9 = 5;
                        s9 = s9 + i9 * lsm;
                        write << "you ordered Orbit :5";
                        write << "\n";
                        write << "Quantity:" << lsm;
                        write << "\n";
                        cout << "\n\n\n\t You Ordered Orbit" << endl;
                        cout << "\t your order successfully saved" << endl;
                        break;

                    case 10:
                        cout << "\n\t\t\t\t Brought To You By RANK E1 peeps";
                        exit(0);
                        break;

                    default:
                        cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                        goto c9;
                        break;
                    }
                    cout << "\n\t Do You Want Another Order(yes/no):";
                    cin >> y9;
                    if (y9 == "yes" || y9 == "YES")
                    {
                        goto a9;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
                        for (int a9 = 1; a9 < 8; a9++) // Change 'a<?' to how many * you want
                        {
                            Sleep(500);
                            cout << "...";
                        }
                        cout << "\n\t\t\t\t";
                        system("PAUSE");
                    }
                    system("cls");
                    cout << "\n\t\t\t\t ================================================" << endl;
                    cout << "\t\t\t\t|               Food Ordering System             |" << endl;
                    cout << "\t\t\t\t ================================================" << endl;
                    cout << endl;
                    cout << endl;

                    cout << "\t\t\t\t  Bill No : CP51           Order : NB1353" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t  Cashier :  hehehe" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t    YOUR TOTAL BILL IS Rs." << s9 << endl;
                    write << "\t\t\t\t ";
                    write << "\t\t\t\tTOTAL BILL IS : " << s9;
                    cout << "\n\t\t\t\t ================================================" << endl;

                    write.close();
                }
            }
            else
            {
                cout << "\n\n\t\t\t\tYOU ENTERED WRONG KEY !!!" << endl;
                goto c;
            }
            cout << "\n\t Do You Want to visit Another shop(yes/no):";
            cin >> y;
            if (y == "yes" || y == "YES")
            {
                system("CLS");
                menu1();
                goto a;
            }
            else
            {
                cout << "\n\t\t\t\tTHANK YOU FOR YOUR visiting java ";
                for (int a = 1; a < 8; a++) // Change 'a<?' to how many * you want
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\t\t\t\t";
                system("PAUSE");
            }
        }
    }
    void show1()
    {
        menu1();
        menu2();
    }
};

class ownerlogin : public java{
public:
    void login(){
        long userId;
    d:
        cout << "\n\n\n\n\t\t---------------------";
        cout << "\n\t\tEnter Login Id = ";
        cin >> userId;
        cout << "\t\t---------------------";
        if (userId != 12345){
            cout << "\n\t\tDon't try to be smart.....Enter correct id\n";
            goto d;
        }
        else
            cout << "\n\n\t\twelcome to java green,\n";
    z:
        string pwd = "abcd"; // password
        string pass = "";        // empty string
        char c;
        cout << "\n\n\t\tPassword = ";
    p:
        c = getch();
        cout << "*"; // for printing * instead for password
        if (c != 13){
            pass = pass + c; // for concatenating the string
            goto p;
        }
        {
            if (pass == pwd){
                cout << "\n\n\t\tAccess Granted. Welcome to our system\n\n\n\t\t";
                system("PAUSE");
                system("CLS");
                choice();
            }
            else{
                cout << "\n\t\tWrong Password\n";
                goto z;
            }
        }
    }
};

class customerlogin : public one, public two
{
public:
    void login()
    {
        long userId; // for user id of administrator

    d:
        // system("cls");
        cout << "\n\n\n\n\t\t---------------------";
        cout << "\n\t\tEnter Login Id = ";
        cin >> userId;
        cout << "\t\t---------------------";
        if (userId != 67890)
        {
            cout << "\n\t\tDon't try to be smart.....Enter correct id\n";
            goto d;
        }
        else
            cout << "\n\n\t\twelcome to java green,\n";
    z:
        string pwd = "abcd"; // password
        string pass = "";         // empty string
        char c;
        cout << "\n\n\t\tPassword = ";
    p:
        c = getch();
        cout << "*"; // for printing * instead for password
        if (c != 13)
        {
            pass = pass + c; // for concatenating the string
            goto p;
        }

        {
            if (pass == pwd)
            {
                cout << "\n\n\t\tAccess Granted. Welcome to our system\n\n\n\t\t";
                system("PAUSE");
                system("CLS");
                show1();
            }
            else
            {
                cout << "\n\t\tWrong Password\n";
                goto z;
            }
        }
    }
};

int main()
{
    int x, xx;
    customerlogin ob;
    ownerlogin b;
xx:
    cout << "\t\t----------------------------------------------------------------\n";
    cout << "\t\t----------------------------------------------------------------\n";
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \t\t ONLINE JAVA  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 > Press 1 for Owner LOgin  \t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 > Press 2 for Customer login \t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 > Press 3 for Exit \t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
    cout << "\t\t----------------------------------------------------------------\n";
    cout << "\t\t----------------------------------------------------------------\n\t\t-->";
    cin >> x;
    if (x == 1)
    {
        b.login();
    }
    else if (x == 2)
    {
        ob.login();
    }
    else if (x == 3)
    {
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 > Thank you for visiting Java Online \t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n";
        cout << "\t\t----------------------------------------------------------------\n";
        cout << "\t\t----------------------------------------------------------------\n\n\n\n";
        return 0;
    }
    else
    {
        cout << "\t\t\xB3\xB3\xDB\xDB\xDB\xDB\xDB\xDB \xB10 > wrong input \t\t\xDB\xDB\xDB\xDB\xDB\xDB\xB3\xB3\n\n";
        goto xx;
    }
    getch();
    return 0;
}
