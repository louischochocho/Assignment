#include <iostream>
#include <cstdlib>
using namespace std;

class Dice
{
public:
    int cnt;
    int *num;

    void setCnt(int cnt)
    {
        this->cnt = cnt;
    }
    void setDice()
    {
        num = new int[cnt];
    }
    Dice()
    {
        setDice();
    }

    void setItem(int *num)
    {
        this->num = num;
    }

    void setItem()
    {
        for(int i=0; i<cnt; i++)
        {
            int temp;
            cin>>temp;
            num[i] = temp;
        }
    }

    int getItem()
    {
        return num[rand()%cnt];
    }
};

class fourDice :public Dice
{
public:
    fourDice()
    {
        Dice::setCnt(4);
        Dice::setDice();
    }

    void setItem()
    {
        cout<<"네가지 숫자를 입력하세요"<<endl<<":";
        Dice::setItem();
    }
};

class sixDice : public Dice
{
public:
    sixDice()
    {
        Dice::setCnt(6);
        Dice::setDice();
    }

    void setItem()
    {
        cout<<"여섯가지 숫자를 입력하세요"<<endl<<":";
        Dice::setItem();
    }
};



int main()
{
    srand(32323);
    sixDice s = sixDice();
    fourDice f = fourDice();

    s.setItem();
    f.setItem();

    int cnt;
    cout<<"반복 횟수를 설정해 주세요"<<endl<<":";
    cin>>cnt;

    while(cnt--)
    {
        cout<<f.getItem() + s.getItem()<<endl;
    }
    return 0;
}
