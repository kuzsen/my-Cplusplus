#pragma once
#include<iostream>  
using namespace std;

typedef int KeyType; //��ؼ�����Ϊ����,��Ҫ�޸�����ʱ��ֻ���޸�����Ϳ���  
const int NULLKEY = 0; //NULLKEY��ʾ��λ����ֵ  
int c = 0; //����ͳ�Ƴ�ͻ����  

struct Elemtype //����Ԫ������  
{
    KeyType key;
    int ord;
};

int hashsize[] = { 11,19,29,37,47 }; //hash������������  
int Hash_length = 0;//hash���  

class HashTable
{
private:
    Elemtype* elem; //����Ԫ������,��̬����  
    int count;// ��ǰ����Ԫ�ظ���  
    int size; //����hash�������Ϊ�ڼ���,hashsize[size]Ϊ��ǰhash����  
public:

    int Init_HashTable() //����һ����hash��  
    {
        int i;
        count = 0;
        size = 0; //��ʼ������Ϊhashsize[0]=11  
        Hash_length = hashsize[0];
        elem = new Elemtype[Hash_length];
        if (!elem)
        {
            cout << "�ڴ�����ʧ��" << endl;
            exit(0);
        }
        for (i = 0; i < Hash_length; i++)
            elem[i].key = NULLKEY;
        return 1;
    }

    void Destroy_HashTable()
    {
        delete[]elem;
        elem = NULL;
        count = 0;
        size = 0;
    }

    unsigned Hash(KeyType k) //hash������һ��(ȡģ��)  
    {
        return k % Hash_length;
    }

    void Collision(int& p, int d) //�����ͻ  
    {
        p = (p + d) % Hash_length; //���ÿ��ŵ�ַ���������̽��  
    }

    bool Search_Hash(KeyType k, int& p) //����  
    {
        //�ڿ��ŵ�ַhash���в��ҹؼ��ֵ���k��Ԫ��  
        //���ҵ���p��ʾ��������,���Ҳ��ɹ�ʱ��pָ����ǿɲ����ַ  
        c = 0;
        p = Hash(k); //��hash��ַ  
        while (elem[p].key != NULLKEY && elem[p].key != k)
        {
            c++;
            if (c < Hash_length)
                Collision(p, c);
            else
                return 0; //��ʾ���Ҳ��ɹ�  
        }
        if (elem[p].key == k)
            return 1;
        else
            return 0;

    }

    int Insert_Hash(Elemtype e) //����  
    {
        //�ڲ��Ҳ��ɹ�������½�k���뵽hash����  
        int p;
        if (Search_Hash(e.key, p))
            return -1; //��ʾ��Ԫ������hash����  
        else if (c < hashsize[size] / 2) //��ͻ����δ�ﵽ����  
        {
            //����e  
            elem[p] = e;
            count++;
            return 1;
        }
        else
            ReCreate_HashTable(); // �ؽ�hash��  
        return 0; //����ʧ��  
    }

    void ReCreate_HashTable() //�ؽ�hash��  
    {
        int i, count2 = count;
        Elemtype* p, * elem2 = new Elemtype[count];
        p = elem2;
        cout << "____�ؽ�hash��_____" << endl;
        for (i = 0; i < Hash_length; i++) //��ԭ��Ԫ���ݴ浽elem2��  
            if (elem[i].key != NULLKEY)
                *p++ = *(elem + i);
        count = 0;
        size++; //hash��������  
        Hash_length = hashsize[size];
        p = new Elemtype[Hash_length];
        if (!p)
        {
            cout << "�ռ�����ʧ��" << endl;
            exit(0);
        }
        elem = p;
        for (i = 0; i < Hash_length; i++)
            elem[i].key = NULLKEY;
        for (p = elem2; p < elem2 + count2; p++) //��ԭ��Ԫ�طŻ��±�  
            Insert_Hash(*p);
    }

    void Traverse_HashTable()
    {
        cout << "��ϣ��ַ0->" << Hash_length - 1 << endl;
        for (int i = 0; i < Hash_length; i++)
            if (elem[i].key != NULLKEY)
                cout << "Ԫ�صĹؼ���ֵ�����ı�־�ֱ��ǣ�" << elem[i].key << "  " << elem[i].ord << endl;

    }

    void Get_Data(int p)
    {
        cout << "Ԫ�صĹؼ���ֵ�����ı�־�ֱ��ǣ�" << elem[p].key << "  " << elem[p].ord << endl;
    }

};
