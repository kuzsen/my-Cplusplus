#include"��ϣ��myhash.h"  

int main()
{
    Elemtype r[12] = { {17,1},{60,2},{29,3},{38,4},{1,5},{2,6},{3,7},{4,8},{5,9},{6,10},{7,11},{8,12} };
    HashTable H;
    int i, p, j;
    KeyType k;
    H.Init_HashTable();
    for (i = 0; i < 11; i++) //����ǰ11����¼  
    {
        j = H.Insert_Hash(r[i]);
        if (j == -1)
            cout << "�������йؼ���Ϊ" << r[i].key << "  " << r[i].ord << "�ļ�¼" << endl;
    }

    cout << "����ϣ��ַ˳�������ϣ��" << endl;
    H.Traverse_HashTable();
    cout << endl;

    cout << "����Ҫ���ҵļ�¼�Ĺؼ��֣�";
    cin >> k;
    j = H.Search_Hash(k, p);
    if (j == 1)
        H.Get_Data(p);
    else
        cout << "�޴˼�¼" << endl;

    j = H.Insert_Hash(r[11]); //�������һ��Ԫ��  
    if (j == 0)
    {
        cout << "����ʧ��" << endl;
        cout << "��Ҫ�ؽ���ϣ��ſ��Բ���" << endl;
        cout << "____�ؽ���ϣ��____" << endl;
        H.Insert_Hash(r[i]); //�ؽ������²���  
    }

    cout << "�����ؽ���Ĺ�ϣ��" << endl;
    H.Traverse_HashTable();
    cout << endl;

    cout << "����Ҫ���ҵļ�¼�Ĺؼ��֣�";
    cin >> k;
    j = H.Search_Hash(k, p);
    if (j == 1)
        H.Get_Data(p);
    else
        cout << "�ü�¼������" << endl;

    cout << "____���ٹ�ϣ��____" << endl;
    H.Destroy_HashTable();

    return 0;
}
