#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int freq;
    char ch;
    Node *left;
    Node *right;
};

Node *buildTree(string &str)
{
    auto cmp = [](Node *a, Node *b)
    {
        return a->freq > b->freq;
    };
    priority_queue<Node *, vector<Node *>, decltype(cmp)> pq(cmp);

    map<char, int> freqMap;
    for (auto ch : str)
        freqMap[ch]++;

    for (auto entry : freqMap)
    {
        Node *temp = new Node();
        temp->ch = entry.first;
        temp->freq = entry.second;
        temp->left = temp->right = NULL;
        pq.push(temp);
    }

    while (pq.size() > 1)
    {
        Node *temp = new Node();
        temp->left = pq.top();
        int freq1 = pq.top()->freq;
        pq.pop();
        temp->right = pq.top();
        int freq2 = pq.top()->freq;
        pq.pop();
        temp->freq = freq1 + freq2;
        temp->ch = '#';

        pq.push(temp);
    }
    return pq.top();
}

void generateCodes(Node *&root, map<char, string> &codeMap, string code)
{
    if (root->left == NULL && root->right == NULL)
    {
        codeMap[root->ch] = code;
        return;
    }
    else
    {
        if (root->left != NULL)
            generateCodes(root->left, codeMap, code + "0");
        if (root->right != NULL)
            generateCodes(root->right, codeMap, code + "1");
    }
}

string encode(string str, map<char, string> &codeMap)
{
    string encodedStr = "";
    for (char ch : str)
        encodedStr += codeMap[ch];
    cout << "\nEncoded message:" << endl;
    cout << encodedStr << endl;
    return encodedStr;
}

void decode(map<char, string> &codeMap, string encodedStr, map<string, char> &decodeMap)
{
    cout << "\nDecoded message:" << endl;
    string currentCode = "";
    for (char ch : encodedStr)
    {
        currentCode += ch;
        if (decodeMap.find(currentCode) != decodeMap.end())
        {
            cout << decodeMap[currentCode];
            currentCode = "";
        }
    }
}

int main()
{
    string inputStr;
    getline(cin, inputStr);

    Node *root = buildTree(inputStr);
    map<char, string> codeMap;
    map<string, char> decodeMap;
    generateCodes(root, codeMap, "");

    cout << "\nCharacter codes:" << endl;
    for (auto entry : codeMap)
    {
        decodeMap[entry.second] = entry.first;
        cout << entry.first << " = " << entry.second << endl;
    }

    string encodedMessage = encode(inputStr, codeMap);
    decode(codeMap, encodedMessage, decodeMap);

    return 0;
}