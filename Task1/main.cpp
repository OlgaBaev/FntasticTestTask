#include <iostream>
#include <map>

using namespace std;

bool ReplaceAlgo(string * src, string * dst)
{
    if(!src || !dst)
        return false;

    map<char, int> letters;
    for(unsigned int i = 0; i < src->size(); i++)
    {
        char c = tolower(src->at(i));
        if(letters.count(c))
            letters[c]++;
        else
            letters[c] = 1;
        //теоретически можно обойтись вместо условия одним лишь оператором letters[c]++,
        //так как ненайденный элемент вставляется со значением по умолчанию,
        //но я не буду полагаться на компилятор и считать, что он действительно инициализирует его нулём
    }

    /*for(map<char, int>::iterator it = letters.begin(); it!= letters.end(); ++it)
    {
        cout <<"[" << it->first << "] = " << it->second << endl;
    }*/

    dst->clear();
    for(unsigned int i = 0; i < src->size(); i++)
    {
        char c = tolower(src->at(i));
        if(letters[c] > 1)
            dst->append(")");
        else
            dst->append("(");
    }

    return true;
}

void TestString(string * src, string * result)
{
    string dst;
    ReplaceAlgo(src, &dst);
    cout << "Test: " << *src << " > " << *result <<
            " ::::: Process: " << dst << " - ";

    if(!dst.compare(*result))
        cout << "PASSED";
    else
        cout << "FAILED";
    cout << "\n";
}

void ProcessString(string * src)
{
    string dst;
    ReplaceAlgo(src, &dst);
    cout << "Input: " << *src <<
            " ::::: Output: " << dst << endl;
}

void Test()
{
    string a1, a2;
    a1.clear(); a2.clear();
    a1.assign("din"); a2.assign("((("); TestString(&a1, &a2);
    a1.assign("recede"); a2.assign("()()()"); TestString(&a1, &a2);
    a1.assign("Success"); a2.assign(")())())"); TestString(&a1, &a2);
    a1.assign("(( @"); a2.assign("))(("); TestString(&a1, &a2);

}



int main()
{
    Test();

    string input;
    input.clear();

    cout << "Enter strings to process. Enter -q to exit" << endl;
    cin >> input;
    while(input.compare("-q"))
    {
        ProcessString(&input);
        cin >> input;

    }

    return 0;
}
