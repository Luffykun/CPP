#include<iostream>
using namespace std;

int length(string a)
{
    int len=0;
    while(a[len]!='\0') len++;
    return len;
}

bool counter(int a[26])
{
    int counter = 0;
    for(int i = 0 ; i < 26 ;i++ )
    {
        if(a[i] > 0)
        counter++;
    }

    if(counter >= 2)
    return false;

    return true;
}

bool check(string a)
{
    if(a[0] == a[length(a) - 1])
    {
        return true;
    }
    return false;
}

bool final_check( int a[26] , int b[26])
{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(a[i] > b[i])
        return false;
    }

    return true;
}

int main()
{
    int n;
    cin>>n;
    string word;
    int occur[26];
    int boolean[26];
    int same[26];
    for(int i=0; i<26; i++) {
    occur[i]=0;
    boolean[i] = 0;
    same[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        cin>>word;
        occur[((int)word[0])-97]++;

        occur[((int)word[length(word)-1])-97]--;
        if(check(word))
        {
        same[word[0] - 97] = 1;
        }
        else
        {
            boolean[((int)word[0])-97]++;
            boolean[((int)word[length(word)-1])-97]++;
        }

    }

    if(!final_check(same , boolean))
    {
    cout<< "Not possible";
    }

    if(!counter(occur))
    {
    cout<< "Not possible";
    }

    int sum=0;
    for(int i=0; i<26; i++)
    sum+=occur[i];
    cout<<sum;
}
