#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n==1||n==0) return 1;
    else return n*factorial(n-1);
}

//void combin(int n,int m, int* arrayCombis, int arrayNums[], int start = 0, int combinumber = 0)
//{
//    for(int i = start; i < n; i++)
//    {
//        combinumber++;
//        arrayCombis[start + combinumber*m] = arrayNums[start];
//        combin(n-1,m-1,arrayCombis,arrayNums,start+1,index+1);
//    }
//}
void print_combi(int arrayNums[], int len, int memory[], int n, int m, int start = 0, int i=0)
{
    //cout<<start<<endl;
    if(m==0) {for(int i = 0; i<len; i++) {cout<<memory[i];}cout<<endl;}
    for(; i<n; i++)
    {
        memory[start] = arrayNums[i];
        //cout<<start<<" "<<i<<endl;
        print_combi(arrayNums, len, memory, n, m-1, start+1, i+1);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
//    int terms = factorial(n)/(factorial(n-m)*factorial(m));
//    int *combi = new int(terms*m);
    int numbers[n];
    for(int i=0; i<n; i++) numbers[i]=i+1;
    int currcombi[m];
    print_combi(numbers, m, currcombi,n,m);
}
