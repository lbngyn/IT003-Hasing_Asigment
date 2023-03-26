#include <bits/stdc++.h>
using namespace std;

int getHash(bitset<100> key, int M)
{
    int index = 0;                           // khoi tao bien luu ket qua cua ham
    for (int i = 0; i < 100; ++i)            // duyet qua tung bit cua key
        index = ((index << 1) | key[i]) % M; // index = index*2 + key[i]
    return index;
}

int main()
{
    int n, q, M; // n la so luong du lieu
                 // q la so luong truy van
                 // M la kich thuoc mang bam
    vector<pair<bitset<100>, int>> hashTable[M];

    for (int i = 0; i < n; ++i)
    {
        string tmp; 
        int value;
        cin >> tmp >> value;
        bitset<100> key(tmp); 
        int index = getHash(key, M);
        hashTable[index].push_back(make_pair(key, value));
    }

    for (int i = 0; i < q; ++i)
    {
        string tmp; 
        cin >> tmp;
        bitset<100> key(tmp);

        int index = getHash(key, M);
        bool wrote = false;
        for (int j = 0; j < hashTable[index].size(); ++j)
        {
            pair<bitset<100>, int> tmp = hashTable[index][j];
            if (tmp.first == key)
            {
                cout << "Value of the key \" " << key << "\""
                     << " is: " << tmp.second << '\n';
                wrote = true;
                break;
            }
        }
        if (!wrote)
            cout << "the key is unvalued! \n";
    }
}
